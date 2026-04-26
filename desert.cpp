#include "desert.h"
#include "exceptii.h"
#include <iostream>
//constructori
desert::desert(): produse(),aroma(""),indulcitor(false), calorii(0){};
desert::desert(const std::string& nume, int gramaj, float pret, const std::string& aroma, bool indulcitor, int calorii):
        produse(nume, pret, gramaj), aroma(aroma), indulcitor(indulcitor), calorii(calorii){
            if(calorii<=0) throw intInvalid();}
desert::desert(const desert& d): produse(d), aroma(d.aroma), indulcitor(d.indulcitor), calorii(d.calorii){}

//geter si functii:
float desert::getPret() const { return pret+0.75; }
int desert::timpPreparare() const{ if(indulcitor) return 20; else return 10;}

//operatorii:
desert& desert::operator=(const desert& d){
    if(this != &d){
        produse::operator=(d);
        aroma = d.aroma;
        indulcitor = d.indulcitor;
        calorii = d.calorii;}
    return *this;}

//citire
void desert::citire(std::istream& is){
    bool tastatura = (&is == &std::cin);
    if (tastatura) std::cout<<"aroma = ";
    is >> aroma;
    if (tastatura) std::cout<<"are zahar? 0(nu) 1(da) = ";
    is>> indulcitor;
    if (tastatura) std::cout<<"calorii = ";
    if(!(is>>calorii) || calorii<0) throw intInvalid();}

//afisare
void desert::afisare(std::ostream& os) const{
    os<<"aroma: "<<aroma;
    if(indulcitor) os<<" | nu are zahar | ";
    else os<<" | are zahar | ";
    os<<"calorii: "<< calorii;}











