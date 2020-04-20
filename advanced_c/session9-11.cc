
//############################################################################
/* Resource Acquisition is Initialization (RAII)
 * 
 * Use objects to manage resources: 
 * 	memory, hardware device, network handle, etc.
 */

Mutex_t   mu = MUTEX_INITIALIZER;
 
void functionA()
{
   Mutex_lock( &mu );
   ... // Do a bunch of things
   Mutex_unlock( &mu );      // Will this line always be executed?
}



/*
 * Solution:
 */ 
class Lock {
   privat:
      Mutext_t* m_pm;
   public:
      explicit Lock(Mutex_t *pm) { Mutex_lock(pm); m_pm = pm;};  
      ~Lock() { Mutex_unlock(m_pm); };
}

void functionA()
{
   Lock mylock(&mu);
   ...  // Do a bunch of things
}  // The mutex will always be released when mylock is destroied from stack




/* Conclusion:
 *
 * The only code that can be guaranteed to be executed after exception is 
 * thrown are the destructor of objects residing on the stack. 
 *
 * Resource management therefore needs to be tied to the lifespan of 
 * suitable objects in order to gain automatic deallocation and reclamation.
 */






/* Note 1:
 * Another good example of RAII:  tr1:shared_ptr
 */
int function_A() {
   std::tr1::shared_ptr<dog> pd(new dog()); 
   ...
} // The dog is destructed when pd goes out of scope (no more pointer
  // points to pd).







// Another example:

class dog;
class Trick;
void train(tr1::shared_ptr<dog> pd, Trick dogtrick);
Trick  getTrick();

int main() {
   tr1::shared_ptr<dog> pd(new dog());
   train(pd, getTrick());
}
//Question: What's the problem with above code:


// What happens in train()'s parameter passing:
// 1. new dog();
// 2. getTrick();
// 3. construct tr1::shared_ptr<dog>.
// The order of these operations are determined by compiler.


// Conclusion: Don't combine storing objects in shared pointer with other statement.












/* Note 3:
   What happens when resource management object is copied?
*/
   Lock L1(&mu);
   Lock L2(L1);

/* Solution 1: 
 * Prohibit copying. To see how to disallow copy constructor and copy 
 * assignment operator from being used, watch my another session: 
 * Disallow Compiler Generated Functions. 
 */

/* Solution 2:
 * Reference-count the underlying resource by using tr1::shared_ptr
 */

template<class Other, class D> shared_ptr(Other * ptr, D deleter);

// The default value for D is "delete", e.g.:
	std::tr1::shared_ptr<dog> pd(new dog());

class Lock {
   private:
      std::tr1::shared_ptr<Mutex_t> pMutex;
   public:
      explicit Lock(Mutex_t *pm):pMutex(pm, Mutex_unlock) { 
         Mutex_lock(pm); 
      // The second parameter of shared_ptr constructor is "deleter" function.
      }; 
 }
}

   Lock L1(&mu);
   Lock L2(L1);














//############################################################################
/* User Defined Implicit Type Conversion 
 *
 * Categories of Type Conversion:
 *                                  Implicit      Explicit
 * Standard Type Conversion            A            B
 * User Defined Type Conversion        C            D
 *                                              (casting)
 *
 *
 * Category A: Implicit Standard Type Conversion
 */
   char c = 'A';
   int i = c;  // Integral promotion

   char*  pc = 0;  // int -> Null pointer

   void f(int i);
   f(c);       

   dog* pd = new yellowdog();  // pointer type conversion


/* 
 * Category C: Implicit User Defined Type Conversion
 *
 * Defined inside class (user defined type)
 *
 * There are 2 methods to define implicit user defined type conversion:
 * Method 1: Use constructor that can accept a single parameter.
 *    - convert other types of object into your class
 * Method 2: Use the type conversion function  
 *    - convert an object of your class into other types
 */
class dog {
   public:
      dog(string name) {m_name = name; }  // NO explicit
      // If you only want to define a constructor, and no implicit type
      // conversion, always put "explicit" before the constructor to 
      // avoid inadvertent type conversion.
      string getName() {return m_name;}
  private:
      string m_name;
};

void main ()
{
  string dogname = "Bob";
  dog dog1 = dogname;
  printf("My name is %s.\n", dog1.getName());
}

OUTPUT:
My name is Bob


/* PRINCIPLE: make interface easy to use correctly and hard to use incorrectly.
 * How hard is enough?  Ideally, uncompilable.
 *
 * General guideline: 
 *    1. Avoid defining seemingly unexpected conversion.
 *    2. Avoid defining two-way implicit conversion.
 */


//My Notes:
//operator string () const { return m_name; }
// string dog2 = dog1;
//


//
//


/* Implicit type conversion is useful when creating numerical types of class,
 * such as a rational class.
 */
class Rational {
	public:
      Rational(int numerator = 0, int dennominator = 1):
               num(numerator),den(denominator) {}
      int num;  // Demo only, public data members are not recommended
      int den;

      const Rational operator*(const Rational& rhs) {
         return Rational(num*rhs.num, den*rhs.den);
      }
};

int main ()
{
   Rational r1 = 23;
	Rational r2 = r1 * 2;
}





//   Rational r3 = 3 * r1;
const Rational operator*( const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.num*rhs.num, lhs.den*rhs.den);
}

// How about this one:
      operator int () const { return num/den; }
      // one-way conversion is better
















//############################################################################
/* Named Parameter Idiom */


/* Problem
C++ functions only support positional parameters, it doesn't support named 
parameters as what Python does.
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



/* Solution 1 */
class OpenFile {
public:
  OpenFile(std::string const& filename);
  OpenFile& readonly(bool ro)  { readonly_ = ro; return *this; }
  OpenFile& createIfNotExist(bool c) { createIfNotExist_ = c; return *this; }
  OpenFile& blockSize(unsigned nbytes) { blockSize_ = nbytes; return *this; }
  ...
};

OpenFile f = OpenFile("foo.txt")
           .blockSize(1024)
           .createIfNotExist(true)
           .appendWhenWriting(true)
           .unbuffered(false)
           .readonly(true)
           .exclusiveAccess(false);

OpenFile f = OpenFile("foo.txt").blockSize(1024);






/* Question: 
 * Can I use named parameter for non-member functions? 
 */




/* Solution 2: Use Type */

void setBirthDate(int month, int day, int year);


setBirthDate(3, 1, 2012);  // March 1st, or  Jan 3rd ?




struct Day {
   explicit Day(int d):val(d){}  // Important to use explicit
   int val;
}
struct Month {
   explicit Month(int d):val(d){}  // Important to use explicit
   int val;
}
struct Year {
   explicit Year(int d):val(d){}  // Important to use explicit
   int val;
}
void setBirthDate(Month m, Day d, Year y);



setBirthDate(Month(3), Day(1), Year(2010));

setBirthDate(3, 1, 2010);  // Not compilable -- Hard to use incorrectly 











//############################################################################
/* Template Specialization for STL 
 * 
 * Specialize the standard library templates' behavior for our class
 *
 * std:: is a special namespace where we are not allowed to alter its contents
 * But we can specialize them for our types
 */

class collar;

class dog {
   collar* pCollar;
	dog(string name = "Bob") {pCollar = new collar(); cout << name << " is born." << endl; }
}

int main() {
   dog dog1("Henry");
   dog dog2("Boq");
   std::swap(dog1, dog2); 
}



