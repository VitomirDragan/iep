#ifndef PROJECT1_TRANZACTIE_H
#define PROJECT1_TRANZACTIE_H

#include <iostream>

using namespace std;

class Tranzactie {
private:
    int *idTranzactie;
    int *suma;

public:
    Tranzactie(int idTranzactie, int suma);

    Tranzactie(const Tranzactie &t);

    ~Tranzactie();
    void init(const Tranzactie &t);

    Tranzactie &operator=(const Tranzactie &t);

    int getSuma();

    int getId();
};

#endif //PROJECT1_TRANZACTIE_H
