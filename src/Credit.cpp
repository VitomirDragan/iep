#include "../inc/Credit.h"

Credit::Credit(int idCredit, int suma, int perioada) : idCredit(idCredit), suma(suma), perioada(perioada) {}//Apel superconstructor

Credit::Credit(const Credit &c) {//Copy-constructor, se face o copiere pentru fiecare data membra din clasa
    cout << "Apel copy constructor in credit" << endl;
    this->idCredit = c.idCredit;
    this->suma = c.suma;
    this->perioada = c.perioada;
}

Credit::~Credit() {//Destructorul este apelat la distrugerea unui obiect de tip Credit
    cout << "Deleted credit " << idCredit << "\n";
}

Credit &Credit::operator=(const Credit &t) {//Assignment operator returneaza o referinta pe obiectul this
    cout << "Apel assignment operator in credit" << endl;
    return *this;
}

int Credit::getSuma() {
    return suma;
}

int Credit::getId() {
    return idCredit;
}

int Credit::getPeriod() {
    return perioada;
}

int Credit::calculRata() {
    return suma / (perioada * 12) + 0.09 * suma / (perioada * 12);
}
