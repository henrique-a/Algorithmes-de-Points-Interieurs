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
    float solution;

public:
    ProgrammeLineaire(int n, int m);
    vec karmarkar(vec point_initial);
    float solve(vec point_initial, float ro=0.005, int max_interations=50);
    mat getA(void);
    vec getB(void);
    vec getC(void);

};

#endif /* ProgrammeLineaire_hpp */
