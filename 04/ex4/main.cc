#include <iostream>

using namespace std;

int foo (const int& ); 
int bar (int&);    // error due to line 18 "bar (l)" wrong initialization of type const.  
int main()
{
 int i = 0;    
 int& j = i;    
 static const int f = i;
 int* const p = 0;
 p = &i; // assignment of variable p of type const, reassignment of constant variable types not possible.
 *p = f;
 const int& l = j; 
 const int& k= f;
 foo (j);
 bar (l);//invalid initialization of reference of type 'int&' from expression of type 'const int&'
 foo (f);
 }