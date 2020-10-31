#ifndef PROJECT1_CONTBANCAR_H
#define PROJECT1_CONTBANCAR_H

#include "SumaTotala.h"

class ContBancar : public SumaTotala {
private:
    string numarCont;
    float *suma;
public:
    ContBancar(string nrCont, float sumaTotala);

    ~ContBancar();

    string getNumarCont();

    void setNumarCont(string numarCont);

    float getSuma();

    void setSuma(float sumaP);
};

#endif //PROJECT1_CONTBANCAR_H
