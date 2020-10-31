#include "../inc/ContBancarEuro.h"

ContBancarEuro::ContBancarEuro(string nrCont, float sumaTotala) : ContBancar(nrCont, sumaTotala) {}

float ContBancarEuro::getDobanda() {
    if (getSuma() > 500) {
        return 0.3;
    } else {
        return 0;
    }
}

float ContBancarEuro::getSumaTotala() {
    return getSuma() * 36000;
}

void ContBancarEuro::transfer(ContBancarEuro &contDestinatie, float suma) {
    contDestinatie.setSuma(contDestinatie.getSumaTotala() + suma);
    setSuma(this->getSuma() - suma);
}

