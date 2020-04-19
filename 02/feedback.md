**Feedback Sheet 2**

***Excersice 1:***

* Very good code. You did interesting optimization to avoid overflow. And it's sign safe. 

* I get the following warning while compiling:
```bash
Santiagos-MacBook-Air:exercise1 soilros$ g++-7 -std=c++17 -Wall -Og -g -o program *.cc *.cpp
main.cc: In function 'int main()':
main.cc:7:12: warning: variable 'f3' set but not used [-Wunused-but-set-variable]
   Rational f3 = Rational(0,1);
            ^~
```

***Excersice 2:***

* Very good and clean code.

* If you want to avoid copying code bewteen folders, you can try to use `makefiles`, `CMake`, or simply `symlink`s.

**Points: `20/20`**