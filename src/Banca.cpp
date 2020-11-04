#include "../inc/Banca.h"
// Initializam datele membre ale clasei utilizand member list
Banca::Banca(vector<Client *> clientiP, int codBancaP) : clienti(clientiP) {
    codBanca = new int(codBancaP);//Alocare dinamica, se apeleaza copy-constructorul din tipul predefinit int
}

Banca::~Banca() {
    cout << "Deleted bank " << *codBanca << endl;
    delete codBanca; // Dezalocare explicita a lui codBanca
}

void Banca::add(Client &c) { //Adaugare client in vector de clienti
    clienti.push_back(&c);
}

void Banca::afisareClient(string nume) {
    for (int i = 0; i < clienti.size(); i++) //Parcurgere vectori clienti si afisare
        if (nume == clienti[i]->getNume())
            cout << clienti[i]->toString(); 
}
