#include <memory>
#include "ll.h"
using namespace std;

/**********************************************************************/
//Implementation of Class List using shared_ptrs
//The list is now a doubly linked list
/**********************************************************************/

void List::append(int i){ //append a value to the end
  //Node *temp = new Node;
  shared_ptr<Node> temp {new Node};

  temp->value = i;
  temp->next = nullptr;

  if(head == nullptr){ //in the case of an empty list
    //temp->previous = nullptr;
    head = temp;
    //tail = temp;

  } else { //if node already exists, put it at the end of the list

    shared_ptr<Node> current {new Node};
    for(current = head; current!=nullptr; current=current->next){
      if(current->next == nullptr) break;
    }

    current->next = temp;
    temp->previous = current;
    //tail = temp;
  }
};

void List::insert(shared_ptr<Node> n, int i){ //insert a value before n
  //Node *temp = new Node;
  shared_ptr<Node> temp {new Node};

  temp->value = i;

  if(n == head){ //insertion at the start
    //temp->previous = nullptr;
    temp->next = head;
    head=temp;

  } else { //insertion at any other node n

    //Node *previous = new Node;
    shared_ptr<Node> previous {new Node};
    //Node *current = new Node;
    shared_ptr<Node> current {new Node};

    for(current = head; current != nullptr; current=current->next){
      previous = current;
      current = current->next;
      if(current == n) break;
    }

    temp->previous = previous;
    previous->next = temp;
    temp->next = current;
    current->previous = temp;

  }
};

void List::erase(shared_ptr<Node> n){ //remove n from the list

  if(n == head){ //if deleting the head node
    //Node *temp = new Node;
    shared_ptr<Node> temp {new Node};
    temp = head;
    head = head->next;
    //head->previous = nullptr;

  } else {
    //Node *current = new Node;
    shared_ptr<Node> current {new Node};
    shared_ptr<Node> previous {new Node};
    for(current = head; current!=nullptr; current=current->next){
      previous = current;
      current = current->next;
      if(current == n) break;
    }

    previous->next = current->next;
    if(current->next != nullptr) current->next->previous = previous;

  }

};

//The max function
int List::max(bool recompute) const {

  if(maximum==0 || recompute == true){
    int temp = head->value;
    for(shared_ptr<Node> n = head; n!=nullptr; n=n->next) {
      if(temp<n->value) temp = n->value;
    }
    maximum=temp;
  }

  return maximum;
};
