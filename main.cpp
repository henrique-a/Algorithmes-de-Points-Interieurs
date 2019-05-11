#include <iostream>
#include <armadillo>
#include "ProgrammeLineaire.hpp"

using namespace arma;


int main(int argc, const char * argv[]) {
    
    ProgrammeLineaire pl = ProgrammeLineaire(5,5);

    std::cout << pl.getA().t() << std::endl;
    
    return 0;
}
