#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>
#include <string>

class exceptii: public std::exception{
protected:
    std::string mesaj;
public:
    exceptii(const std::string& m): mesaj(m){}
    virtual const char* what() const noexcept override {
        return mesaj.c_str();}
};

class intInvalid: public exceptii{
public:
    intInvalid():
        exceptii("EROARE: Datele introduse trebuie sa fie numere naturale!!!\n"){}
};

class telefonInvalid: public exceptii{
public:
    telefonInvalid():
        exceptii("EROARE: Numarul de telefon este invlid! Va rog sa introduceti un numar de 10 cifre cu 40 la inceput\n"){}
};

class varstaAlcool: public exceptii{
public:
    varstaAlcool(const std::string& numeBautura):
        exceptii("ATENTIE!! " +numeBautura+"contine alcool!\n"){}
};
#endif
