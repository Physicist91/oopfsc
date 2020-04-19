/*
 * What is object slicing?
 */

class Dog {};

class YellowDog : public Dog {
	public:
	string m_name;
	YellowDog(string name)::m_name(name){}
};

void foo(Dog d) {  }
YellowDog goo() { }

int main() {
  YellowDog yd("Gunner");
  foo(yd);       // foo() will get a Dog, a sliced yd
  Dog d = goo();
}

// Solution: use pointers




/*
void foo(Dog* d) {  
	YellowDog* py = dynamic_cast<YellowDog*>(d);
	cout << py->m_name << endl;
}
foo(&yd);
class Dog { 
	public:
	virtual ~Dog();
};
*/







/*
 * STL containers always copy objects.
 */
  vector<int> vec;
  int x = 45;
  vec.push_back(x);
  vec.insert(vec.begin(), x);

  //Solution: shared_ptr
  //



/*
 *  Functor cannot be passed by reference.
 */

class MyFunctor {
   public:
   int val;
   void operator()(int i) {cout << "Oprating on " << i << endl;}
};

int main() {
   unordered_set<int> us = {2,4,5,1,9};
   MyFunctor f;
   for_each(us.begin(), us.end(), f);
   //for_each<unordered_set<int>::iterator, MyFunctor&>(us.begin(), us.end(), f);
}


// Problem with passing by value: Slicing!!!

// Conclusion 1: functors should not be polymorphic!

// Conclusion 2: functors should be lightweight


// Solution:
//     Pimpl Idiom




class Dog {
public:
   void bark() { cout << "I don't have a name." << endl; }
};

class YellowDog : public Dog {
	string m_name;
public:
	YellowDog(string name):m_name(name){}
   void bark() { cout << "My name is " << m_name << endl; }
};

void foo (Dog d) {} 
 int main(){  
    deque<Dog*> d;
    YellowDog y("Gunner");

    d.push_front(&y);
    
    d[0]->bark();
    
    Dog d2 = y;
    
    foo(y);
 }




