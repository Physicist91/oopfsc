//ll.h
#include <memory>
using namespace std;

/**********************************************************************/
//Declaration of Class Node
/**********************************************************************/

class Node {
  private:
    //Node *next;
    shared_ptr<Node> next;
    weak_ptr<Node> previous;
    friend class List;
  public:
    Node(){ //constructor will initialize the members
      value = 0;
      next = nullptr;
    };
    int value;
    ~Node() = default;
};

//Declaration of class List
class List {
private:
  //Node *head, *tail;
  shared_ptr<Node> head;
  //shared_ptr<Node> tail;
  mutable int maximum;

public:

  List(){
    head=nullptr;
    //tail=nullptr;
    maximum=0;
  };
  ~List() = default;

  shared_ptr<Node> first() const { //return pointer to first entry
    return head;
  };

  shared_ptr<Node> next(const shared_ptr<Node> n) const { //return pointer to node after n
    return n->next;
  };

  void append(int i);

  void insert(shared_ptr<Node> n, int i);

  void erase(shared_ptr<Node> n);

  //The max function
  int max(bool recompute=false) const;

};
