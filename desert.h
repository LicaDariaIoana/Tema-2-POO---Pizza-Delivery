#ifndef DESERT_H
#define DESERT_H
#include "produse.h"
#include <iostream>
#include <string>
class desert: public produse{
protected:
    std::string aroma;
    bool indulcitor;
    int calorii;
    void citire(std::istream& is) override;
    void afisare(std::ostream& os) const override;
public:
    desert();
    desert(const std::string& nume, int gramaj, float pret, const std::string& aroma,bool indulcitor, int calorii);
    desert(const desert& d);
    ~desert() override = default;
    desert& operator= (const desert& d);
    float getPret() const override;
    int timpPreparare() const override;
};
#endif
