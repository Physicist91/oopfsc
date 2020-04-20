






//############################################################################
/*
 * Public, Protected, Private Inheritance 
 */

class B { 
};
class D_priv : private   B { };
class D_prot : protected B { };
class D_pub : public    B { };


/*
They specifies different access control from the derived class to the base class.

Access Control:
1. None of the derived classes can access anything that is private in B. 
2. D_pub inherits public members of B as public and the protected members of B as 
   protected
3. D_priv inherits the public and protected members of B as private. 
4. D_prot inherits the public and protected members of B as protected. 

Casting:
1. Anyone can cast a D_pub* to B*. D_pub is a special kind of B.
2. D_priv's members and friends can cast a D_priv* to B*.
3. D_prot's members, friends, and children can cast a D_prot* to B*.

Note: Only public inheritance indicates a is-a relationship.

*/





/* Detailed Example */

class B { 
   public:
      void f_pub() { cout << "f_pub is called.\n"; }
   protected:
      void f_prot() { cout << "f_prot is called.\n"; }
   private:
      void f_priv() { cout << "f_priv is called.\n"; }
};

class D_pub : public B { 
   public:
      void f() { 
         f_pub();   // OK. D_pub's public function
         f_prot();  // OK. D_pub's protected function
         f_priv();  // Error. B's private function 
      }
};

class D_priv : private   B { 
   public:
   using B::f_pub;
      void f() {
         f_pub();   // OK. D_priv private function
         f_prot();  // OK. D_priv private function
         f_priv();  // Error. B's private function 
      }
};

int main() {
   D_pub D1;
   D1.f_pub();  // OK. f_pub() is D_pub's public function.

   D_priv D2;
   D2.f_pub();  // Error. f_pub() is D_priv's private function.

   B* pB = &D1;  // OK
   pB = &D2;     // Error
   ...
}



// in D_prot, after public, add:  using B::f_pub;   the error goes away.








/*
 * public inheritance: is-a relation, eg., D_pub is-a kind of a B. 
 *
 * private inheritance: similar to has-a relation.
 */
class Ring {
   virtual tremble();
   public:
   void tinkle() {...; tremble(); }
};

/* Composition */
class Dog {
   Ring m_ring;
   public:
   void tinkle() {m_ring.tinkle();}  // call forwarding
};


/* Private Inheritance */
class Dog_Priv : private Ring {
   public:
   using Ring::tinkle;
};

/*
 * composition's advantage: e.g., 2 rings, switchable ring.
 * private inheritance's advantage: more elegant polymorphism.
 *
 * E.g. in class ring, add virtual function: tremble(), which is
 *    used in tinkle().
 */


















//############################################################################
/*
 * Public inheritance => "is-a" relation
 *
 * A Derived class should be able to do everything the base class can do.
 */

class Bird { 
   public:
   void fly();
};

class Penguin : public Bird {};

Penguin p;
p.fly();







// class flyableBird : public bird {};
//   public:
//      void fly();
//penguin p;
//p.fly();



 





class Dog {
   public:
      void bark() { cout << "Whoof, I am just a dog.\n";};
};

class Yellowdog : public Dog{
   public:
      void bark() { cout << "Whoof, I am a yellow dog.\n";};
};

int main() {
   Yellowdog* py = new Yellowdog();
   py->bark(); 
   Dog* pd = py;
   pd->bark(); 
}

OUTPUT:
Whoof, I am a yellow dog.
Whoof, I am just a dog.
/*
 * Never Override Non-virtual Functions
 */







class Dog {
   public:
   void bark(int age) { cout << "I am " << age; }
   virtual void bark(string msg = "just a" ) { 
      cout << "Whoof, I am " << msg << " dog." << endl; }
};

class Yellowdog : public Dog {
   public:
   using Dog::bark;
   virtual void bark(string msg="a yellow" ) { 
      cout << "Whoof, I am " << msg << " dog." << endl; }
};

int main() {
   Yellowdog* py = new Yellowdog();
   py->bark(5); 
}

OUTPUT:
Whoof, I am a yellow dog.
Whoof, I am just a dog.

/*
 * Never redefine default parameter for virtual function
 *   - Default parameters are bound statically;
 *   - Virtual functions are bound dynamically.
 */


/*
 * in class dog, add:
 * virtual void bark(int age) { cout << "I am " << age << " years old"<< endl; }
 * in main(),
 *    py->bark(5);  // Won't compile
 *                  // Can be fixed by adding "using Dog::bark;" in yellow dog
 */















class Dog {
   public:
      virtual void bark() { cout << "I am just a dog.\n";};
      void run();
};

class Yellowdog : public Dog{
   public:
      virtual void barks() { cout << "I am a yellow dog.\n";};
};


// C++ 11 standard:
class Yellowdog : public Dog{
   public:
      virtual void barks() override;       
            // Compile Error: no function to override

      virtual void bark() const override;  
            // Compile Error: no function to override

      void run() override;  // Error
};










