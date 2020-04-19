

/*
 * STL Algorithm Walkthrough: 
 *     Non-modifying Algorithms
 *     count, min and max, compare, linear search, attribute 
 */


// C++ 11 Lambda Function:
num = count_if(vec.begin(), vec.end(), [](int x){return x<10;});  

bool lessThan10(int x) {
   return x<10;
}

vector<int> vec = {9,60,90,8,45,87,90,69,69,55,7};
vector<int> vec2 = {9,60,70,8,45,87};
vector<int>::iterator itr, itr2;
pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr;

// C++ 03: some algorithms can be found in tr1 or boost





vector<int> vec = {9,60,90,8,45,87,90,69,69,55,7};

// 1. Counting
//     Algorithm   Data              Operation
int n = count(vec.begin()+2, vec.end()-1, 69);   // 2
int m = count_if(vec.begin(), vec.end(), [](int x){return x==69;}); // 3  
int m = count_if(vec.begin(), vec.end(), [](int x){return x<10;}); // 3  

// 2.  Min and Max
itr = max_element(vec.begin()+2, vec.end());  // 90
// It returns the first max value
itr = max_element(vec.begin(), vec.end(), 
                  [](int x, int y){ return (x%10)<(y%10);}); // 9 
														 
// Most algorithms have a simple form and a generalized form

itr = min_element(vec.begin(), vec.end());  // 7 
// Generalized form: min_element()

pair_of_itr = minmax_element(vec.begin(), vec.end(),  // {60, 69} 
		                      [](int x, int y){ return (x%10)<(y%10);}); 
// returns a pair, which contains first of min and last of max






// 3. Linear Searching (used when data is not sorted)
//    Returns the first match
itr = find(vec.begin(), vec.end(), 55);

itr = find_if(vec.begin(), vec.end(), [](int x){ return x>80; });

itr = find_if_not(vec.begin(), vec.end(), [](int x){ return x>80; });

itr = search_n(vec.begin(), vec.end(), 2, 69);  // Consecutive 2 items of 69
// Generalized form: search_n()

// Search subrange
vector<int> sub = {45, 87, 90};
itr = search( vec.begin(), vec.end(), sub.begin(), sub.end()); 
      // search first subrange 
itr = find_end( vec.begin(), vec.end(), sub.begin(), sub.end());
      // search last subrange 
// Generalized form: search(), find_end()






// Search any_of
vector<int> items  = {87, 69};
itr = find_first_of(vec.begin(), vec.end(), items.begin(), items.end()); 
      // Search any one of the item in items
itr = find_first_of(vec.begin(), vec.end(), items.begin(), items.end(),
		              [](int x, int y) { return x==y*4;}); 
      // Search any one of the item in items that satisfy: x==y*4;

// Search Adjacent
itr = adjacent_find(vec.begin(), vec.end());  // find two adjacent items that 
                                              // are same
itr = adjacent_find(vec.begin(), vec.end(), [](int x, int y){ return x==y*4;}); 
	     // find two adjacent items that satisfy: x==y*4;












// 4. Comparing Ranges
if (equal(vec.begin(), vec.end(), vec2.begin())) {
  cout << "vec and vec2 are same.\n";	
}

if (is_permutation(vec.begin(), vec.end(), vec2.begin())) {
	cout << "vec and vec2 have same items, but in differenct order.\n";	
}

pair_of_itr = mismatch(vec.begin(), vec.end(), vec2.begin());  
// find first difference
// pair_of_itr.first is an iterator of vec 
// pair_of_itr.second is an iterator of vec2

//Lexicographical Comparison: one-by-one comparison with "less than"
lexicographical_compare(vec.begin(), vec.end(), vec2.begin(), vec2.end());
// {1,2,3,5} < {1,2,4,5}
// {1,2}     < {1,2,3}

// Generalized forms: 
//   equal(), is_permutation(), mismatch(), lexicographical_compare()






// 5. Check Attributes
is_sorted(vec.begin(), vec.end());  // Check if vec is sorted

itr = is_sorted_until(vec.begin(), vec.end()); 
// itr points to first place to where elements are no longer sorted
// Generalized forms: is_sorted(), is_sorted_until()

is_partitioned(vec.begin(), vec.end(), [](int x){return x>80;} );
			// Check if vec is partitioned according to the condition of (x>80)

is_heap(vec.begin(), vec.end());  // Check if vec is a heap
itr = is_heap_until(vec.begin(), vec.end());  // find the first place where it 
                                              // is no longer a heap
// Generalized forms: is_heap(), is_heap_until()








// All, any, none
all_of(vec.begin(), vec.end(), [](int x) {return x>80} );  
// If all of vec is bigger than 80 

any_of(vec.begin(), vec.end(), [](int x) {return x>80} );  
// If any of vec is bigger than 80 

none_of(vec.begin(), vec.end(), [](int x) {return x>80} );  
// If none of vec is bigger than 80 


