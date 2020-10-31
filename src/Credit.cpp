#include "../inc/Credit.h"

Credit::Credit(int idCredit, int suma, int perioada) : idCredit(idCredit), suma(suma), perioada(perioada) {}

Credit::Credit(const Credit &c) {
    this->idCredit = c.idCredit;
    this->suma = c.suma;
    this->perioada = c.perioada;
}

Credit::~Credit() {
    cout << "Deleted credit " << idCredit << "\n";
}

Credit &Credit::operator=(const Credit &t) {
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