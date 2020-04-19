/*
 * Remove from Vector or Deque
 */
  vector<int> vec = {1, 4, 1, 1, 1, 12, 18, 16}; // To remove all '1'
  for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
     if ( *itr == 1 ) {
        vec.erase(itr);
     }
  }   // vec: { 4, 12, 18, 16}
  // Complexity: O(n*m)

  
  remove(vec.begin(), vec.end(), 1);  // O(n) 
                                      // vec: {4, 12, 18, 16, ?, ?, ?, ?}

  
  
  vector<int>::iterator newEnd = remove(vec.begin(), vec.end(), 1);   // O(n)
  vec.erase(newEnd, vec.end());  

  // Similarly for algorithm: remove_if() and unique()


  // vec still occupy 8 int space: vec.capacity() == 8
  vec.shrink_to_fit();   // C++ 11
  // Now vec.capacity() == 4 

  // For C++ 03:
  vector<int>(vec).swap(vec); // Release the vacant memory














/*
 * Remove from List
 */
  list<int> mylist = {1, 4, 1, 1, 1, 12, 18, 16};

  list<int>::iterator newEnd = remove(mylist.begin(), mylist.end(), 1);  
  mylist.erase(newEnd, mylist.end());


  mylist.remove(1);  // faster















 
/*
 * Remove from associative containers or unordered containers
 */
  multiset<int> myset = {1, 4, 1, 1, 1, 12, 18, 16};

  multiset<int>::iterator newEnd = remove(myset.begin(), myset.end(), 1);  
  myset.erase(newEnd, myset.end()); // O(n)

  myset.erase(1); // O(log(n)) or O(1)















/*
 * Remove and do something else
 */

// Associative Container:
multiset<int> s = {1, 4, 1, 1, 1, 12, 18, 16};;

multiset<int>::iterator itr;
for (itr=s.begin(); itr!=s.end(); itr++) {
   if (*itr == 1) {
      s.erase(itr);      
      cout << "Erase one item of " << *itr << endl;
   } 
}

// First erase OK; second one is undefined behavior














//Solution:
multiset<int>::iterator itr;
for (itr=s.begin(); itr!=s.end(); ) {
   if (*itr == 1) {
      cout << "Erase one item of " << *itr << endl;
      s.erase(itr++);
   } else {
      itr++;
   }
}






// Sequence Container:
vector<int> v = {1, 4, 1, 1, 1, 12, 18, 16};
vector<int>::iterator itr2;
for (itr2=v.begin(); itr2!=v.end(); ) {
   if (*itr2 == 1) {
      cout << "Erase one item of " << *itr2 << endl;
      v.erase(itr2++);
   } else {
      itr2++;
   }
}


// Sequence container and unordered container's erase() returns  
// iterator pointing to next item after the erased item.








//Solution:
for (itr2=v.begin(); itr2!=v.end(); ) {
   if (*itr2 == 1) {
      cout << "Erase one item of " << *itr2 << endl;
      itr2 = v.erase(itr2);
   } else {
      itr2++;
   }
}


// 1. Sequence container and unordered container's erase() returns the next 
//    iterator after the erased item.
// 2. Associative container's erase() returns nothing.
// 
// A thing about efficiency: v.end()



vector<int> c = {1, 4, 1, 1, 1, 12, 18, 16};

// Use Algorithm
bool equalOne(int e) {
   if (e == 1) {
      cout << e << " will be removed" << endl;
      return true;
   }
   return false;
}
auto itr = remove_if(c.begin(), c.end(), equalOne);
c.erase(itr, c.end());



// Use bind():
bool equalOne(int e, int pattern) {
   if (e == pattern) {
      cout << e << " will be removed" << endl;
      return true;
   }
   return false;
}
remove_if(v.begin(), v.end(), bind(equalOne, placeholders::_1, 1));



// Lambda:
auto itr = remove_if(v.begin(), v.end(), 
      [](int e){ 
         if(e == 1) {
            cout << e << " will be removed" <<endl; return true; 
         } 
      } 
   );


