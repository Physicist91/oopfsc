**Feedback Sheet 4**

***Exercise 1:***

* This is something I didn't noticed in your past code: Your code is not memory safe. because in several methods (e.g `eralse()`) you create an new `Node` and assign its address to the pointer `temp`, later you set `temp` to point to another addres. At that moment you lose completely the address of the new node you just created leading to a memory leak.

1. Good code and good reasoning. Well done!

2. Good code and good reasoning. Well done!

3. Well done.

4. (`-1`) This code suffer the same problem as you method `erase()`. Please check again you understanding on raw pointers.

***Exercise 2:***

* Here your code suffer the same problem as I pointed before, fortunately, smart pointers are smart enough to understand that they are not needed anymore and get deleted automatically.

1. Good code.

2. Good reasoning.

3. Good code and good reasoning.

***Exercise 3:***

* Good reasoning. Well done!

***Exercise 4:***

* Good reasoning. Well done!

**Points: `19/20`**