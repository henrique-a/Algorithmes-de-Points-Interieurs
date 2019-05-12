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

vec ProgrammeLineaire::transformation_test(vec point_initial){
    int n = A.n_cols;
    mat D = diagmat(point_initial); // Matrice de transformation affine
    std::cout << "D: " << std::endl << D << std::endl;
    vec c_tilde = D*c;
    std::cout << "c_tilde: "<< std::endl << c_tilde << std::endl;
    mat A_tilde = A*D;
    std::cout << "A_tilde: "<< std::endl << A_tilde << std::endl;
    mat A_tildeT = A_tilde.t();
    std::cout << "A_tildeT: "<< std::endl << A_tildeT << std::endl;
    mat AAT_inv = inv(A_tilde * A_tildeT);
    std::cout << "AAT_inv: "<< std::endl << AAT_inv << std::endl;
    mat P = eye<mat>(n,n) - (A_tildeT*AAT_inv)*A_tilde;
    std::cout << "P: "<< std::endl << std::endl << P << std::endl;
    vec cp_tilde = P*c_tilde; // projection de c_tilde
    std::cout << "cp_tilde: "<< std::endl << cp_tilde << std::endl;    
    float k = -0.5 / cp_tilde.min();
    vec x_tilde_new = ones<vec>(n) + k*cp_tilde;
    std::cout << "x_tilde_new: "<< std::endl << x_tilde_new << std::endl;
    std::cout << "solution: "<< std::endl << D*x_tilde_new << std::endl;
    return D*x_tilde_new; 
}

float ProgrammeLineaire::solve(vec point_initial, float ro, int max_interations){
    vec x = point_initial;
    for(int i = 0; i < max_interations; i++){
        vec x_new = transformation_affine(x);
        float dist = norm(x - x_new);
        x = x_new; 
        if (dist < ro) {
            break;
        }
    }
    return dot(c.t(),x);
}


vec ProgrammeLineaire::transformation_affine(vec x_0, float episilon){
    vec x_c = x_0
    float deta_c = episilon*(c.t()*)
    float gamma = 0.995;
    int n = A.n_cols;
    mat D = diagmat(x_0); // Matrice de transformation affine
//    std::cout << "D: " << std::endl << D << std::endl;
    
    mat P = -D*(eye(n,n) - D*A.t() * pinv(A*(D*D)*A.t()) * A*D)*D;
  //  std::cout << "P: " << std::endl << P << std::endl;
    vec delta_x = P*c;
    //std::cout << "detal_x: " << std::endl << delta_x << std::endl;
    vec K = -x_0 / delta_x;
    //std::cout << "K: " << std::endl << K << std::endl;
    // enleve les negatives
    for (int i = 0; i < K.n_elem; i++) {
        if (K(i) < 0) {
            K(i) = datum::inf;
        }
    }
    //std::cout << "K: " << std::endl << K << std::endl;

    float alpha = gamma * K.min();
    //std::cout << "alpha: " << std::endl << alpha << std::endl;
    vec x_new = x_0 + alpha*delta_x;
    std::cout << "solution: " << std::endl << x_new << std::endl;
    return x_new;
}
