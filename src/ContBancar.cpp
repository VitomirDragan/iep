#include "../inc/ContBancar.h"

ContBancar::ContBancar(string nrCont, float sumaTotala) : numarCont(
        nrCont) {// Initializam datele membre ale clasei utilizand member list
    suma = new float(sumaTotala); // Alocare dinamica pentru suma totala si initializare
}

ContBancar::~ContBancar() {
    cout << "Deleted bank account " << numarCont << endl;
    delete suma; //Eliberare explicita de memorie pentru suma
}

string ContBancar::getNumarCont() {//Getter numar cont
    return numarCont;
}

void ContBancar::setNumarCont(string numarCont) {//Setter numar cont
    this->numarCont = numarCont;
}

float ContBancar::getSuma() {//Getter suma detinuta in cont
    return *suma;
}

void ContBancar::setSuma(float sumaP) {//Setter pentru suma
    *suma = sumaP;
}
