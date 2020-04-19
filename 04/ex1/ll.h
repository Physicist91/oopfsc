//ll.h
const int na_value = -99999;

/**********************************************************************/
//Declaration of Class Node
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
    ~Node(){delete next;}
};

//Declaration of class List
class List {
private:
  //Node *head, *tail;
  Node* head;
  mutable int maximum;

public:

  List(){
    head=nullptr;
    //tail=nullptr;
    maximum=na_value;
  };
  ~List(){delete head;};

  Node* first() const { //return pointer to first entry
    return head;
  };

  Node* next(const Node* n) const { //return pointer to node after n
    return n->next;
  };

  void append(int i);

  void insert(Node* n, int i);

  void erase(Node* n);

  //The max function
  int max(bool recompute=false) const;


};
