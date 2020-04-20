# Feedback Sheet 9

* These are some of my learnings debugging your codes and understading why you didn't get the expected boost:

    * Remeber that inline only makes sense when the time to acces a function is comparable to the time it takes to compute the result of the function.

    * Inlining is what really makes your code faster when doing static polymorphisim, not static polymorphisim itself.

    * Most of you used `std::pow()` to compute the polynomial. It's so expensive doing so that computing the function takes much longer than that the time it takes to acces it (without inlining). Therefore, you don't get boost here.

    * The keyword `inline` is almost useless to say the compiler wheter to inline. The compiler usually make a good decision with respect to the size of the code on the function.

    * Inlining is only posible in headers since it is not possible to inline through linked files (process done when one uses `.cpp` or `.cc` files).

    * The keyword `inline` is useful to be sure that the compiler is indeed able to do inling, for example, using `inline` on a `.cpp` or a `.cc` will lead to a compiler error.

    * The size of the vtable (that is, the amount of polyphormic objects you have) does matter. The bigger the longer it takes the lookup of the vpointer. Most of you only implemented one polyphormic object, compilers can detect that and cut out the polymorphism.

* Checkout my version of the code for this exercise sheet on https://gitlab.com/SoilRos/OOPFSC2018-Ospina/tree/master/sheet09.

* Compile that code and checkout differences for each type of polymorphisim, compiler, and type of optimization. For example, for a GNU compiler, with flags `-O3 - match=native` I got the following results:

    * DD = Dynamic Function / Dynamic Rule
    * SD = Static Function / Dynamic Rule
    * SS = Static Function / Static Rule
    * DDI = Dynamic Function / Dynamic Rule (`inline` version) -> senseless because you cannot inline virtual functions 
    * SDI = Static Function / Dynamic Rule (`inline` version)
    * SSI = Static Function / Static Rule (`inline` version)

    | Time test GNU `-O3 -match=native`                       |     DD   |     SD   |     SS   |    SDI   |   SSI    |          |
    |---------------------------------------------------------|---------:|---------:|---------:|---------:|---------:|---------:|   
    | Average composite trapezoidal polynomial time:          | 1.15e+00 | 9.63e-01 | 9.28e-01 | 1.97e+00 | 5.59e-01 | [µs]     |
    | Average composite simpson polynomial time:              | 1.71e+00 | 1.44e+00 | 1.34e+00 | 2.70e+00 | 7.81e-01 | [µs]     |
    | Average (adapt) composite trapezoidal polynomial time:  | 6.23e+01 | 6.50e+01 | 6.48e+01 | 6.22e+01 | 5.41e+01 | [µs]     |
    | Average (adapt) composite simpson polynomial time:      | 3.08e-02 | 3.00e-02 | 1.36e+00 | 4.10e-02 | 4.35e-02 | [µs]     |
    | Average composite trapezoidal sine time:                | 3.34e+00 | 3.28e+00 | 4.59e+00 | 4.75e+00 | 3.12e+00 | [µs]     |
    | Average composite simpson sine time:                    | 4.91e+00 | 5.38e+00 | 7.30e+00 | 5.93e+00 | 5.08e+00 | [µs]     |
    | Average (adapt) composite trapezoidal sine time:        | 1.61e-02 | 3.00e-02 | 4.86e-02 | 2.72e-02 | 2.96e-02 | [µs]     |
    | Average (adapt) composite simpson sine time:            | 4.32e+00 | 4.58e+00 | 4.59e+00 | 4.19e+00 | 3.99e+00 | [µs]     |

    | Speedup w.r.t. StaticStaticInline test                  |  DD/SSI  |   SD/SSI |  SS/SSI  | SDI/SSI  |          |
    |---------------------------------------------------------|---------:|---------:|---------:|---------:|---------:|
    | Average composite trapezoidal polynomial time:          |      205 |      172 |      166 |      353 | [%]      |
    | Average composite simpson polynomial time:              |      219 |      185 |      171 |      346 | [%]      |
    | Average (adapt) composite trapezoidal polynomial time:  |      115 |      120 |      120 |      115 | [%]      |
    | Average (adapt) composite simpson polynomial time:      |       71 |       69 |     3117 |       94 | [%]      |
    | Average composite trapezoidal sine time:                |      107 |      105 |      147 |      152 | [%]      |
    | Average composite simpson sine time:                    |       97 |      106 |      144 |      117 | [%]      |
    | Average (adapt) composite trapezoidal sine time:        |       54 |      101 |      164 |       92 | [%]      |
    | Average (adapt) composite simpson sine time:            |      108 |      115 |      115 |      105 | [%]      |

    * This speedups are huge just because it is repeating the same operation many times, you shouldn't expect speedups like these in real code. Nevertheless, it ilustrates the adventages/drawbacks of static vs dynamic polymorphisim.

    * Notice that in this table, there is only speedups when small functions are the majority of your code.

