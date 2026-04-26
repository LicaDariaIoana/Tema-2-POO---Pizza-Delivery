#ifndef COMANDA_H
#define COMANDA_H
#include <iostream>
#include <vector>
#include <memory>
#include "produse.h"
#include "client.h"
class comanda{
private:
    client clientComanda;
    std::vector<std::shared_ptr<produse>> produseComanda;
    static int nrComenzi;
public:
    comanda();
    comanda(const client& clientComanda);
    comanda(const comanda& c);
    comanda& operator=(comanda c);
    ~comanda() = default;

    void adaugaProdus(std::shared_ptr<produse> p);
    void stergeProdus(int index);
    int timpPreparareTotal()const;
    float pretTotal() const;
    friend std::ostream& operator<<(std::ostream& os, const comanda& c);
    friend void swap(comanda& first, comanda& second) noexcept;

    std::string getNume() const;
    static int getNrComenzi();
    void push_back(std::shared_ptr<produse> p);
    size_t size() const;
    bool empty() const;
    std::shared_ptr<produse> operator[](int index);
};

#endif

























