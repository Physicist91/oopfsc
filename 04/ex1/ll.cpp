#include "ll.h"

/**********************************************************************/
//Implementation of Class List
/**********************************************************************/

void List::append(int i){ //append a value to the end
  Node *temp = new Node;
  temp->value = i;
  temp->next = nullptr;
  if(head == nullptr){ //in the case of an empty list
    head = temp;
    //tail = temp;
    temp = nullptr;
  } else { //if node already exists, put it at the end of the list

    Node* current {new Node};
    for(current = head; current!=nullptr; current=current->next){
      if(current->next == nullptr) break;
    }

    current->next = temp;
    current = nullptr;
    temp = nullptr;
  }
};

void List::insert(Node* n, int i){ //insert a value before n
  Node *temp = new Node;
  temp->value = i;

  if(n == head){ //insertion at the start
    temp->next = head;
    head=temp;
    temp = nullptr;
  } else { //insertion at any other node n

    Node *previous = new Node;
    Node *current = new Node;

    for(current = head; current != nullptr; current=current->next){
      previous = current;
      current = current->next;
      if(current == n) break;
    }
    previous->next = temp;
    temp->next = current;
    previous = nullptr;
    current = nullptr;
  }
};

void List::erase(Node* n){ //remove n from the list

  if(n == head){ //if deleting the head node
    Node *temp = new Node;
    temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;

  } else {
    Node *previous = new Node;
    Node *current = new Node;
    for(current = head; current!=nullptr; current=current->next){
      previous = current;
      current = current->next;
      if(current == n) break;
    }
    previous->next = current->next;
    delete current;
    current = nullptr;
    previous = nullptr;
  }

};

//The max function
int List::max(bool recompute) const {

  if(maximum==na_value || recompute == true){
    int temp = head->value;
    for(Node* n = head; n!=nullptr; n=n->next) {
      if(temp<n->value) temp = n->value;
    }
    maximum=temp;
  }

  return maximum;
};
