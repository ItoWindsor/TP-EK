#include <iostream>
#include "polynome.hpp"

int main(){

    // test constructeur
    int coeff[] = { 2, -1, 4, 0, 2, 6 }; 
    unsigned degre [] = { 0, 3, 2, 5, 6, 2 };
    Polynome P(coeff , degre , 6);

    for(int i= 0; i < P.size() ; ++i){
        std::cout << P.afficher_monome(i) << " " ;
    }
    std::cout << std::endl;

    std::cout << "simplification de : P" << std::endl;
    P.simplifie();

    for(int i= 0; i < P.size() ; ++i){
        std::cout << P.afficher_monome(i) << " " ;
    }
    std::cout << std::endl;

    // test surcharge de l'opérateur + 
    Polynome Q = P+P;
    std::cout << "Polynome Q = P+P : " ;
    for(int i= 0; i < Q.size() ; ++i){
        std::cout << Q.afficher_monome(i) << " " ;
    }
    std::cout << std::endl;

    // test surcharge de l'opérateur //
    std::cout << "P = " << P << std::endl;
    return(0);
}