/* Class Name:  Advanced C++
 *
 * Contents: Medium to advanced C++ coding techniques.
 *
 * Prerequisite:  2+ Years of C++ programming
 *
 * Class Notes: boqian.weebly.com
 *
 * Language Standard: C++03
 *
 * Youtube HD issue:
 */







                        C++ Advanced:  Session 1







//############################################################################
/*
Compiler silently writes 4 functions if they are not explicitly declared:
1. Copy constructor.
2. Copy Assignment Operator.
3. Destructor.
4. Default constructor (only if there is no constructor declared).
*/

class dog {};

/* equivalent to */

class dog {
	public:
		dog(const dog& rhs) {...};   // Member by member initialization

		dog& operator=(const dog& rhs) {...}; // Member by member copying

		dog() {...};  // 1. Call base class's default constructor; 
		              // 2. Call data member's default constructor.

		~dog() {...}; // 1. Call base class's destructor; 
		              // 2. Call data member's destructor.
}
/*
Note:
1. They are public and inline.
2. They are generated only if they are needed.
*/


/*  Example:
  1. Copy constructor.   - no
  2. Copy Assignment Operator. - yes
  3. Destructor.  - no
  4. Default constructor - no
*/
class dog {
	public:
		string& m_name;

		dog(string name = "Bob") {m_name = name; cout << name << " is born." << endl;}
		~dog() { cout<< m_name << " is destroyed.\n" << endl; }
};

int main() {
  dog dog1("Henry");
  dog dog2;
  dog2 = dog1;
}

OUTPUT:
Henry is born.
Bob is born.
Henry is distroied.
Henry is distroied.


/*Questions: 
  What functions are silently written by compiler.


Notes:
 Compiler will refuse to generate default copy assignment operator when it is illegal.
 1. Reference member data
 2. Const member data
 Such classes cannot be used in STL containers because a container's elements has to
 be copy constructable and assignable.
*/







/* Example 2: */
class collar {
	public:
	collar() { std::cout <<  " collar is born.\n"; }
};

class dog {
	collar m_collar;
	string& m_name;
};

int main() {
	dog dog1;
}


