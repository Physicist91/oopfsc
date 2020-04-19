#include <iostream>

/**********************************************************************/
//Implementation of Class Node
/**********************************************************************/

class Node {
  private:
    Node *next;
    friend class List;
  public:
    Node(){ //constructor will initialize the members
      value = 0;
      next = nullptr;
    };
    int value;
};

/**********************************************************************/
//Implementation of Class List
/**********************************************************************/

class List {
private:
Node *head, *tail;

public:

  List(){
    head=nullptr;
    tail=nullptr;
  };
  ~List(){delete head; delete tail;};

  Node* first() const { //return pointer to first entry
    return head;
  };

  Node* next(const Node* n) const { //return pointer to node after n
    return n->next;
  };

  void append(int i){ //append a value to the end
    Node *temp = new Node;
    temp->value = i;
    temp->next = nullptr;
    if(head == nullptr){ //in the case of an empty list
      head = temp;
      tail = temp;
      temp = nullptr;
    } else { //if node already exists, put it at the end of the list
      tail->next = temp;
      tail = temp;
    }
  };

  void insert(Node* n, int i){ //insert a value before n
    Node *temp = new Node;
    temp->value = i;

    if(n == head){ //insertion at the start
      temp->next = head;
      head=temp;
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

    }
  };

  void erase(Node* n){ //remove n from the list

    if(n == head){ //if deleting the head node
      Node *temp = new Node;
      temp = head;
      head = head->next;
      delete temp;

    } else if(n == tail){ //if removing the end, we need to traverse the linked list to find the 2nd last node
      Node *previous = new Node;
      Node *current = new Node;
      for(current = head; current!=nullptr;current=current->next){
        previous = current;
        current = current->next;
      }
      tail = previous;
      previous->next = nullptr;
      delete current;
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
    }


  };
};

int main(){
  List list;
  list.append(2);
  list.append(3);
  list.insert(list.first(), 1);
  for (Node* n =list.first(); n!= 0; n = list.next(n))
      std::cout << n->value << std::endl;

  //List list2 = list;
}
