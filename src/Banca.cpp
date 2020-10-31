#include "../inc/Banca.h"

Banca::Banca(vector<Client *> clientiP, int codBancaP) : clienti(clientiP) {
    codBanca = new int;
    *codBanca = codBancaP;
}

Banca::~Banca() {
    cout << "Deleted bank " << *codBanca << endl;
    delete codBanca;
}

void Banca::add(Client &c) {
    clienti.push_back(&c);
}

void Banca::afisareClient(string nume) {
    for (int i = 0; i < clienti.size(); i++)
        if (nume == clienti[i]->getNume())
            cout << clienti[i]->toString();
}