/* 
 * Summary of pitfalls:
 * 1. Precise definition of classes;
 * 2. Don't override non-virtual functions;
 * 3. Don't override default parameter values for virtual functions;
 * 4. Force inheritance of shadowed functions.
 * 5. Be careful of typo in function overriding.
 */
















//############################################################################
/*
 *  Polymorphism
 */

// Non-virtual Interface Idiom (NVI)

struct TreeNode {TreeNode *left, *right;};

class Generic_Parser {
   public:
   void parse_preorder(TreeNode* node) {
      if (node) {
         process_node(node);
         parse_preorder(node->left);
         parse_preorder(node->right);
      }
   }
   private:
   virtual void process_node(TreeNode* node) { }
};

class EmployeeChart_Parser : public Generic_Parser {
   private:
   void process_node(TreeNode* node) {
       cout << "Customized process_node() for EmployeeChart.\n";
   }
};
   
int main() {
   ...
   EmployeeChart_Parser ep;
   ep.parse_preorder(root);
   ...
}
// Benefits: clean, elegant, generic code
/*
 * 1. is-a relationship between base class and derived class
 * 2. Base class defines a "generic" algorithm that's used by derived class
 * 3. The "generic" algorithm is customized by the derived class
 */







/*
 * Alternatives for Virtual Function
 */
class A {
   X x;   // dynamically controls what task to be performed.

   /* X could be:
    * 1. Function pointer
    * 2. tr1::function, a generalized function pointer.
    * 3. Strategy class
    */
   ...
};






struct TreeNode {TreeNode *left, *right;};

template <typename T>
class Generic_Parser {
   public:
   void parse_preorder(TreeNode* node) {
       if (node) {
           process_node(node);
           parse_preorder(node->left);
           parse_preorder(node->right);
       }
   }
   void process_node(TreeNode* node) {
       static_cast<T*>(this)->process_node(node);
   }
};

class EmployeeChart_Parser : public Generic_Parser<EmployeeChart_Parser> {
   public:
   void process_node(TreeNode* node) {
       cout << "Customized process_node() for EmployeeChart.\n";
   }
};
   
int main() {
   ...
   EmployeeChart_Parser ep;
   ep.parse_preorder(root);
   ...
}


// Curiously Recurring Template Pattern 
//   (Static Polymorphism, Simulated Polymorphism)


// TMP







//###########################################################################
/*
 * Multiple Inheritance
 *
 *  -- A class is directly derived from more than one base classes.
 *
 *  -- Is it worth the trouble?
 */


//###########################################################################
/*
 * Multiple Inheritance
 */


class InputFile {
   public:
   void read();
};

class OutputFile {
   public:
   void write();
};

class IOFile : public InputFile, public OutputFile {
};

int main() {
   IOFile f;
}


// Notes:
//   void open();
//   f.open();   
//Correction:
//f.Output::open();





class File {            //         File
   public:              //         /  \        -
   string name;         // InputFile  OutputFile
   void open();         //         \  /
};                      //        IOFile

class InputFile : virtual public File {
};                              
                                
class OutputFile : virtual public File {
};                              

class IOFile : public InputFile, public OutputFile {
};  // Diamond shape of hierarchy

int main() {
   IOFile f;
   f.open();   
   //f.InputFile::name = "File1";
   //f.OutputFile::name = "File2";
}

// Compile Error: Ambiguous call to open()
// f.InputFile::name  = "File1";
// f.OutputFile::name = "File2";




class File {     
   public:      
   File(string fname);
};             

class InputFile : virtual public File {
   InputFile(string fname) : File(fname) {}
};                              
                                
class OutputFile : virtual public File {
   OutputFile(string fname) : File(fname) {}
};                              

class IOFile : public InputFile, public OutputFile {
   IOFile(string fname) : OutputFile(fname), InputFile(fname), File(fname) {}
};  

int main() {
   IOFile f;
}







/*
 * Interface Segregation Principle
 * 
 * Split large interfaces into smaller and more specific ones so that clients
 * only need to know about the methods that are of interest to them.
 */


class Engineer {
   public:
   ...; // 40 APIs
};

class Son {
   public:
   ...; // 50 APIs
};

...

class Andy : public Engineer, Son {
   public:
   ...; // 500 APIs
   };



/*
 * Benefits of ISP:
 * 1. Easy-to-use interfaces
 * 2. Static type safety
 */












/*
 *  Pure Abstract Classes 
 *
 *  Abstract Class: A class has one or more pure virtural functions.
 *
 *  Pure Abstract Classes: 
 *  A class containing only pure virtual functions
 *    - no data 
 *    - no concrete functions
 *    - no private protected functions
 */

class OutputFile {
   public:
   void write() = 0;
   void open() = 0;
};









/*
 * Summary:
 * 1. Multiple Inheritance is an important technique, e.g. ISP
 * 2. Derive only from PACs when using Multiple Inheritance.
 */












//###########################################################################
/* 
 * The Duality of Public Inheritance
 *
 *   - Inheritance of Interface  
 *   - Inheritance of Implementation
 */

