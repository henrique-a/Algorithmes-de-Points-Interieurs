#include "ProgrammeLineaire.hpp"
#include <armadillo>

ProgrammeLineaire::ProgrammeLineaire(int n, int m){
    A = randu<mat>(n,m);
    b = randu<vec>(m);
    c = randu<vec>(n);
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

vec ProgrammeLineaire::karmarkar(vec point_initial){
    mat D = diagmat(point_initial);
    vec c_tilde = c*D;
    mat A_tilde = A*D;
    mat A_tildeT = A_tilde.t();
    mat AAT_inv = (A_tilde * A_tildeT).i();
    mat P = eye<mat>(m,m) - (A_tildeT*AAT_inv)*A_tilde;
    vec cp_tilde = c_tilde*P;
    float k = -0.5 / cp_tilde.min();
    vec x_tilde_new = ones<vec>(m) + k*cp_tilde;
    return x_tilde_new*D; 
}

float ProgrammeLineaire::solve(vec point_initial, float ro, int max_interations){
    vec x = point_initial;
    for(int i = 0; i < max_interations; i++){
        vec x_new = karmarkar(x);
        float dist = norm(x - x_new);
        x = x_new; 
        if (dist < ro) {
            break;
        }
    }
    return solution;
}
