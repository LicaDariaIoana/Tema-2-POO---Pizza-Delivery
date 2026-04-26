#include "bauturi.h"
#include <iostream>
//constructori
bauturi::bauturi(): produse(),ambalaj(""), alcool(false){};

bauturi::bauturi( const std::string& nume,float pret, int gramaj, const std::string& ambalaj, bool alcool):
        produse(nume, pret, gramaj), ambalaj(ambalaj), alcool(alcool){}
bauturi::bauturi(const bauturi& b): produse(b), ambalaj(b.ambalaj), alcool(b.alcool){}

std::string bauturi::getNume() const{return nume;}

//operatorii:
bauturi& bauturi::operator=(const bauturi& b){
    if(this != &b){
        produse::operator=(b);
        ambalaj = b.ambalaj;
        alcool = b.alcool;}
    return *this;}

//citire
void bauturi::citire(std::istream& is){
    bool tastatura = (&is == &std::cin);
    if (tastatura) std::cout<<"ambalaj = ";
    is>>ambalaj;
    if (tastatura) std::cout<<"are alcool? 0(nu) 1(da) = ";
    is>>alcool;}

//afisare
void bauturi::afisare(std::ostream& os) const{
    os<<" ambalaj de "<<ambalaj;
    if(alcool) os<<" | are alcool";
    else os<<" | nu are alcool";}

//functii
float bauturi::getPret()const{ return pret+0.5;}
float bauturi::getAlcool()const{return alcool;};
int bauturi::timpPreparare()const{
    if (alcool) return 5;
    else return 2;}















