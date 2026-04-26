#ifndef BAUTURI_H
#define BAUTURI_H
#include "produse.h"
#include <string>
class bauturi: public produse{
protected:
    std::string ambalaj;
    bool alcool;
    void citire(std::istream& is) override;
    void afisare(std::ostream& os) const override;
public:
    bauturi();
    bauturi(const std::string& nume,float pret, int gramaj, const std::string& ambalaj, bool alcool);
    bauturi(const bauturi& b);
    ~bauturi() override = default;

    std::string getNume() const;
    float getPret() const override;
    float getAlcool()const;
    int timpPreparare() const override;
    bauturi& operator=(const bauturi& b);
};
#endif




















