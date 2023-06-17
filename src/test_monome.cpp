#include <iostream>
#include "monome.hpp"

/*
int main(){
    std::cout << "Hello World!" << std::endl;

    // definition des Monomes
    Monome P(10,1); // P(X) = 10X
    Monome P1(2,1); // P1(X) = 2X
    Monome Q(2,4); // Q(X) = 2X^4 
    Monome R(-2,0); // R(X) = -2

    // affichage des monomes par méthodes 
    std::cout << " Monome P : " << P.afficher() << std::endl;
    std::cout << " Monome P1 : " << P1.afficher() << std::endl;
    std::cout << " Monome Q : " << Q.afficher() << std::endl;
    std::cout << " Monome R : " << R.afficher() << std::endl;

    // surcharge de l'opérateur ()
    std::cout << " P(4) = " << P(4) << std::endl;
    std::cout << " P1(4) = " << P1(4) << std::endl;
    std::cout << " Q(1) = " << Q(1) << std::endl;
    std::cout << "R(10) = " << R(10) << std::endl;

    // surcharge de l'opérateur == 
    bool tmp = (P == P1);
    std::cout << "P == P1 ? " << tmp << std::endl;

    // surcharge de l'opérateur +
    Monome P2 = P+P1;
    std::cout << " Monome P2 : " << P2.afficher() << std::endl;

    // surcharge de l'opérateur << 
    std::cout << "Monome Q : " <<  Q << std::endl;

    // surcharge de l'opérateur - (pas besoin d'utiliser afficher car on a surcharger << )
    std::cout << "P-P1 : " << P-P1 << std::endl;

    // surcharge de l'opérateur *
    std::cout << "2*P : " << 2*P << std::endl;
    std::cout << "P*2 : " << P*2 << std::endl;
    std::cout << "P*Q : " << P*Q << std::endl;
    return(0);
}
*/