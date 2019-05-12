#include <iostream>
#include <armadillo>
#include "ProgrammeLineaire.hpp"

using namespace arma;

int main(int argc, const char * argv[]) {
    
    // mat A(1,3); // (m,n)
    //             // rang(A) = m
    // A(0,0) = 1; A(0,1) = 1; A(0,2) = 1;
    // vec c(3);
    // c(0) = 1; c(1) = 2; c(2) = 0;
    // vec b(1);
    // b(0) = 8; 

    mat A(2,4); // (m,n)
                // rang(A) = m
    A(0,0) = 2; A(0,1) = 1; A(0,2) = 1; A(0,3) = 0;
    A(0,0) = 1; A(0,1) = 1; A(0,2) = 0; A(0,3) = 1;

    vec c(4);
    c(0) = -8; c(1) = -5; c(2) = 0; c(3) = 0;
    vec b(2);
    b(0) = 600; b(1) = 400; 


    ProgrammeLineaire pl = ProgrammeLineaire(A, b, c);
    vec v(4);
    v(0) = 50.0; v(1) = 100.0; v(2) = 400.0; v(3) = 250.0; 
    std::cout << pl.solve(v, 0.005, 1000) << std::endl;
    
    return 0;
}
