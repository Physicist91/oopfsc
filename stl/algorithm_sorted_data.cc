



/*
 * Sorted Data Algorithms
 *   - Algorithms that require data being pre-sorted
 *   - Binary search, merge, set operations
 */

// Note: Every sorted data algorithm has a generalized form with a same name.














vector<int> vec = {8,9,9,9,45,87,90};     // 7 items

// 1. Binary Search
// Search Elements
bool found = binary_search(vec.begin(), vec.end(), 9);  // check if 9 is in vec

vector<int> s = {9, 45, 66};
bool found = includes(vec.begin(), vec.end(),     // Range #1
		                s.begin(), s.end());        // Range #2
// Return true if all elements of s is included in vec
// Both vec and s must be sorted      

// Search Position
itr = lower_bound(vec.begin(), vec.end(), 9);  // vec[1]  
// Find the first position where 9 could be inserted and still keep the sorting.

itr = upper_bound(vec.begin(), vec.end(), 9);  // vec[4] 
// Find the last position where 9 could be inserted and still keep the sorting.

pair_of_itr = equal_range(vec.begin(), vec.end(), 9); 
// Returns both first and last position









// 2. Merge
vector<int> vec = {8,9,9,10}; 
vector<int> vec2 = {7,9,10}; 
merge(vec.begin(), vec.end(),      // Input Range #1
		vec2.begin(), vec2.end(),    // input Range #2
		vec_out.begin());               // Output 
      // Both vec and vec2 should be sorted (same for the set operation)
      // Nothing is dropped, all duplicates are kept.
// vec_out: {7,8,9,9,9,10,10}

vector<int> vec = {1,2,3,4,1,2,3,4,5}  // Both part of vec are already sorted 
inplace_merge(vec.begin(), vec.begin()+4, vec.end());  
// vec: {1,1,2,2,3,3,4,4,5}  - One step of merge sort







// 3. Set operations
//    - Both vec and vec3 should be sorted 
//    - The resulted data is also sorted
vector<int> vec = {8,9,9,10}; 
vector<int> vec2 = {7,9,10}; 
vector<int> vec_out[5]; 
set_union(vec.begin(), vec.end(),      // Input Range #1
		    vec2.begin(), vec2.end(),    // input Range #2
		    vec_out.begin());               // Output 
// if X is in both vec and vec2, only one X is kept in vec_out
// vec_out: {7,8,9,9,10}

set_intersection(vec.begin(), vec.end(),      // Input Range #1
		           vec2.begin(), vec2.end(),    // input Range #2
		           vec_out.begin());               // Output 
// Only the items that are in both vec and vec2 are saved in vec_out
// vec_out: {9,10,0,0,0}





vector<int> vec = {8,9,9,10}; 
vector<int> vec2 = {7,9,10}; 
vector<int> vec_out[5]; 
set_difference(vec.begin(), vec.end(),      // Input Range #1
		         vec2.begin(), vec2.end(),    // input Range #2
		         vec_out.begin());               // Output 
// Only the items that are in vec but not in vec2 are saved in vec_out
// vec_out: {8,9,0,0,0}

set_symmetric_difference(vec.begin(), vec.end(),      // Input Range #1
		         vec2.begin(), vec2.end(),       // input Range #2
		         vec_out.begin());               // Output 
// vec_out has items from either vec or vec2, but not from both
// vec_out: {7,8,9,0,0}









/*
 *  Numeric Algorithms (in <numeric>)
 *   - Accumulate, inner product, partial sum, adjacent difference
 */

// 1. Accumulate

int x = accumulate(vec.begin(), vec.end(), 10); 
// 10 + vec[0] + vec[1] + vec[2] + ...

int x = accumulate(vec.begin(), vec.end(), 10, multiplies<int>());
// 10 * vec[0] * vec[1] * vec[2] * ...








// 2. Inner Product
//vector<int> vec = {9,60,70,8,45,87,90};     // 7 items
int x = inner_product(vec.begin(), vec.begin()+3,  // Range #1
		               vec.end()-3,                 // Range #2
				         10);                         // Init Value
// 10 + vec[0]*vec[4] + vec[2]*vec[5] + vec[3]*vec[6]
		
int x = inner_product(vec.begin(), vec.begin()+3,  // Range #1
		                vec.end()-3,                 // Range #2
				          10,                          // Init Value
				          multiplies<int>(),
				          plus<int>());
// 10 * (vec[0]+vec[4]) * (vec[2]+vec[5]) * (vec[3]+vec[6])
              





// 3. Partial Sum
partial_sum(vec.begin(), vec.end(), vec2.begin());
// vec2[0] = vec[0]
// vec2[1] = vec[0] + vec[1];
// vec2[2] = vec[0] + vec[1] + vec[2]; 
// vec2[3] = vec[0] + vec[1] + vec[2] + vec[3]; 
// ...

partial_sum(vec.begin(), vec.end(), vec2.begin(), multiplies<int>());


// 4. Adjacent Difference
adjacent_difference(vec.begin(), vec.end(), vec2.begin());
// vec2[0] = vec[0]
// vec2[1] = vec[1] - vec[0];
// vec2[2] = vec[2] - vec[1]; 
// vec2[3] = vec[3] - vec[2]; 
// ...

adjacent_difference(vec.begin(), vec.end(), vec2.begin(), plus<int>());


