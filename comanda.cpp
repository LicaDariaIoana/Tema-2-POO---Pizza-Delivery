#include "comanda.h"
#include "exceptii.h"
#include "pizza.h"
#include "bauturi.h"
#include "desert.h"
int comanda::nrComenzi = -1;

//constructori
comanda::comanda(): clientComanda(){nrComenzi++;}
comanda::comanda(const client& clientComanda): clientComanda(clientComanda){nrComenzi++;}

std::string comanda::getNume() const {return clientComanda.getNume();}
int comanda::getNrComenzi() {return nrComenzi;}

void swap(comanda& first, comanda& second) noexcept {
    using std::swap;
    swap(first.clientComanda, second.clientComanda);
    swap(first.produseComanda, second.produseComanda);}

comanda& comanda::operator=(comanda c) {
    swap(*this, c);
    return *this;}

float comanda::pretTotal() const{
    float total = 0;
    for(const auto& p : produseComanda){
        total += p->getPret();}
    return total;}

std::ostream& operator<<(std::ostream& os, const comanda& c){
    if(c.getNume() != "-") {os<<c.clientComanda<<"produse:\n";}
    int i=1;

    bool aux = true;
    for(const auto& p: c.produseComanda){
        if(std::dynamic_pointer_cast<pizza>(p)){
            if(aux) os<<"\n\n--PIZZA--";
            aux = false;
            os<<"\n"<<i<<". "<<*p; i++;}}

    aux = true;
    for(const auto& b : c.produseComanda){
        if(std::dynamic_pointer_cast<bauturi>(b)){
            if(aux) os<<"\n\n--BAUTURI--";
            aux = false;
            os<<"\n"<<i<<". "<<*b; i++;}}

    aux = true;
    for(const auto& d : c.produseComanda) {
        if(std::dynamic_pointer_cast<desert>(d)) {
            if(aux) os<<"\n\n--DESERT--";
            aux=false;
            os <<"\n"<<i<<". " << *d; i++;}}

    if(c.getNume() != "-") {os<<"\n\n==============TOTAL = "<<c.pretTotal()<<" ==============\n";}
    else os<<"\n\n";
    return os;}

//functii
void comanda::adaugaProdus(std::shared_ptr<produse> p){
    auto b = std::dynamic_pointer_cast<bauturi>(p);
    if (b != nullptr && b->getAlcool() == 1) {
        throw varstaAlcool(b->getNume());}
    produseComanda.push_back(p);}

void comanda::stergeProdus(int index) {
    if (index >= 0 && index < (int)produseComanda.size()) {
        std::cout << "Produsul '" << produseComanda[index]->getNume() << "' a fost eliminat.\n";
        produseComanda.erase(produseComanda.begin() + index);}
    else {std::cout << "Eroare: Index invalid in comanda!\n";}}

int comanda::timpPreparareTotal()const{
    int timpMax = 0;
    for(const auto& p: produseComanda){
        int timpCurent = p->timpPreparare();
        if(timpCurent>timpMax){timpMax = timpCurent;}
    }
    return timpMax;}


void comanda::push_back(std::shared_ptr<produse> p) {produseComanda.push_back(p);}

size_t comanda::size() const {return produseComanda.size();}

bool comanda::empty() const {return produseComanda.empty();}

std::shared_ptr<produse> comanda::operator[](int index) {return produseComanda[index];}






