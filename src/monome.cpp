#include <iostream>
#include <string>
#include "monome.hpp"
#include <bits/stdc++.h> // pour pow

Monome::Monome(int coeff, unsigned int degre)
    :coeff(coeff),degre(degre)
    {}

std::string Monome::afficher() const{
    std::string str = std::to_string(get_coeff());
    if(get_degre() > 0) {
        str += "X^";
        str += std::to_string(get_degre());
    }
    return(str);
}

int Monome::get_coeff() const{
    return(coeff);
}

unsigned int Monome::get_degre() const{
    return(degre);
}

double Monome::operator()(double x) const{
    return( get_coeff()*pow( x, get_degre() ) );
}

bool Monome::operator==(Monome const& X2) const{
    if(get_degre() != X2.get_degre()){
        throw "Comparaison impossible : Monome de degree differents";
    }
    else{
        if(get_coeff() == X2.get_coeff()){
            return(true);
        }
        else{
            return(false);
        }
    }
}

const Monome operator+(Monome const& X1, Monome const& X2){
    if(X1.get_degre() != X2.get_degre()){
        throw "Somme impossible : Monome de degree differents";
    }
    else{
        return( Monome (X1.get_coeff() + X2.get_coeff() , X1.get_degre() ) );
    }
}

const Monome operator-(Monome const& X1, Monome const& X2){
    return(X1 + Monome(- X2.get_coeff(), X2.get_degre()) );
}

bool Monome::operator<(Monome const& X2) const{
    if(get_degre() < X2.get_degre() ){
        return(true);
    }
    else{
        return(false);
    }
}

std::ostream& operator<<(std::ostream& sortie, Monome const& X){
    sortie << X.afficher() ;
    return(sortie);
}

const Monome operator*(int x, Monome const& X){
    return( Monome(x*X.get_coeff(), X.get_degre() ));
}

const Monome operator*(Monome const& X, int x){
    return( x*X );
}

const Monome operator*(Monome const& X1, Monome const& X2){
    return(Monome(X1.get_coeff()*X2.get_coeff(), X1.get_degre() + X2.get_degre()));
}