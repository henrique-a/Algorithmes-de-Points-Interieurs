#ifndef ProgrammeLineaire_hpp
#define ProgrammeLineaire_hpp

#include <iostream>
#include <armadillo>

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
    vec transformation_test(vec point_initial);
    vec transformation_affine(vec x_0);
    float solve(vec point_initial, float ro=0.005, int max_interations=50);
    mat getA(void);
    vec getB(void);
    vec getC(void);
};

#endif /* ProgrammeLineaire_hpp */
