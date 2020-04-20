#include <array>
#include <iostream>
#include <iomanip>

#include "test_static_static.hh"
#include "test_static_dynamic.hh"
#include "test_dynamic_dynamic.hh"

int main(int argc, char const *argv[])
{ 
    std::array<double,8> times_static_static, times_static_dynamic, times_dynamic_dynamic;
    std::array<double,8> times_static_static_inline, times_static_dynamic_inline;

    times_dynamic_dynamic       = test_dynamic_dynamic();
    times_static_dynamic        = test_static_dynamic();
    times_static_static         = test_static_static();
    times_static_dynamic_inline = test_static_dynamic_inline();
    times_static_static_inline  = test_static_static_inline();

    std::array<std::array<double,4>,8> times;

    for (int i = 0; i < 8; ++i)
    {
        times[i][0] = times_dynamic_dynamic[i]/times_static_static_inline[i];
        times[i][1] = times_static_dynamic[i]/times_static_static_inline[i];
        times[i][2] = times_static_static[i]/times_static_static_inline[i];
        times[i][3] = times_static_dynamic_inline[i]/times_static_static_inline[i];
    }


    std::cout << std::scientific;
    std::cout << std::setprecision(2);

    std::cout << "*************************************************** Time test ***************************************************" << std::endl;

    std::cout << "                                                      \t" <<  " | " << std::setw(8) << "  DD  " << " | " << std::setw(8) << "  SD  " << " | " << std::setw(8) << "  SS  " << " | " << std::setw(8) << "  SDI  " << " | " << "  SSI  " << std::setw(8) << " |     " << std::endl;
    std::cout << "Average composite trapezoidal polynomial time:\t\t" <<        " | " << std::setw(8) << times_dynamic_dynamic[0] << " | " << std::setw(8) << times_static_dynamic[0] << " | " << std::setw(8) << times_static_static[0] << " | " << std::setw(8) << times_static_dynamic_inline[0] << " | " << std::setw(8) << times_static_static_inline[0] << " | [µs]" << std::endl;
    std::cout << "Average composite simpson polynomial time:\t\t" <<            " | " << std::setw(8) << times_dynamic_dynamic[1] << " | " << std::setw(8) << times_static_dynamic[1] << " | " << std::setw(8) << times_static_static[1] << " | " << std::setw(8) << times_static_dynamic_inline[1] << " | " << std::setw(8) << times_static_static_inline[1] << " | [µs]" << std::endl;
    std::cout << "Average (adapt) composite trapezoidal polynomial time:\t" <<  " | " << std::setw(8) << times_dynamic_dynamic[2] << " | " << std::setw(8) << times_static_dynamic[2] << " | " << std::setw(8) << times_static_static[2] << " | " << std::setw(8) << times_static_dynamic_inline[2] << " | " << std::setw(8) << times_static_static_inline[2] << " | [µs]" << std::endl;
    std::cout << "Average (adapt) composite simpson polynomial time:\t" <<      " | " << std::setw(8) << times_dynamic_dynamic[3] << " | " << std::setw(8) << times_static_dynamic[3] << " | " << std::setw(8) << times_static_static[3] << " | " << std::setw(8) << times_static_dynamic_inline[3] << " | " << std::setw(8) << times_static_static_inline[3] << " | [µs]" << std::endl;
    std::cout << "Average composite trapezoidal sine time:\t\t" <<              " | " << std::setw(8) << times_dynamic_dynamic[4] << " | " << std::setw(8) << times_static_dynamic[4] << " | " << std::setw(8) << times_static_static[4] << " | " << std::setw(8) << times_static_dynamic_inline[4] << " | " << std::setw(8) << times_static_static_inline[4] << " | [µs]" << std::endl;
    std::cout << "Average composite simpson sine time:\t\t\t" <<                " | " << std::setw(8) << times_dynamic_dynamic[5] << " | " << std::setw(8) << times_static_dynamic[5] << " | " << std::setw(8) << times_static_static[5] << " | " << std::setw(8) << times_static_dynamic_inline[5] << " | " << std::setw(8) << times_static_static_inline[5] << " | [µs]" << std::endl;
    std::cout << "Average (adapt) composite trapezoidal sine time:\t" <<        " | " << std::setw(8) << times_dynamic_dynamic[6] << " | " << std::setw(8) << times_static_dynamic[6] << " | " << std::setw(8) << times_static_static[6] << " | " << std::setw(8) << times_static_dynamic_inline[6] << " | " << std::setw(8) << times_static_static_inline[6] << " | [µs]" << std::endl;
    std::cout << "Average (adapt) composite simpson sine time:\t\t" <<          " | " << std::setw(8) << times_dynamic_dynamic[7] << " | " << std::setw(8) << times_static_dynamic[7] << " | " << std::setw(8) << times_static_static[7] << " | " << std::setw(8) << times_static_dynamic_inline[7] << " | " << std::setw(8) << times_static_static_inline[7] << " | [µs]" << std::endl;
    std::cout << std::endl;

    std::cout << std::fixed;
    std::cout << std::setprecision(0);

    std::cout << std::endl;
    std::cout << "************************************ Speedup w.r.t. StaticStaticInline test *************************************" << std::endl;

    std::cout << "                                                      \t" <<  " | " << std::setw(8) << "DD/SSI " << " | " << std::setw(8) << "SD/SSI" << " | " << std::setw(8) << "SS/SSI " << " | " << std::setw(8) << "SDI/SSI " << " |    " << std::endl;
    std::cout << "Average composite trapezoidal polynomial time:\t\t" <<        " | " << std::setw(8) << times[0][0]*100 << " | " << std::setw(8) << times[0][1]*100 << " | " << std::setw(8) << times[0][2]*100 << " | " << std::setw(8) << times[0][3]*100 << " | [%]" << std::endl;
    std::cout << "Average composite simpson polynomial time:\t\t" <<            " | " << std::setw(8) << times[1][0]*100 << " | " << std::setw(8) << times[1][1]*100 << " | " << std::setw(8) << times[1][2]*100 << " | " << std::setw(8) << times[1][3]*100 << " | [%]" << std::endl;
    std::cout << "Average (adapt) composite trapezoidal polynomial time:\t" <<  " | " << std::setw(8) << times[2][0]*100 << " | " << std::setw(8) << times[2][1]*100 << " | " << std::setw(8) << times[2][2]*100 << " | " << std::setw(8) << times[2][3]*100 << " | [%]" << std::endl;
    std::cout << "Average (adapt) composite simpson polynomial time:\t" <<      " | " << std::setw(8) << times[3][0]*100 << " | " << std::setw(8) << times[3][1]*100 << " | " << std::setw(8) << times[3][2]*100 << " | " << std::setw(8) << times[3][3]*100 << " | [%]" << std::endl;
    std::cout << "Average composite trapezoidal sine time:\t\t" <<              " | " << std::setw(8) << times[4][0]*100 << " | " << std::setw(8) << times[4][1]*100 << " | " << std::setw(8) << times[4][2]*100 << " | " << std::setw(8) << times[4][3]*100 << " | [%]" << std::endl;
    std::cout << "Average composite simpson sine time:\t\t\t" <<                " | " << std::setw(8) << times[5][0]*100 << " | " << std::setw(8) << times[5][1]*100 << " | " << std::setw(8) << times[5][2]*100 << " | " << std::setw(8) << times[5][3]*100 << " | [%]" << std::endl;
    std::cout << "Average (adapt) composite trapezoidal sine time:\t" <<        " | " << std::setw(8) << times[6][0]*100 << " | " << std::setw(8) << times[6][1]*100 << " | " << std::setw(8) << times[6][2]*100 << " | " << std::setw(8) << times[6][3]*100 << " | [%]" << std::endl;
    std::cout << "Average (adapt) composite simpson sine time:\t\t" <<          " | " << std::setw(8) << times[7][0]*100 << " | " << std::setw(8) << times[7][1]*100 << " | " << std::setw(8) << times[7][2]*100 << " | " << std::setw(8) << times[7][3]*100 << " | [%]" << std::endl;
    std::cout << std::endl;

    return 0;
}