#include <iostream>
#include <armadillo>
#include "ProgrammeLineaire.hpp"

using namespace arma;

int main(int argc, const char * argv[]) {
    
    mat A(1,3); // (m,n)
                // rang(A) = m
    A(0,0) = 1; A(0,1) = 1; A(0,2) = 1;
    vec c(3);
    c(0) = 1; c(1) = 2; c(2) = 3;
    vec b(1);
    b(0) = 8; 

    ProgrammeLineaire pl = ProgrammeLineaire(A, b, c);
    vec v(3);
    v(0) = 1.0; v(1) = 1.0; v(2) = 6.0;
    std::cout << pl.solve(v) << std::endl;
    
    return 0;
}