class Dog {
   public:
      virtual void bark() = 0;
      void run() { cout << "I am running."; }
      virtual void eat() { cout << "I am eating. "; }
   protected:
      void sleep() { cout << " I am sleeping. "; }
};

class Yellowdog : public Dog{
   public:
      virtual void barks() { cout << "I am a yellow dog.\n";}
      void iSleep() { sleep(); }
};











/*
 * Types of Inheritance in C++:
 * 1. Pure virtual public function - inherit interface only.
 * 2. Non-virtual public function - inherit both interface and implementation.
 * 3. Impure virtual public function - inherit interface and default 
 *    implementation
 * 4. Protected function - inherit implementation only
 *
 * As a software designer, it is very important to separate the concepts of 
 * interface and implementation.
 */







/*
 * Interface Inheritance
 *
 * 1. Subtyping
 * 2. Polymorphism
 */
  virtual void bark() = 0;

/*
 * Pitfalls:
 *  -- Be careful of interface bloat.
 *  -- Interfaces do not reveal implementation.
 */











/*
 * Implementation Inheritance 
 *    - Increase code complexity
 *    - Not encouraged
 */
public:
   void run() { cout << "I am running."; }
   virtual void eat() { cout << "I am eating. "; }
protected:
   void sleep() { cout << " I am sleeping. "; }

/*
 * Guidelines for Implementation Inheritance:
 * 1. Do not use inheritance for code reuse, use composition.
 * 2. Minimize the implementation in base classes. Base classes should be thin.
 * 3. Minimize the level of hierarchies in implementation inheritance.
 */









/* 
 * "Inheritance is evil"  ???
 * 
 * "Inheritance is often useful, but more often overused (abused)."
 */










/*
 *  Pure Abstract Class (PAC)
 *
 *  Abstract Class: A class has one or more pure virtual functions.
 *
 *  Pure Abstract Classes: 
 *  A class containing only pure virtual public functions
 *    - no data 
 *    - no concrete functions
 *    - no private or protected functions
 */

class File {
   public:

   /* Open a file with the name of "filename"
    * param filename  C-string name of the file to be opened.
    */
   void open(const char* filename) = 0;

   /* Close the file
    */
   void close() = 0;
};







//############################################################################
/*
 * Code Reuse: Inheritance Vs. Composition
 */

class BaseDog {
   ...
   ... // common activities
};

class BullDog : public BaseDog {
   ... // Call the common activities to perform more tasks.
};

class ShepherdDog : public BaseDog {
   ... // Call the common activities to perform more tasks.
};





// Code Reuse with composition

class ActivityManager {
   ... // common activities
};

class Dog {
   ...
};

class BullDog : public Dog {
   ActivityManager* pActMngr;
   ... // Call the common activities through pActMngr
};

class ShepherdDog : public Dog {
   ActivityManager* pActMngr;
   ... // Call the common activities through pActMngr
};















/*
 * Code reuse: composition is better than inheritance
 *
 * 1. Less code coupling between reused code and reuser of the code 
 *    a. Child class automatically inherits ALL parent class's public members.
 *    b. Child class can access parent's protected members.
 *       - Inheritance breaks encapsulation
 */

/*
 * 2. Dynamic binding
 *    a. Inheritance is bound at compile time
 *    b. Composition can be bound either at compile time or at run time.
 */

class OutdoorActivityManager : public ActivityManager {...}

class IndoorActivityManager : public ActivityManager {...}


/*
 * 3. Flexible code construct
 *
 *    Dog             ActivityManager
 *
 *    BullDog         OutdoorActivityManager
 *    ShepherdDog     IndoorActivityManager
 *    ...             ...
 */

































/*
 * RESERVED
 */

/*
 * "Never use inheritance for code reuse!"
 * 
 * "Inherit interfaces only; never inherit implementation!"
 *
 * "All base classes should be Pure Abstract Classes!"
 */












// Composition Example: Inherit only from pure abstract class:
class ActivityManager {
   void eatBiscuit() { ... }
};

class Dog {
   ...
   virtual void eatBiscuit() = 0;
};

class BullDog : public Dog {
   ActivityManager* pActMngr;
   ...
   void eatBiscuit() { pActMngr->eatBiscuit(); }
};

class ShepherdDog : public Dog {
   ActivityManager* pActMngr;
   ... 
   void eatBiscuit() { pActMngr->eatBiscuit(); }
};







// Inheritance Example: 
class Dog {
   ...
   void eatBiscuit() {... }
};

class BullDog : public Dog {
   ...
};

class ShepherdDog : public Dog {
   ... 
};



// virtual function is another benefit of implementation inheritance.



/*
 * 1. Minimize the implementation in base classes. Base classes should be thin.
 * 2. Minimize the level of hierarchies in implementation inheritance.
 */







/* 
 * "Inheritance is evil"  ???
 * 
 * "Inheritance is often useful, but more often overused (abused)."
 *
 * Guidelines for Implementation Inheritance:
 * 1. Do not use inheritance for code reuse, use composition.
 * 2. Minimize the implementation in base classes. Base classes should be thin.
 * 3. Minimize the level of hierarchies in implementation inheritance.
 */


