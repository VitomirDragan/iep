#include "../inc/ContBancar.h"

ContBancar::ContBancar(string nrCont, float sumaTotala) : numarCont(nrCont) {
    suma = new float;
    *suma = sumaTotala;
}

ContBancar::~ContBancar() {
    cout << "Deleted bank account " << numarCont << endl;
    delete suma;
}

string ContBancar::getNumarCont() {
    return numarCont;
}

void ContBancar::setNumarCont(string numarCont) {
    this->numarCont = numarCont;
}

float ContBancar::getSuma() {
    return *suma;
}

void ContBancar::setSuma(float sumaP) {
    *suma = sumaP;
}