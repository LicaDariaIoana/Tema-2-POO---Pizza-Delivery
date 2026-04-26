#include "produse.h"
#include "exceptii.h"
#include <iostream>
produse::produse():nume(""), gramaj(0),pret(0){}
produse::produse(const std::string& nume, int gramaj, float pret)
    :nume(nume), gramaj(gramaj), pret(pret){
    if(pret<=0) throw intInvalid();
    if(gramaj<=0)throw intInvalid();}
produse::produse(const produse& p)
    :nume(p.nume), gramaj(p.gramaj), pret(p.pret){}


//citire
void produse::citire(std::istream& is) {}
std::istream& operator>>(std::istream& is, produse& p){
    bool tastatura = (&is == &std::cin);

    if(tastatura) std::cout<<"nume = ";
    is>>p.nume;

    if(tastatura) std::cout<<"gramaj = ";
    if(!(is>>p.gramaj) || p.gramaj<=0)
        throw intInvalid();

    if(tastatura) std::cout<<"pret = ";
    if(!(is>>p.pret) || p.pret<=0)
        throw intInvalid();

    p.citire(is);
    return is;}

//afisare
void produse::afisare(std::ostream& os) const {}
std::ostream& operator<<(std::ostream& os, const produse& p){
    os<<"Nume: "<<p.nume<<" | gramaj: "<<p.gramaj<<" grame | pret: "<<p.pret<<" lei | ";
    p.afisare(os);
    return os;}

//functia operator =
produse& produse::operator=(const produse& p){
    if(this != &p){
        nume = p.nume;
        pret = p.pret;
        gramaj = p.gramaj;}
    return *this;}


//functii:
float produse::getPret() const {return pret;}
std::string produse::getNume() const{return nume;};
















