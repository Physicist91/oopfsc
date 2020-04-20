
//############################################################################
/*
 *  Introduction to Template
 */
template<typename T>
T square(T x) {
   return x*x;
}

template<typename T>
class BoVector {
   T arr[1000];
   int size;
public:
   BoVector():size(0) {}
   void push(T x) { arr[size] = x; size++; }
   T get(int i) const { return arr[i]; }
   int getSize() const { return size; }
   //void print() const {for(int i=0; i<size; i++) {cout << arr[i] << endl;}}
   void print() const { 
      const int* p = arr; 
      for(int i=0;  i<size; i++) {cout << *(p++) << endl;}
   }
};

template<typename T>
BoVector<T> operator*(const BoVector<T>& rhs1, BoVector<T>& rhs2) {
   BoVector<T> ret;
   for (int i=0; i<rhs1.getSize(); i++) {
      ret.push(rhs1.get(i)*rhs2.get(i));
   }
   return ret;
}

int main()
{
   cout << square(5) << endl;

   BoVector<int> bv;
   bv.push(2);
   bv.push(5);
   bv.push(8);
   bv.push(9);
   bv.print();

   cout << "Print squared bv: " << endl;
   bv = square(bv);
   bv.print();
}




//############################################################################
/*
 *  Template Specializaton and Partial Specialization
 */


//############################################################################
/*
 *  Function Template Type Deduction
 */

template<class T>
void f() {
   ...
}

int main() {
   f<int>();  // T is explicitly specified
}


// The type T can also be deduced 

template<class T>
void f(T t) {
   ...
}

int main() {
   f(67);  // T is deduced by compiler to be integer

   f<long>(67);  // explicitly tell compiler T's type

   f(67L);
}




//############################################################################
/*
 * Keyword typename and Its Usage
 */

template<class T>
void printAge(T& item) {
   ...
}

template<typename T>
void printAge(T& item) {
   ...
}

//Question: What's the difference?
//          Which one should I use?
//






/*
 * Dependent Type
 */
template<typename T> A {
   vector<T> vec;
}

/*
 * Nested Dependent Type
 */
template<typename T> A {
   T::age myAge = 9;
   vector<T>::iterator itr;
}



/*
 * Second Usage of 'typename'
 */
class Dog {
   public:
   typedef int age;
};

template<class T>
void printMyAge(T& item) {
   int n = 9;
   T::age* a = &n;
   cout << (*a) << endl;
}

int main() {
   Dog d;
   printMyAge<Dog>(d);    
}




// The code won't compile, why?

//class Wolf {
//   public:
//   int age;
//}; 



/*
 * RULE: always preceed a nested dependant type name with 'typename'
 */



// EXCEPTION: in base class list or in initialization list

template<typename T>
class D : public T::NestedBaseClass {
public:
   D(int x) : T::NestedBaseClass(x) { 
      typename T::NestedBaseClass y;
      ...
   }
}








//############################################################################
/*
 *  Template Specializaton and Partial Specialization
 */
