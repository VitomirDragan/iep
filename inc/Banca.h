#ifndef PROJECT1_BANCA_H
#define PROJECT1_BANCA_H

#include "Uncopyable.h"
#include "Client.h"


using namespace std;

class Banca : private Uncopyable {
private:
    vector<Client *> clienti;
    int *codBanca;
public:
    Banca(vector<Client *> clientiP, int codBancaP);

    ~Banca();

    void add(Client &c);

    void afisareClient(string nume);
};

#endif //PROJECT1_BANCA_H
