


/*
 * Reverse Iterator and Iterator 
 */

// Two ways to declare a reverse iterator
reverse_iterator<vector<int>::iterator> ritr;
vector<int>::reverse_iterator ritr;


// Traversing with reverse iterator
vector<int> vec = {4,5,6,7};
reverse_iterator<vector<int>::iterator> ritr;
for (ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
   cout << *ritr << endl;   // prints: 7 6 5 4








vector<int>::iterator itr;
vector<int>::reverse_iterator ritr;

ritr = vector<int>::reverse_iterator(itr);

itr = vector<int>::iterator(ritr);  // Compile Error
itr = ritr.base();  

// C++ Standard: base() returns current iterator
// 












vector<int> vec = {1,2,3,4,5};
vector<int>::reverse_iterator ritr = find(vec.rbegin(), vec.rend(), 3);


cout << (*ritr) << endl;   // 3

vector<int>::iterator itr = ritr.base();  

cout << (*itr) << endl;   // 4 
















vec = {1,2,3,4,5};
ritr = find(vec.rbegin(), vec.rend(), 3);

//Inserting
vec.insert(ritr, 9);         // vec: {1,2,3,9,4,5}
// or
vec.insert(ritr.base(), 9);  // vec: {1,2,3,9,4,5}


vec = {1,2,3,4,5};
ritr = find(vec.rbegin(), vec.rend(), 3);

// Erasing
vec.erase(ritr);    // vec: {1,2,4,5}  
// or
vec.erase(ritr.base());    // vec: {1,2,3,5}  












