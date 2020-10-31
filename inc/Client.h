#ifndef PROJECT1_CLIENT_H
#define PROJECT1_CLIENT_H

#include "Uncopyable.h"
#include "ContBancar.h"
#include "Tranzactie.h"
#include "Credit.h"

class Client : private Uncopyable {
private:
    string nume;
    string adresa;
    int *varsta;
    vector<ContBancar *> conturi;
    vector<Tranzactie *> tranzactii;
    vector<Credit *> credite;
public:
    Client(string numeP, string adresaP, vector<ContBancar *> conturiP, int varstaP);

    ~Client();

    string getNume();

    void setNume(string nume);

    string getAdresa();

    void setAdresa(string adresa);

    string toString();

    void addTranzaction(Tranzactie *t);

    void printTranzactions();

    void addCredit(Credit *c);

    void printCredits();

    int calculRataTotala();
};

#endif //PROJECT1_CLIENT_H
