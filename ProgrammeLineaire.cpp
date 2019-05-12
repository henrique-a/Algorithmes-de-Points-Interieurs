#include "ProgrammeLineaire.hpp"
#include <armadillo>

ProgrammeLineaire::ProgrammeLineaire(mat A, vec b, vec c){
    this->A = A;
    this->b = b;
    this->c = c;
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

vec ProgrammeLineaire::transformation_affine(vec x_0, float episilon, float gamma){
    vec x = x_0;
    float delta_c = abs(episilon*dot(c, x)) + 1;
    std::cout << "delta_c: " << std::endl << delta_c << std::endl;
    std::cout << "no while: " << std::endl << delta_c / dot(c, x) << std::endl;

    int n = A.n_cols;
    while (abs(delta_c / dot(c, x)) > episilon) { // delta_c / dot(c, x) = episilon + 1 / c.x
        mat D = diagmat(x); // Matrice de transformation affine (matrice diagonal)
        //std::cout << "D: " << std::endl << D << std::endl;
        // matrice de projection
        mat P = -D*(eye(n,n) - D*A.t() * inv(A*(D*D)*A.t()) * A*D)*D;
        //std::cout << "P: " << std::endl << P << std::endl;
        vec delta_x = P*c;
        //std::cout << "detal_x: " << std::endl << delta_x << std::endl;
        vec K = -x / delta_x;
        //std::cout << "K: " << std::endl << K << std::endl;
        // enleve les negatives
        for (int i = 0; i < K.n_elem; i++) {
            if (K(i) < 0) {
                K(i) = datum::inf;
            }
        }
        float alpha = gamma * K.min();
        //std::cout << "alpha: " << std::endl << alpha << std::endl;
        vec x_new = x + alpha*delta_x;
        std::cout << "solution: " << std::endl << x_new << std::endl;
        std::cout << "objective: " << std::endl << dot(c, x_new) << std::endl;
        delta_c = abs(dot(c, (x - x_new)));
        x = x_new;
    } 
    return x;   
}
