#include "pizza.h"
#include "exceptii.h"
#include <iostream>
//constructorii
pizza::pizza():produse(),toppinguri(), blat(""), calorii(0){}

pizza::pizza(const std::string& nume, int gramaj, float pret, const std::vector<std::string>& toppinguri,
             const std::string& blat, int calorii):produse(nume, gramaj, pret),toppinguri(toppinguri),
blat(blat), calorii(calorii){
                 if(calorii<=0) throw intInvalid();}

pizza::pizza(const pizza& p): produse(p), toppinguri(p.toppinguri),blat(p.blat), calorii(p.calorii){}

//operatori
pizza& pizza::operator=(const pizza& p){
    if(this != &p){
        produse::operator=(p);
        toppinguri= p.toppinguri;
        blat = p.blat;
        calorii = p.calorii;}
    return *this;}

//citire
void pizza::citire(std::istream& is){
    bool tastatura = (&is == &std::cin);
    // citirea toppingurilor
    int n;
    if (tastatura) std::cout<<"cate toppinguri?";
    if(!(is>>n) || n<0) throw intInvalid();
    if (tastatura) std::cout<<"toppinguri = ";
    toppinguri.clear();
    for (int i = 0; i<n; i++){
        std::string t;
        is>>t;
        toppinguri.push_back(t);}
    if (tastatura) std::cout<<"tip blat = ";
    is>>blat;
    if (tastatura) std::cout<<"calorii = ";
    if(!(is>>calorii) || calorii<0) throw intInvalid();}

//afisare
void pizza::afisare(std::ostream& os) const{
    os<<" Toppinguri: ";
    if(toppinguri.empty()) os<<" - ";
    else for (int i = 0; i < toppinguri.size(); ++i) {
            os << toppinguri[i] << (i == toppinguri.size() - 1 ? "" : ", ");
    }
    os<<" | blat: "<<blat<<"  ["<<calorii<<"kcal ] ";}

//functii
float pizza::getPret()const{ return pret+0.25;}
int pizza::timpPreparare()const{ return 25 + toppinguri.size()*5;}
















