#include "../inc/Tranzactie.h"

Tranzactie::Tranzactie(int idTranzactie, int suma)
{
    this->idTranzactie = new int(idTranzactie);
    this->suma = new int(suma);
} 

Tranzactie::Tranzactie(const Tranzactie &t) {
    cout << "Apel copy constructor in Tranzactie" << endl;
    init(t);
}

Tranzactie::~Tranzactie() {
    cout << "Deleted trazaction " << idTranzactie << "\n";
}

void Tranzactie::init(const Tranzactie &t)
{
    int *sumaO = suma;
    int *idTranzactieO = idTranzactie;
    
    suma= new int(*t.suma);
    idTranzactie= new int(*t.idTranzactie);

    delete sumaO;
    delete idTranzactieO;
}

Tranzactie &Tranzactie::operator=(const Tranzactie &t) {
    cout << "Apel assignment operator in Tranzactie" << endl;
    init(t);
    return *this;
}

int Tranzactie::getSuma() {
    return *suma;
}

int Tranzactie::getId() {
    return *idTranzactie;
}
