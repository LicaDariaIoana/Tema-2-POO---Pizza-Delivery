#ifndef PIZZA_H
#define PIZZA_H
#include "produse.h"
#include <string>
#include <vector>
class pizza: public produse{
protected:
    std::string blat;
    std::vector<std::string> toppinguri;
    int calorii;
    void citire(std::istream& is) override;
    void afisare(std::ostream& os) const override;
public:
    pizza();
    pizza(const std::string& nume, int gramaj, float pret, const std::vector<std::string>& toppinguri,
          const std::string& blat, int calorii);
    pizza(const pizza& p);
    ~pizza() override = default;

    pizza& operator= (const pizza& p);

    float getPret() const override;
    int timpPreparare()const override;
};
#endif
