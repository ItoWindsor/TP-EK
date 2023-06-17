#ifndef _POLYNOME_HPP_
#define _POLYNOME_HPP_

#include <vector> 
#include <string>
#include "monome.hpp"

using MonoVec = std::vector <Monome>; // on voit le polynôme comme un vecteur de monôme
using MonoVec_It = std::vector <Monome>::iterator;
using MonoVec_CIt = std::vector <Monome>::const_iterator;
// pas utilisé de typedef car using marche mieux si on passe à des templates (apparemment)

class Polynome{
    public:
        Polynome(int coeff = 0, unsigned degre = 0); // constructeur de base
        Polynome(int coeff[], unsigned degre[], int n); 
        Polynome(std::vector<int>& vec_coeff, std::vector<unsigned int>& vec_degre);
        Polynome(const MonoVec &data0); 

        Monome afficher_monome(int i) const;
        void simplifie();
        int size() const;

        double operator()(double x) const; // surcharge interne
        bool operator==(Polynome const& Q) const; // surcharge interne
        bool operator<(Polynome const& Q) const; // surcharge interne
        friend const Polynome operator+(Polynome const& P, Polynome const& Q); // surcharge externe 

        Monome get_monome(long long unsigned int ith_element);
        
    private:
        MonoVec data;

};


const Polynome operator-(Polynome const& P, Polynome const& Q); // surcharge externe
std::ostream& operator<<(std::ostream& sortie, Polynome const Q); // surcharge externe 

#endif