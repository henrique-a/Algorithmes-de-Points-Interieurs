#ifndef ProgrammeLineaire_hpp
#define ProgrammeLineaire_hpp

#include <iostream>
#include <armadillo>
#include <cstdlib>

using namespace std;
using namespace arma;

class ProgrammeLineaire{
private:
    int n, m;
    mat A;
    vec b;
    vec c;

public:
    ProgrammeLineaire(mat A, vec b, vec c);
    vec transformation_affine(vec x_0, float episilon, float gamma);
    mat getA(void);
    vec getB(void);
    vec getC(void);
};

#endif /* ProgrammeLineaire_hpp */
