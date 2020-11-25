#include "../inc/Tranzactie.h"

Tranzactie::Tranzactie(int idTranzactie, int suma) {
    this->idTranzactie = new int(idTranzactie);
    this->suma = new int(suma);
}

Tranzactie::Tranzactie(const Tranzactie &t) {
    cout << "Apel copy constructor in Tranzactie" << endl;
    suma = new int(*t.suma);
    idTranzactie = new int(*t.idTranzactie);
}

Tranzactie::~Tranzactie() {
    cout << "Deleted trazaction " << *idTranzactie << "\n";
    delete (idTranzactie);
    delete (suma);
}


Tranzactie &Tranzactie::operator=(const Tranzactie &t) {
    cout << "Apel assignment operator in Tranzactie" << endl;
    int *sumaO = suma;
    int *idTranzactieO = idTranzactie;

    suma = new int(*t.suma);
    idTranzactie = new int(*t.idTranzactie);

    delete sumaO;
    delete idTranzactieO;
    return *this;
}

int Tranzactie::getSuma() {
    return *suma;
}

int Tranzactie::getId() {
    return *idTranzactie;
}
