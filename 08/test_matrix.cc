#include <iostream>
#include <complex>
#include "matrix.h"
#include "rational.h"

template<class T>
void test_matrix_vector(int size = 5)
{
    std::cout << "************** Testing matrix-vector operations **************" << std::endl;
    std::cout << "T = " << typeid(T).name() << std::endl;
    Matrix<T> A(0);

    A.resize(size,size,T(0.));

    for (int i = 0; i < A.rows(); ++i)  
        A(i,i) = T(2.);
    for (int i = 0; i < A.rows()-1; ++i) 
        A(i+1,i) = A(i,i+1) = T(-1.);

    std::cout << "A" << std::endl;
    A.print();

    // define vector b
    std::vector<T> b(size);
    for (int i = 0; i < size/2; ++i)
    {
        if (i%2==0)
            b[i] = b[size-i-1] = T(5.);  
        else
            b[i] = b[size-i-1] = T(-4.);
    }
    b[size/2] = T(4.);

    std::cout << "b = ( ";
    for (size_t i = 0; i < b.size(); ++i)
        std::cout << b[i] << "  ";
    std::cout << ")" << std::endl;
    std::cout << std::endl;

    std::vector<T> x = A * b;

    std::cout << "A*b = ( ";
    for (size_t i = 0; i < x.size(); ++i)
        std::cout << x[i] << "  ";
    std::cout << ")" << std::endl;
    std::cout << std::endl;
    // 
    // 
    // 
    // 
    // solve
    x = A.solve(b);
    std::cout << "The solution with the ordinary Gauss Elimination is: ( ";
    for (size_t i = 0; i < x.size(); ++i)
        std::cout << x[i] << "  ";
    std::cout << ")" << std::endl;








    // const Matrix<std::complex<double>> D(A);
    // std::cout << "Element 1,1 of D is " << D(1,1) << std::endl;
    // std::cout << std::endl;
    // A.resize(5,5,0.);
    // for (int i = 0; i < A.rows(); ++i)  
    //     A(i,i) = 2.;
    // for (int i = 0; i < A.rows()-1; ++i) 
    //     A(i+1,i) = A(i,i+1) = -1.;
    // // define vector b
    // std::vector<std::complex<double>> b(5);
    // b[0] = b[4] = 5.;
    // b[1] = b[3] = -4.;
    // b[2] = 4.;
    // std::vector<std::complex<double>>x = A * b;
    // std::cout << "A*b = ( ";
    // for (size_t i = 0; i < x.size(); ++i)
    //     std::cout << x[i] << "  ";
    // std::cout << ")" << std::endl;
    // std::cout << std::endl;
    // // solve
    // x = A.solve(b);
    // A.print();
    // std::cout << "The solution with the ordinary Gauss Elimination is: ( ";
    // for (size_t i = 0; i < x.size(); ++i)
    //     std::cout << x[i] << "  ";
    // std::cout << ")" << std::endl;
}


template<class T1, class T2 = T1>
void test_matrix(int size_1 = 4, int size_2 = 6)
{
    std::cout << "************** Testing matrix-matrix operations **************" << std::endl;
    std::cout << "T1 = " << typeid(T1).name() << std::endl;
    std::cout << "T2 = " << typeid(T2).name() << std::endl;

    // define matrix
    Matrix<T1> A(size_1,size_2,T1(0.));
    for (int i = 0; i < A.rows(); ++i)  
        A[i][i] = T1(2.);
    for (int i=0; i < A.rows()-1; ++i) 
        A[i+1][i] = A[i][i+1] = T1(-1.);

    Matrix<T2> B(size_2,size_1,T2(0.));
    for (int i = 0; i <B.cols(); ++i)  
        B[i][i] = T2(2.);
    for (int i = 0; i < B.cols()-1; ++i) 
        B[i+1][i] = B[i][i+1] = T2(-1.);

    // print matrix
    std::cout << "A" << std::endl;
    A.print();
    std::cout << "B" << std::endl;
    B.print();

    std::cout << "C = A" << std::endl;
    Matrix<T1> C(A);

    A = T1(2.) * C;
    std::cout << "A = T1(2.) * C" << std::endl;
    A.print();

    std::cout << "A = C * T1(2.)" << std::endl;
    A = C * T1(2.);
    A.print();

    std::cout << "D = B" << std::endl;
    Matrix<T2> D(B);

    B = T2(2.) * D;
    std::cout << "B = D * T2(2.) " << std::endl;
    B.print();

    B = D * T2(2.);
    std::cout << "B = T2(2.) * D" << std::endl;
    B.print();

    if constexpr (not std::is_same<T1,T2>::value)
    {
        std::cout << "T2(2.) * A" << std::endl;
        auto E = T2(2.) * A;
        E.print();

        std::cout << "A * T2(2.)" << std::endl;
        auto F = A * T2(2.);
        F.print();

        std::cout << "T1(2.) * B" << std::endl;
        auto G = T1(2.) * B;
        G.print();

        std::cout << "B * T1(2.)" << std::endl;
        auto H = B * T1(2.);
        H.print();
    }

    if (size_1 == size_2)
    {
        std::cout << "A + B" << std::endl;
        auto E = A + B;
        E.print();
    }

    std::cout << "A = C + A" << std::endl;
    A = C + A;
    A.print();

    std::cout << "B = D + B" << std::endl;
    B = D + B;
    B.print();

    const Matrix<T1> E(A);
    std::cout << "Element 1,1 of E is " << E(1,1) << std::endl;
    std::cout << std::endl;

    test_matrix_vector<T1>(size_1);
    test_matrix_vector<T2>(size_1);
}



int main(int argc, const char *argv[]) 
{
    test_matrix<std::complex<double>,double>(3,3);
    test_matrix<std::complex<int>,int>(3,3);
    test_matrix<double,int>(3,3);
    test_matrix<double,unsigned int>(3,3);
    test_matrix<double,unsigned int>(3,3);
    test_matrix<Rational,int>(5,5);
}
