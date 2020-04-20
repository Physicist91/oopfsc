**Feedback Sheet 6**

***Exercise 1:***

>Calling ~Foo will throw another exception, but this will again invoke the destructor of Foo.


This is not true. Once the destructor is called, the object do not exist anymore, therefore, a second call of the destructor is not possible.

>This is sensible because otherwise the stack will unwind in an infinite loop.

Since your argument about destructor invocation is not true, this one is also not true.

* (`-1`) Your answer do not explain program behavior correctly. 
    The main reason for abortion is because when `b` is created it thows an exception, then, it starts the *stack unwinding* trying to destroy all objects created so far in order to handle the exception. In this case it destroys `f` which throws another exception. Since the program cannot manage an exception while it is doing *stack unwinding*, the it aborts the execution.

* (`-2`) Your answer do not explain why the note on *Section 15.2, point 3 of the C++ standard* is sensible.
    It is sensible because it means that **an object cannot fail in its destruction**, or at least if it fails, it must be recoverd in place do not throwing an exception outside of the destruction call.

***Exercise 2:***

* (`-2`) Regarding the return value of the method `what()` When returning *pointers* of *references* **DO NOT** return local variables!! Values stored in these variables will only contain what you want until the program decides to overrite it. Therefore, in this case, you have to store the message in your object.

* When catching exceptions that you cannot handle (e.g. only printing the message in `what()`) it is useful to catch them as references of the base class, that way we can use its polyphormic properties.

```c++
try {throw some_derived_class_from_std_exception();} 
catch (std::exception& e) 
{std::cout << e.what()<< std::endl;} // polyphormic call of what()
```

***Exercise 3:***

* Good reasoning. Good code.

**Points: `15/20`**

