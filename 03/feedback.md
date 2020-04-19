**Feedback Sheet 3**

***Excersice 1:***

* `-1/2` All ansewers are correct but the third and the seventh ones, they are correct statements. Of course the programer have to be aware that they are memory addresses operations.

***Excersice 2:***

* `-2` You didn't answer all questions. The one you addressed is correct though. Here the answers:

* `...cleaning up all objects of class C.`: No => Each object has its own destructor, therefore, they are destroied one by one.

* `...cleaning up objects of class C on the heap`: No/Partially yes => Only if the destructor calls the method `delete` for pointers that are contained in C.

* `...cleaning up all components of objects of class C`: Partially yes => All member variables of object C get destroied, nontheless, if there was memory on the heap associated to the object C by a pointer, the pointer is destroied, not the memory on the heap. It also is not in charge of deleting static member functions.

* `...cleaning up components of objects of the class C that are on the heap`: No/Partially yes => Default destructors do not manage memory on the heap at all. The user is in charge to clean up memory on the heap (maybe with spart pointers), usually in the destructor.

* ` delete is just a special way of calling the destructor: let x be of type C*, then delete x; is the same as (*x).~C()`: No/Partially yes => calling de destructor of `x` is only a part of the job of delete, it also releases memory on the heap where `x` was saved such that other programs can use that part of memory again. 

***Excersice 3:***

* Good reasoning.

***Excersice 4:***

* `-4.5` In general is a good code, nevertheless, it is not memory safe. Notice that in the destructor you are only deleting head and tail. What happens with the other nodes? You had to loop over the whole list and delete each node one by one. You implementation for `erase()` is akward and quite error prone because the multiple allocation and deallocation of nodes. 

* I hope you this is enough encouragement to learn more about memory managment and how smart pointers can help you to avoid such problems.

**Points: `13/20`**