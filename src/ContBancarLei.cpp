#include "../inc/ContBancarLei.h"

ContBancarLei::ContBancarLei(string nrCont, float sumaTotala) : ContBancar(nrCont, sumaTotala) {}

float ContBancarLei::getSumaTotala(){
    return getSuma();
}

void ContBancarLei::transfer(ContBancarLei &contDestinatie, float suma) {
    contDestinatie.setSuma(contDestinatie.getSumaTotala() + suma);
    setSuma(this->getSuma() - suma);
}