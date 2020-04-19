


/*
 * Algorithm Walkthrough: 
 *   Value-changing Algorithm - Changes the element values
 *   copy, move, transform, swap, fill, replace, remove
 */

vector<int> vec = {9,60,70,8,45,87,90};     // 7 items
vector<int> vec2 = {0,0,0,0,0,0,0,0,0,0,0}; // 11 items
vector<int>::iterator itr, itr2;
pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr;











vector<int> vec = {9,60,70,8,45,87,90};     // 7 items
vector<int> vec2 = {0,0,0,0,0,0,0,0,0,0,0}; // 11 items

// 1. Copy
copy(vec.begin(), vec.end(), // Source
	  vec2.begin());          // Destination

copy_if(vec.begin(), vec.end(),      // Source
		  vec2.begin(),                // Destination
		  [](int x){ return x>80;});   // Condition 
// vec2: {87, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0}

copy_n(vec.begin(),  4, vec2.begin());  
// vec2: {9, 60, 70, 8, 0, 0, 0, 0, 0, 0, 0}

copy_backward(vec.begin(),  vec.end(),  // Source
		        vec2.end());              // Destination 
// vec2: {0, 0, 0, 0, 9, 60, 70, 8, 45, 87, 90}






// 2. Move 
vector<string> vec = {"apple", "orange", "pear", "grape"}; // 4 items
vector<string> vec2 = {"", "", "", "", "", ""};            // 6 items

move(vec.begin(), vec.end(), vec2.begin());
// vec:  {"", "", "", ""}  // Undefined
// vec2: {"apple", "orange", "pear", "grape", "", ""};
//
// If move semantics are defined for the element type, elements are moved over, 
// otherwise they are copied over with copy constructor, just like copy().

move_backward(vec.begin(), vec.end(), vec2.end());
// vec2: {"", "", "apple", "orange", "pear", "grape"};









vector<int> vec = {9,60,70,8,45,87,90};     // 7 items
vector<int> vec2 = {9,60,70,8,45,87,90};     // 7 items
vector<int> vec3 = {0,0,0,0,0,0,0,0,0,0,0}; // 11 items

// 3. Transform
transform(vec.begin(), vec.end(),    // Source
		    vec3.begin(),              // Destination
			 [](int x){ return x-1;});  // Operation 

transform(vec.begin(), vec.end(),           // Source #1
          vec2.begin(),                     // Source #2
		    vec3.begin(),                     // Destination
  	       [](int x, int y){ return x+y;});  // Operation
         // Add items from vec and vec2 and save in vec3 
         // vec3[0] = vec[0] + vec2[0]
         // vec3[1] = vec[1] + vec2[1]
         // ...

// 4. Swap - two way copying
swap_ranges(vec.begin(), vec.end(), vec2.begin());









// 5. Fill
vector<int> vec = {0, 0, 0, 0, 0};

fill(vec.begin(), vec.end(), 9); // vec: {9, 9, 9, 9, 9}

fill_n(vec.begin(), 3, 9);       // vec: {9, 9, 9, 0, 0}

generate(vec.begin(), vec.end(), rand); 

generate_n(vec.begin(), 3, rand); 








// 6. Replace
replace(vec.begin(), vec.end(),  // Data Range
		  6,                       // Old value condition
		  9);                      // new value                    

replace_if(vec.begin(), vec.end(),     // Data Range
			  [](int x){return x>80;},    // Old value condition
			  9);                         // new value                    

replace_copy(vec.begin(), vec.end(),  // Source
			  vec2.begin(),              // Destination
			  6,                         // Old value condition
			  9);                        // new value                    
  // Generalized form: replace_copy_if()







// 7. Remove
remove(vec.begin(), vec.end(), 3);   // Remove all 3's
remove_if(vec.begin(), vec.end(), [](int x){return x>80;});  
	 // Remove items bigger than 80

remove_copy(vec.begin(), vec.end(),  // Source
		      vec2.begin(),            // Destination
				6);                      // Condition 
   // Remove all 6's, and copy the remain items to vec2
   // Generalized form: remove_copy_if()

unique(vec.begin(), vec.end());   // Remove consecutive equal elements

unique(vec.begin(), vec.end(), less<int>());   
        // Remove elements whose previous element is less than itself

unique_copy(vec.begin(), vec.end(), vec2.begin());   
// Remove consecutive equal elements, and then copy the uniquified items to vec2
// Generalized form: unique_copy()
	











/*
 * Order-Changing Algorithms:
 *   - reverse, rotate, permute, shuffle 
 *   
 * They changes the order of elements in container, but not necessarily the
 * elements themselves.
 */










vector<int> vec =  {9,60,70,8,45,87,90};     // 7 items
vector<int> vec2 = {0,0,0,0,0,0,0};     // 7 items

// 1. Reverse
reverse(vec.begin()+1, vec.end()-1);
// vec: {9,87,45,8,70,60,90};     // 7 items

reverse_copy(vec.begin()+1, vec.end()-1, vec2.begin());
// vec2: {87,45,8,70,60,0,0};     



// 2. Rotate
rotate(vec.begin(), vec.begin()+3, vec.end());
// vec: {8,45,87,90,9,60,70};     // 7 items

rotate_copy(vec.begin(), vec.begin()+3, vec.end(),  // Source
		 vec2.begin());                               // Destination
       // Copy vec to vec2 in rotated order
       // vec is unchanged









// 3. Permute
next_permutation(vec.begin(), vec.end()); 
                           //Lexicographically next greater permutation
prev_permutation(vec.begin(), vec.end()); 
                           //Lexicographically next smaller permutation
// {1,2,3,5} < {1,2,4,4}
// {1,2}     < {1,2,3}

//Sorted in ascending order:  {8, 9, 45, 60, 70, 87, 90} 
//                            - Lexicographically smallest
//
//Sorted in descending order: {90, 87, 70, 60, 45, 9, 8} 
//                            - Lexicographically greatest

// Generalized form: next_permutation(), prev_permutation()








// 4. Shuffle  
//    - Rearrange the elements randomly 
//      (swap each element with a randomly selected element)
random_shuffle(vec.begin(), vec.end());
random_shuffle(vec.begin(), vec.end(), rand);

// C++ 11
shuffle(vec.begin(), vec.end(), default_random_engine()); 
// Better random number generation










