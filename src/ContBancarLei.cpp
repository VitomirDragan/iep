#include "../inc/ContBancarLei.h"

ContBancarLei::ContBancarLei(string nrCont, float sumaTotala) : ContBancar(nrCont, sumaTotala) {}/*Initializarea parametrilor se face in superconstructor*/

float ContBancarLei::getSumaTotala(){//Returnam suma detinuta
    return getSuma();
}

void ContBancarLei::transfer(ContBancarLei &contDestinatie, float suma) {//Realizam un transfer bancar
    contDestinatie.setSuma(contDestinatie.getSumaTotala() + suma);
    setSuma(this->getSuma() - suma);
}
