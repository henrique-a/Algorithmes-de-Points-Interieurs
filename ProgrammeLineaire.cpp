#include "ProgrammeLineaire.hpp"
#include <armadillo>

ProgrammeLineaire::ProgrammeLineaire(int n, int m){
    A = randu<mat>(n,m);
    b = randu<vec>(m);
    c = randu<vec>(n);
}

void ProgrammeLineaire::karmarkar(vec point_initial){
    for(int i = 0; i < 50; i++){
        
    }
}

mat ProgrammeLineaire::getA(void){
    return A;
}

vec ProgrammeLineaire::getB(void){
    return b;
}

vec ProgrammeLineaire::getC(void){
    return c;
}
