#include "../inc/Tranzactie.h"

Tranzactie::Tranzactie(int idTranzactie, int suma) : idTranzactie(idTranzactie), suma(suma) {}

Tranzactie::Tranzactie(const Tranzactie &t) {
    cout << "Apel copy constructor in Tranzactie" << endl;
    this->suma = t.suma;
    this->idTranzactie = t.idTranzactie;
}

Tranzactie::~Tranzactie() {
    cout << "Deleted trazaction " << idTranzactie << "\n";
}

Tranzactie &Tranzactie::operator=(const Tranzactie &t) {
    cout << "Apel assignment operator in Tranzactie" << endl;
    return *this;
}

int Tranzactie::getSuma() {
    return suma;
}

int Tranzactie::getId() {
    return idTranzactie;
}
