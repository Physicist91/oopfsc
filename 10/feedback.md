# Feedback Sheet 10

* Checkout my version of the code for this exercise sheet on https://gitlab.com/SoilRos/OOPFSC2018-Ospina/tree/master/sheet10.

## Exercise 1:

> 1)Which type of container is suitable for storing the node values?
Vector: it is suitable to store the grid numbers consecutively and can be accessed randomly.

  * Good choice!

> 2)Which type of container is well suited to save the pivot elements and which to store the data itself?
The sequence adaptor std::stack as container (to use the helpful interfaces such as top() and pop()),
and std::pair to store the data itself (the start and end index of a partition). Such an implementation is in quickSort.cpp

* (`-1`) Good choice for the pivots. However, the question about the data was misunderstood. With data, the exercise refers to the values that are being sorted. In your algorithm the are what is contained in the array `double a[]`. For the values it is needed a container that can swap values between two iterators/values of the container. Then, `std::list` or `std::vector` (depending on the case) can perform a good job storing the values. 

> 3)What type of container would you use as a FIFO?
std::queue, because it's the one that fulfills the FIFO requirement.

* Good choice!

> 4)In what container you would store the indices of Dirichlet nodes and their values?
list:it will give access to value node by node and also it free the memory which will make it posibble to use it for big problems.

* (`-2`) No. If you store the data by list, how do you know to which node it belongs to? A `std::map` or `std::unsorted_map` can keep the two values glued thogether.

## Exercise 2:

* Good code in general!

## Points: `17/20`