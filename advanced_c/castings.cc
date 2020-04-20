//############################################################################
/*
 * All Castings Considered
 *
 *
 * Type Conversion:
 *    1. Implicit Type Conversion
 *    2. Explicit Type Conversion - Casting
 */

/*
 * 1. static_cast
 */
int i = 9;
float f = static_cast<float>(i);  // convert object from one type to another
dog d1 = static_cast<dog>(string("Bob"));  // Type conversion needs to be defined.
dog* pd = static_cast<dog*>(new yellowdog()); // convert pointer/reference from one type 
                                              // to a related type (down/up cast)

/*
 * 2. dynamic_cast 
 */
dog* pd = new yellowdog();
yellowdog py = dynamic_cast<yellowdog*>(pd); 
// a. It convert pointer/reference from one type to a related type (down cast)
// b. run-time type check.  If succeed, py==pd; if fail, py==0;
// c. It requires the 2 types to be polymorphic (have virtual function).

/*
 * 3. const_cast
 */                                        // only works on pointer/reference
const char* str = "Hello, world.";         // Only works on same type
char* modifiable = const_cast<char*>(str); // cast away constness of the object 
                                           // being pointed to

/*
 * 4. reinterpret_cast
 */
long p = 51110980;                   
dog* dd = reinterpret_cast<dog*>(p);  // re-interpret the bits of the object pointed to
// The ultimate cast that can cast one pointer to any other type of pointer.

/*
 * C-Style Casting:  
 */
short a = 2000;
int i = (int)a;  // c-like cast notation
int j = int(a);   // functional notation
//   A mixture of static_cast, const_cast and reinterpret_cast


/*
 * Generally C++ style of casts are preferred over the C-style, because:
 * 1. Easier to identify in the code.
 * 2. Less usage error. C++ style provides:
 *    a. Narrowly specified purpose of each cast, and
 *    b. Run-time type check capability.
 */





/*
 * Casting could be risky.
 *
 * Example with dynamic_cast:
 */
class dog {
   public:
   virtual ~dog() {}
};

class yellowdog : public dog {
   int age;
   public:
   void bark() { cout<< "woof. I am " << age  << endl; }
};

int main() {
   dog* pd = new dog();
   yellowdog* py = dynamic_cast<yellowdog*>(pd);
   py->bark();
   cout << "py = " << py << endl;
   cout << "pd = " << pd << endl;
   ...
}

OUTPUT:
woof.
py = 0
pd = 57873400









/* casting could be a handy hack tool */

class dog {
	public:
	std::string m_name;
	dog():m_name("Bob") {}
	void bark() const { 
	  std::cout << "My name is " << m_name << std::endl;
	}
};







//	  m_name = "Henry";
//	  const_cast<dog*>(this)->m_name = "Henry";



/*
 * =========================================  C++ Style Casting ================================
 *                             Generate_Code   Generate_data      risky   data_type
 * Object Casting:            
 *    static_cast                 yes              yes             2      any types
 *                                                                       (as long as type 
 *                                                                       conversion is defined)
 * Pointer/Reference Casting:
 *    static_cast                 no               no              4     related types
 *    dynamic_cast                yes              no              3     related types(down-cast)
 *    const_cast                  no               no              1     same type
 *    reinterpret_cast            no               no              5      any types
 *
 *
 *
 *
 *
 * =========================================  C Style Casting ================================
 *                             Generate_Code  Generate_data      risky   data_type
 * Object Casting:               yes              yes             5      any types
 *                                                                       (as long as type 
 *                                                                       conversion is defined)
 * Pointer/Reference Casting:    no               no              5      any types
 *
 *
 * Notes can be downloaded at my website: boqian.weebly.com
 *
 * Note:
 * 1. const_cast, dynamic_cast and reinterpret_cast can only work on pointers/references.
 * 2. static_cast of objects is very different from static_cast of pointers. 
 * 3. reinterpret_cast basically reassigning the type information of the bit pattern. 
 *    It should only be used in low-level coding.
 * 4. dynamic_cast does static_cast plus run-time type check.
 * 5. dynamic_cast and static_cast for pointers can only work on related type (e.g., 
 *    base <-> derived).
 *
 */



/* Use polymorphism to minimize castings */

class dog {
   public:
   virtual ~dog() {}
};

class yellowdog : public dog {
   public:
   void bark() { cout<< "Yellow dog rules! "  << endl; }
};

int main() {
   dog* pd = get_dog();
   if (yellowdog *py = dynamic_cast<yellowdog*>(pd)) {
      py->bark();
   }
   delete pd;
}



/* Add virtual bark() in dog */

class dog {
   public:
   virtual ~dog() {}
   virtual void bark() {}
};

class yellowdog : public dog {
   public:
   void bark() { cout<< "Yellow dog rules! "  << endl; }
};

int main() {
   dog* pd = get_dog();
   pd->bark();
   delete pd;
}

















