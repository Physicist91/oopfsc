const int* bar();

int main(){
  int** v = new int* [10];
  v[0] = bar();
  return 0;
}
