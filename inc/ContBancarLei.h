#ifndef PROJECT1_CONTBANCARLEI_H
#define PROJECT1_CONTBANCARLEI_H

#include "ContBancar.h"

class ContBancarLei : public ContBancar {
public:
    ContBancarLei(string nrCont, float sumaTotala);

    float getSumaTotala() override;

    void transfer(ContBancarLei &contDestinatie, float suma);
};

#endif //PROJECT1_CONTBANCARLEI_H
