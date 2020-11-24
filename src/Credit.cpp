#include "../inc/Credit.h"

Credit::Credit(int idCredit, int suma, int perioada) {
    this->idCredit = new int(idCredit);
    this->suma = new int(suma);
    this->perioada = new int(perioada);
}

Credit::Credit(const Credit &c) {//Copy-constructor, se face o copiere pentru fiecare data membra din clasa
    cout << "Apel copy constructor in credit" << endl;
    this->idCredit = c.idCredit;
    this->suma = c.suma;
    this->perioada = c.perioada;
}

Credit::~Credit() {//Destructorul este apelat la distrugerea unui obiect de tip Credit
    cout << "Deleted credit " << *idCredit << "\n";
    delete idCredit;
    delete suma;
    delete perioada;
}

Credit &Credit::operator=(const Credit& c) {//Assignment operator returneaza o referinta pe obiectul this
    if (this == &c) return *this;
    
    int *idCreditO = idCredit;
    int *sumaO = suma;
    int *perioadaO = perioada;

    idCredit = new int(*c.idCredit);
    suma = new int(*c.suma);
    perioada = new int(*c.perioada);

    delete idCreditO;
    delete sumaO;
    delete perioadaO;

    return *this;
}

int Credit::getSuma() {
    return *suma;
}

int Credit::getId() {
    return *idCredit;
}

int Credit::getPeriod() {
    return *perioada;
}

int Credit::calculRata() {
    return *suma / (*perioada * 12) + 0.09 * (*suma) / (*perioada * 12);
}
