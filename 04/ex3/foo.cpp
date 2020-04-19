void foo(const int**);

int main(){
  int** v = new int* [10];
  foo(v);
  return 0;
}
