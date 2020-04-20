#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

//Partition by the pivot element
int Partition(int a[], int left, int right){

  //Use the rightmost element as pivot
  int pivot = a[right];

  //starting from the left, we want to find the location of the next pivot to partition the array
  //the idea is that, any element less than the pivot should be to its left
  int iPivot = left;
  for(int i = left; i<right; i++){
    if(a[i] <= pivot){
      std::swap(a[i],a[iPivot]);
      iPivot++;
    }
  }
  std::swap(a[iPivot], a[right]);

  //use iPivot as the position of the new pivot
  return iPivot;
}

//Iterative quicksort
void quickSort(int a[], int size){

  //stack of std::pairs to store start and end index
  std::stack<std::pair<int, int>> myStack;

  myStack.push(std::make_pair(0, size-1));

  while(!myStack.empty()){
    int start = myStack.top().first, end = myStack.top().second;
    myStack.pop();

    //find the pivot point
    int pivot = Partition(a, start, end);

    //push the "left array" into stack
    if(pivot - 1 > start) myStack.push(std::make_pair(start, pivot - 1));

    //push the "right array" into stack
    if(pivot + 1 < end) myStack.push(std::make_pair(pivot + 1, end));
  }
}

int main(){
  //int a[] = {6, -3, 5, 1, 9, 8, 3, 2, -6};
  int a[] = {3, 2, 1, 4, 5};
  int N = sizeof(a)/sizeof(a[0]);
  std::cout << "N is " << N << std::endl;
  quickSort(a, N);

  for(int i =0; i<N; ++i){
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
