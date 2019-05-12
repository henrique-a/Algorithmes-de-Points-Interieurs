#include <iostream>
#include <armadillo>
#include "ProgrammeLineaire.hpp"

using namespace arma;

int main(int argc, const char * argv[]) {
    
    mat A(1,3); // (m,n)
                // rang(A) = m
    A(0,0) = 1; A(0,1) = 1; A(0,2) = 1;
    vec c(3);
    c(0) = -1; c(1) = -2; c(2) = 0;
    vec b(1);
    b(0) = 8; 

    // mat A(2,4); // (m,n)
    //             // rang(A) = m
    // A(0,0) = 2; A(0,1) = 1; A(0,2) = 1; A(0,3) = 0;
    // A(0,0) = 1; A(0,1) = 1; A(0,2) = 0; A(0,3) = 1;

    // vec c(4);
    // c(0) = -8; c(1) = -5; c(2) = 0; c(3) = 0;
    // vec b(2);
    // b(0) = 600; b(1) = 400; 


    ProgrammeLineaire pl = ProgrammeLineaire(A, b, c);
    vec x_0(3);
    x_0(0) = 1.0; x_0(1) = 1.0; x_0(2) = 6.0; 
    pl.transformation_affine(x_0, 0.005, 0.995);    
    return 0;
}