output:
main.cc:13: error: no matching function for call to `dog::dog()'
main.cc:8: note: candidates are: dog::dog(const dog&)



// Add to dog:
// string& m_name; 
// Result: not compilable because age is not initialized.





/* C++ 11 Update: */
class dog {
   public:
      dog() = default;
      dog(string name) {...};
}









                     



//############################################################################
/*
 * Disallow the use of compiler generated functions 
 *
 *
 *
 * Not all classes need the compiler generated functions.
 *
 * E.g.  a class "OpenFile" represents a file being opened. Its constructor at
 * least needs a file name as parameter. So default constructor is not needed.
 */

/*
 * C++ 11 Update:
 */
class dog {
   public:
   dog(const dog& ) = delete; // Prevent copy constructor from being used.
                              // Useful when dog holds unsharable resource.
}



/* For C++ 03:
 *
1. Default constructor.      - easy
2. Copy constructor.         - see following solutions
3. Copy Assignment Operator. - see following solutions


Solution:
 Declare them as private functions, but not define them.
 -- Members and friends get link-time error, others get compile-time error.
*/
class dog {
   private:
   dog& operator=(const dog& rhs);   
};




/*
Solution 2:
 In its base class, declare them as private function, but not define them.
 -- Compile time error.
*/
class yellowdog : public dog {
};
int main() {
   yellowdog y1("henry");
   yellowdog  y2;
   y2 = y1;
}

// Note: the same techniques can used to disallow any function from being used.





/* Question: Can we disallow destructor from being used?
 */





/* Solution */
class dog {
  public:
     void destroyMe() { delete this; }
  private:
     ~dog() { cout<< m_name.m_str << " is destroyed.\n" << endl; }
};

int main ()
{
  dog* dog1 = new dog();
  dog1->destroyMe();
}


/* Usage: 1. Reference counting smart pointer.
 *        2. Small stack embedded programming.
 */










//############################################################################
/*
Declare a destructor virtual in polymorphic base classes
*/

/* Problem */
class yellowdog : public dog {
};

dog* dogFactory::createDog() {
	dog* pd = new yellowdog();
	return pd;
}

int main() {
	dog* pd = dogFactory::createDog();
	...
	delete pd;  // Only dog's destructor is invoked, not yellowdog's.
}


/*
Solution: 
*/
class dog {
      virtual ~dog() {...}
}

/* 
Note: All classes in STL have no virtual destructor, so be careful inheriting 
from them.
*/


/*
When we should use virtual destructor:
Any class with virtual functions should have a virtual destructor.

When not to use virtual destructor:
1. Size of the class needs to be small;
2. Size of the class needs to be precise, e.g. passing an object from C++ to C.
*/




/* Solution 2: 
 *    using shared_prt
 */

class Dog {
public:
   ~Dog() {  cout << "Dog is destroyed"; }
};

class Yellowdog : public Dog {
public:
   ~Yellowdog() {cout << "Yellow dog destroyed." <<endl; }
};


class DogFactory {
public:
   //static Dog* createYellowDog() { return (new Yellowdog()); }
   static shared_ptr<Dog> createYellowDog() { 
      return shared_ptr<Yellowdog>(new Yellowdog()); 
   }
   //static unique_ptr<Dog> createYellowDog() {
   //   return unique_ptr<Yellowdog>(new Yellowdog());
   //}

};

int main() {

   //Dog* pd = DogFactory::createYellowDog();
   shared_ptr<Dog> pd = DogFactory::createYellowDog();
   //unique_ptr<Dog> pd = DogFactory::createYellowDog();
   
   //delete pd;
   
	return 0;
}
/*Note: you cannot use unique_ptr for this purpose */












//############################################################################
/*
 * Prevent Exceptions from Leaving Destructors.
 */







class dog {
	public:
	string m_name;
	dog(string name) {m_name = name; cout << name << " is born." << endl; }
	~dog() { cout<< m_name << " is distroied.\n" << endl; }
   void prepareToDestr() {...; throw 20; }
   void bark() {...}
	...
};

int main{} {
  try {
     dog dog1("Henry");
     dog dog2("Bob");
     dog1.bark(); 
     dog2.bark();
     dog1.prepareToDestr();
     dog2.prepareToDestr();
  } catch (int e) {
	  cout << e << " is caught" << endl;
  }
}

OUTPUT:
Henry is born.
Bob is born.
Bob is distroied.
Henry is distroied.
20 is caught











/*
 * Solution 1: Destructor swallow the exception.
 */
	~dog() { 
      try {
         // Enclose all the exception prone code here
      } catch (MYEXCEPTION e) {
         // Catch exception
      } catch (...) {
      }
   }







/* 
 * Solution 2: Move the exception-prone code to a different function.
 */














/*
Which one to use?

It depends on who is the better person to handle the exception, dog or dog's client.
*/















//############################################################################
/*
Never call virtual functions in constructor or destructor.
*/
class dog {
	public:
		string m_name;
		dog(string name) {m_name = name;  bark();}
		virtual void bark() { cout<< "Woof, I am just a dog " << m_name << endl;}
};

class yellowdog : public dog {
	public:
		yellowdog(string name) : dog(string name) {...}
		virtual void bark() { cout << "Woof, I am a yellow dog " << m_name << endl; }
};

int main ()
{
  yellowdog mydog("Bob");
}



OUTPUT:
Woof, I am just a dog Bob.

/*

During the construction, all virtual function works like non-virtual function.

Why?
Base class's constructor run before derived class's constructor. So at the 
time of bark(), the yellowlog is not constructed yet.


Why Java behaves differently?

There is a fundamental difference in how Java and C++ defines an object's Life time.
Java: All members are null initialized before constructor runs. Life starts before constructor.
C++: Constructor is supposed to initialize members. Life starts after constructor is finished.

Calling down to parts of an object that haven not yet initialized is inherently dangerous.

*/


/*
solution 1:
*/
class dog {
	public:
		...
		dog(string name, string color) {m_name = name; bark(color);}
		void bark(string str) { cout<< "Woof, I am "<< str << " dog " << m_name << endl;}
};

class yellowdog : public dog {
	public:
		yellowdog(string name):dog(name, "yellow") {}
};

int main ()
{
  yellowdog mydog("Bob");
}

OUTPUT:
Woof, I am yellow dog Bob



/*
solution 2:
*/
class dog {
	public:
		...
		dog(string name, string woof) {m_name = name; bark(woof);}
		dog(string name) {m_name = name; bark( getMyColor() );}
		void bark(string str) { cout<< "Woof, I am "<< str << "	private:
	private:
		static string getMyColor() {return "just a";} 
};

class yellowdog : public dog {
	public:
		yellowdog(string name):dog(name, getMyColor()) {}
	private:
		static string getMyColor() {return "yellow";}  //Why static? 
};

int main ()
{
  yellowdog mydog("Bob");
}
OUTPUT:
Woof, I am yellow dog Bob



















//############################################################################
/*
 * Handle self-assignment in operator=
 *
 *
 * Operator overload: exploite people's intuition and reduce their learning curve
 */

dog dd;
dd = dd;  // Looks silly

dogs[i] = dogs[j]; // looks less silly




/* Implementing Assignment Operator */
class collar;
class dog {
   collar* pCollar;
   dog& operator=(const dog& rhs) {
      if (this == &rhs)
         return *this;

      collar* pOrigCollar = pCollar;
      pCollar = new collar(*rhs.pCollar);
      delete pOrigCollar;
      return *this;
   }
}









/* Solution 2: Delegation */
class dog {
   collar* pCollar;
   dog& operator=(const dog& rhs) {
      *pCollar = *rhs.pCollar;   // member by member copying of collars or
                                 // call collar's operator=
      return *this;
   }
}












   
//############################################################################
/*
Copy functions copy all parts of an object.
	- Copy constructor
	- Copy assignment operator


Make sure to do three things in copy constructor and copy assignment operator:
1. Copy all local data members.
   - Inside a class definition, separate data members from function members.

2. Invoke copying function in all base classes.
   - Multiple inheritance.

3. Every time a new data member is added, update the copying functions.
   - Difficult to remember until it becomes a habit.
   - Copy assignment operator calling copy constructor? 
      (what happens? Java?)
*/

class dog {
   dog(string name) {...}
   dog() { 
      dog("default_name");
   }
}
int main() {
   dog dog1;
}








//############################################################################
/* Named Parameter Idiom */



/* Problem
C++ only support positional parameters, it doesn't support named parameters as 
what Python does.

 */

class OpenFile {
public:
   OpenFile(string filename, bool readonly=true, bool appendWhenWriting=false, 
            int blockSize=256, bool unbuffered=true, bool exclusiveAccess=false);
}

OpenFile pf = OpenFile("foo.txt", true, false, 1024, true, true);
// Inconvenient to use
// Unreadable
// Inflexible

// What's ideal is:
OpenFile pf = OpenFile(.filename("foo.txt"), .blockSize(1024) );





/* Solution */
class OpenFile {
public:
  OpenFile(std::string const& filename);
  OpenFile& readonly()  { readonly_ = true; return *this; }
  OpenFile& createIfNotExist() { createIfNotExist_ = true; return *this; }
  OpenFile& blockSize(unsigned nbytes) { blockSize_ = nbytes; return *this; }
  ...
};

OpenFile f = OpenFile("foo.txt")
           .readonly()
           .createIfNotExist()
           .appendWhenWriting()
           .blockSize(1024)
           .unbuffered()
           .exclusiveAccess();

OpenFile f = OpenFile("foo.txt").blockSize(1024);


















//############################################################################
/* 
 * Named Constructor Idiom 
 *
 * C++ constructors always have the same name as the class 
 */














// Point epresents a point on a 2-dimension plane
class Point {
public:
  Point(float x, float y);          // Rectangular coordinates
  Point(float radius, float angle); // Polar coordinates (radius and angle)
};

int main()
{
  Point p = Point(5.7, 1.2);   // Ambiguous: Which coordinate system?
}









/* Solution */
class Point {
  Point(float x, float y);     // Rectangular coordinates

  // These static methods are the so-called "named constructors"
  static Point rectangular(float x, float y) { return Point(x,y);}  
  static Point rectangular_heap(float x, float y) { return new Point(x,y);}  
  static Point rectangular_heap_p(float x, float y) { return new(buffer) Point(x,y);}  
  static Point polar(float radius, float angle) { 
      return Point(radius*cos(angle), radius*sin(angle)); 
  }
  ...
};

  Point p = Point::rectangular(5.7, 1.2);   // No longer ambiguous
  Point* p = new Point::rectangular(5.7, 1.2);   // Wrong

/* Benefits:
 1. Less error-prone
 2. No longer depends on parameter list to differentiate constructors.
 */


/*
 * How to create a Point on heap
 */



/* 
 * Solution 1: Create a separate heap version of named constructor.
 */









/*
 * Solution 2:
 */
 Point* pp = new Point(Point::rectangular(5.7, 1.2)); 
 Point* pp = new(buffer) Point(Point::rectangular(5.7, 1.2)); 












/*
 * Solution 3: A variation of named constructor
 */
enum Rectangular {rectangular};
enum Polar       {polar};
class Point {
public:
  Point(Rectangular, float x, float y) { cout << "creating Point with rectangular coordinates" << endl;}  
  Point(Polar, float radius, float angle) { 
      cout << "creating Point with polar coordinates" << endl;; 
  }
};



   Point* pp = new Point(polar, 5.7, 1.2);













