#include <vector> 
#include <string>
#include <algorithm>
#include "monome.hpp"
#include "polynome.hpp"

Polynome::Polynome(int coeff, unsigned degre)
    :data(1)
    {
        data[0] = Monome(coeff,degre);
    }

Polynome::Polynome(int coeff[], unsigned degre[], int n)
    :data(n)
    {
        for(int i=0; i < n ; ++i){
            data[i] = Monome(coeff[i], degre[i]);
        }
        std::sort(data.begin(),data.end());
    }

Polynome::Polynome(std::vector<int>& vec_coeff, std::vector<unsigned int>& vec_degre)
    :data(vec_coeff.size())
    {
        for(long long unsigned int i = 0; i < vec_coeff.size() ; ++i){
            data[i] = Monome (vec_coeff[i], vec_degre[i]) ;
        }
        std::sort(data.begin(),data.end());
        simplifie();
    }

Polynome::Polynome(const MonoVec &data0)
    :data{data0}
    {}

int Polynome::size() const{
    return(data.size());
}

Monome Polynome::afficher_monome(int i) const{
    return(data[i]);
}

// la méthode part du principe que le Polynôme est déjà trié !
void Polynome::simplifie(){
    for(MonoVec_It it = data.begin(); it != data.end() ; ++it){
        // on enlève les monomes de coeff 0
        if(it->get_coeff() == 0){
            it = data.erase(it);
        }
        // on regarde s'il y'a deux monomes de même degrés et dans ce cas-là, on les recrée en un seul
        if( (it+1) != data.end() and (it->get_degre() == (it+1)->get_degre()) ){
            *it = (*it) + (*(it+1));
            (it+1) = data.erase((it+1));
        }
    }
}

const Polynome operator+(Polynome const& P, Polynome const& Q){
    std::vector <int> coeff_add;
    std::vector <unsigned int> degre_add;
    for(MonoVec_CIt it = P.data.begin(); it != P.data.end() ; ++it){
        coeff_add.push_back(it->get_coeff());
        degre_add.push_back(it->get_degre());
    }
    for(MonoVec_CIt it = Q.data.begin(); it != Q.data.end() ; ++it){
        coeff_add.push_back(it->get_coeff());
        degre_add.push_back(it->get_degre());
    }
    return( Polynome (coeff_add, degre_add));
}

Monome Polynome::get_monome(long long unsigned int ith_element){
    if(ith_element > data.size()){
        throw "accès impossible : élement hors de la zone du polynôme";
    }
    else{
        return(data[ith_element]);
    }
}

std::ostream& operator<<(std::ostream& sortie,Polynome Q){
    for(int i = 0; i < Q.size() ; ++i){
        if((Q.get_monome(i).get_coeff() > 0 and i > 0)){
            sortie << std::string(" + ") ;
        }
        sortie << Q.get_monome(i);
    }
    return(sortie);
}