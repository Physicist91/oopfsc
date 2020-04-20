# include <iostream>

class A {
public:
    void foo() const {std::cout << "A::foo" << std::endl;}
};

class B : public A {
public:
  void foo() {std::cout << "B::foo" << std::endl;}
};

class C : private B {
public:
  void bar() { foo();}
};

void test(const A& a) {a.foo();}

int main(){
  A a; B b; C c;
  a.foo();
  b.foo();
  test(b);
  c.bar();
  //test(c);
}
