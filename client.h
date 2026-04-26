#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
class client{
private:
    std::string nume, adresa, telefon;
    static int nrClienti;
public:
    client();
    client(const std::string& nume,const std::string& adresa, const std::string& telefon);
    client(const client& c);
    client& operator= (const client& c);
    ~client();

    std::string getNume() const;
    float pretTotal()const;
    static int getNrClienti();

    friend std::istream& operator>>(std::istream& is, client& c);
    friend std::ostream& operator<<(std::ostream& os, const client& c);
    bool operator==(const client& altul) const;
};
#endif
