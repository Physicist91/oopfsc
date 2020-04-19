/*
 * vector
 */
  class Dog;
// Example 1:
  vector<Dog> vec(6);  // vec.capacity() == 6, vec.size() == 6, 
                       // 6 Dogs created with default constructor

// Example 2:
  vector<Dog> vec; // vec.capacity() >= 0, vec.size() == 0
  vec.resize(6);   // vec.capacity() >= 6, vec.size() == 6, 
                   // 6 Dogs created with default constructor  

// Example 3:
  vector<Dog> vec;
  vec.reserve(6);   // vec.capacity() >= 6, vec.size() == 0, 
                    // no default constructor invoked

/*
 * Strategy of avoiding reallocation:
 * 1. If the maximum number of item is known, reserve(MAX);
 * 2. If unknown, reserve as much as you can, once all data a inserted, 
 *    trim off the rest.
 */











/*
 * deque
 *
 * - No reallocation 
 *   deque has no reserve() and capacity()
 * - Slightly slower than vector
 */












/*
 * Which one to use?
 *
 * - Need to push_front a lot?  -> deque
 *
 * - Performance is important?   -> vector
 */












/*
 * 1. Element type
 *   - When the elements are not of a trivial type, deque is not much less 
 *   efficient than vector.
 */

  
/*
 * 2. Memory Availability
 *   Could allocation of large contiguous memory be a problem? 
 *   - Limited memory size
 *   - Large trunk of data
 */






/*
 * 3. Frequency of Unpredictable Growth
 */
  vector<int> vec;
  for (int x=0; x<1025; x++) 
     vec.push_back(x);   // 11 reallocations performed (growth ratio = 2)

    		//   workaround: reserve()
 










/*
 * 4. Invalidation of pointers/references/iterators because of growth
 */
  vector<int> vec = {2,3,4,5}; 
  int* p = &vec[3]
  vec.push_back(6);
  cout << *p << endl;  // Undefined behavior

  deque<int> deq = {2,3,4,5};
  p = &deq[3];
  deq.push_back(6);
  cout << *p << endl;  // OK
  // push_front() is OK too
  // deque: inserting at either end won't invalidate pointers

// Note: removing or inserting in the middle still will invalidate 
//       pointers/references/iterators






/*
 * 5. Vector's unique feature: portal to C
 */
  vector<int> vec = {2,3,4,5}; 
  
  void c_fun(const int* arr, int size);

  c_fun(&vec[0], vec.size());

  // Passing data from a list to C
  list<int> mylist;
  ...
  vector<int> vec(mylist.gegin(), mylist.end());
  c_fun(&vec[0], vec.size());

  // NOTE: &vector[0] can be used as a raw array.
  // Exception: vector<bool>
  void cpp_fun(const bool* arr, int size);
  vector<bool> vec = {true, true, false, true}; 
  cpp_fun(&vec[0], vec.size()); // Compiler Error: &vec[0] is not a bool pointer

       // workaround: use vector<int>, or bitset








/*
 * Summary:
 * 1. Frequent push_front()    - deque
 * 2. High performance         - vector
 * 3. Non-trivial data type    - deque
 * 4. Contiguous memory        - deque
 * 5. Unpredictable growth     - deque
 * 6. Pointer integrity        - deque
 * 7. Talk to C                - vector
 */








  // Backups
  vector<int> vec = {2,3,4,5}; 

  cout << vec.capacity() << endl;  

  vec.push_back(6);   











/* 
 * Vector Reallocation:
 * 1. A new memory space of 8 int is allocated (Assume growth factor is 2)
 * 2. A new vector is constructed with {2,3,4,5,6} at the new memory space.
 * 3. The old memory is release.
 */
