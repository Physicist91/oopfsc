


//############################################################################
/*
 *  Static Polymorphism
 */

// (Dynamic) Polymorphism:

struct TreeNode {TreeNode *left, *right;};

class Generic_Parser {
   public:
   void parse_preorder(TreeNode* node) {
      if (node) {
         process_node(node);
         parse_preorder(node->left);
         parse_preorder(node->right);
      }
   }
   private:
   virtual void process_node(TreeNode* node) { }
};

class EmployeeChart_Parser : public Generic_Parser {
   private:
   void process_node(TreeNode* node) {
       cout << "Customized process_node() for EmployeeChart.\n";
   }
};
   
int main() {
   ...
   EmployeeChart_Parser ep;
   ep.parse_preorder(root);
   ...
}

/*
 * 1. is-a relationship between base class and derived class
 * 2. Base class defines a "generic" algorithm that's used by derived class
 * 3. The "generic" algorithm is customized by the derived class
 */
// TMP: Template Metaprogramming
template <typename T> class Generic_Parser {
   public:
   void parse_preorder(TreeNode* node) {
       if (node) {
           process_node(node);
           parse_preorder(node->left);
           parse_preorder(node->right);
       }
   }
   void process_node(TreeNode* node) {
       static_cast<T*>(this)->process_node(node);
   }
};

class EmployeeChart_Parser : public Generic_Parser<EmployeeChart_Parser> {
   public:
   void process_node(TreeNode* node) {
       cout << "Customized process_node() for EmployeeChart.\n";
   }
};
   
int main() {
   ...
   EmployeeChart_Parser ep;
   ep.parse_preorder(root);
   ...
   MilitaryChart_Parser ep;
}


// Curiously recurring template pattern (static polymorphism, simulated polymorphism)



// Free Lunch??



// Generalized Static Polymorphism
template<typename T>
T Max(vector<T> v) {
   T max = v[0];
   for (typename std::vector<T>::iterator it = v.begin(); it!=v.end(); ++it) {
      if (*it >  max) {
         ret = *it;
      }
   }
   return max;
}

  



