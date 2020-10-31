#ifndef PROJECT1_CONTBANCAREURO_H
#define PROJECT1_CONTBANCAREURO_H

#include "ContBancar.h"

class ContBancarEuro : public ContBancar {
public:
    ContBancarEuro(string nrCont, float sumaTotala);

    float getDobanda();

    float getSumaTotala() override;

    void transfer(ContBancarEuro &contDestinatie, float suma);
};

#endif //PROJECT1_CONTBANCAREURO_H
