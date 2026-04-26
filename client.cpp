#include "client.h"
#include "exceptii.h"
int client::nrClienti = 0;

//constructoruii + destructorul
client::client(): nume("-"), adresa("-"), telefon("-"){}

client::client(const std::string& nume, const std::string& adresa, const std::string& telefon)
    :nume(nume), adresa(adresa), telefon(telefon){
        if (telefon.length() != 10) throw telefonInvalid();
        else if (telefon[0] != '0' || telefon[1] != '7') throw telefonInvalid();
        nrClienti++;}

client::client(const client& c): nume(c.nume), adresa(c.adresa), telefon(c.telefon){}

client::~client(){}

//getarii
std::string client::getNume() const{return nume;}
int client::getNrClienti() {return nrClienti;}

//suprascrierea operatorilotr
client& client::operator=(const client& c){
    if(this != &c){
        nume = c.nume;
        adresa = c.adresa;
        telefon = c.telefon;}
    return *this;}


std::istream& operator>>(std::istream& is, client& c){
    is>>c.nume>>c.adresa>>c.telefon;
    return is;}
std::ostream& operator<<(std::ostream& os, const client& c){
    os<<"client: "<<c.nume<<" adresa: "<<c.adresa<<" telefon: "
    <<c.telefon<<";\n";
    return os;}

bool client::operator==(const client& c) const {
    return (this->nume == c.nume && this->adresa == c.adresa&& this->telefon == c.telefon);
}


















