/*
 * Container's member functions vs algorithms
 */

// Functions with same name:
// List:
void remove(const T); template<class Comp> void remove_if(Comp);
void unique();        template<class Comp> void unique(Comp);
void sort();          template<class Comp> void sort(Comp);
void merge(list&);    template<class Comp> void merge(Comp);
void reverse();

// Associative Container:
size_type count(const T&) const;
iterator find(const T&) const;
iterator lower_bound(const T&) const;
iterator upper_bound(const T&) const;
pair<iterator,iterator> equal_range (const T&) const;
// Note: they don't have generalized form, because comparison is defined by
//       the container.

// Unordered Container:
size_type count(const T&) const;
iterator find(const T&);
std::pair<iterator, iterator> equal_range(const T&);
// Note: No generalized form; use hash function to search















unordered_set<int> s = {2,4,1,8,5,9};  // Hash table 
unordered_set<int>::iterator itr;

// Using member function
itr = s.find(4);                      // O(1)

// Using Algorithm
itr = find(s.begin(), s.end(), 4);    // O(n)













// How about map/multimap?
map<char, string> mymap = {{'S',"Sunday"}, {'M',"Monday"}, {'W', "Wendesday"}, ...};


// Using member function
itr = mymap.find('F');                                           // O(log(n))

// Using Algorithm
itr = find(mymap.begin(), mymap.end(), make_pair('F', "Friday")); // O(n)












// How about list?
list<int> s = {2,1,4,8,5,9};

// Using member function
s.remove(4);                    // O(n)
// s: {2,1,8,5,9}

// Using Algorithm
itr = remove(s.begin(), s.end(), 4);  // O(n)
// s: {2,1,8,5,9,9}
s.erase(itr, s.end());
// s: {2,1,8,5,9}


// Sort
//
// Member function
s.sort();

// Algorithm
sort(s.begin(), s.end());   // Undefined behavior











// s: {2,4,1,8,5,9}
// s: {2,1,8,5,9,9}
/*
list<int>::iterator itr = remove(s.begin(), s.end(), 4);  // O(n)
s.erase(itr, s.end());
// Similarly for algorithm: remove_if() and unique()
*/

// Using member function
s.sort();

// Using Algorithm
sort(s.begin(), s.end());   // Undefined Behavior











/* 
 * Summary:
 *
 * 1. There are duplicated functions between container's member functions and 
 *    algorithm functions.
 * 2. Prefer member functions over algorithm functions with the same names.
 *
 */















