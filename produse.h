#ifndef PRODUSE_H
#define PRODUSE_H
#include <string>
#include <istream>
#include <ostream>
class produse{
protected:
    std::string nume;
    int gramaj;
    float pret;
    virtual void citire(std::istream& is);
    virtual void afisare(std::ostream& os) const;
public:
    produse();
    produse(const std::string& nume, int gramaj, float pret);
    produse(const produse& p);
    virtual ~produse() = default;

    produse& operator=(const produse& p);

    std::string getNume() const;
    virtual float getPret() const = 0;
    virtual int timpPreparare() const = 0;

    friend std::istream& operator>>(std::istream& is, produse& p);
    friend std::ostream& operator<<(std::ostream& os,const produse& p);
};
#endif
