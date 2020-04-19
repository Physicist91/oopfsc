#include <iostream>
#include "ll.h"

//Compilation:
//g++ -std=c++11 main.cc ll.cpp

//The printlist function
void printList(const List& list) {
  for (shared_ptr<Node> n =list.first(); n!= 0; n = list.next(n))
      std::cout << n->value << std::endl;
}

//The function to concatenate
void append(List& list1, const List& list2){
  //list1.tail->next = list2.first();
  shared_ptr<Node> temp;
  for(temp = list2.first(); temp!=nullptr; temp=list2.next(temp))
    list1.append(temp->value);
}

int main(){

  //Define list1 and find the maximum value
  List list;
  list.append(2);
  list.append(3);
  list.insert(list.first(), 1);
  std::cout << "List1 is:\n";
  printList(list);
  std::cout << "Max value in the list: " << list.max() << "\n";

  //Define list2 and concatenate with list1
  List list2;
  list2.append(5);
  list2.append(6);
  list2.insert(list2.first(), 7);
  std::cout << "List2 is:\n";
  printList(list2);
  std::cout << "Max value in the list: " << list2.max() << "\n";
  append(list, list2);
  std::cout << "Concatenated list is:\n";
  printList(list);

  //List list2 = list;
}
