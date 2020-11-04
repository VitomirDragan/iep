#include "../inc/ContBancarEuro.h"

ContBancarEuro::ContBancarEuro(string nrCont, float sumaTotala) : ContBancar(nrCont, sumaTotala) {}//Se face apel catre superconstructor

float ContBancarEuro::getDobanda() {//Calculam dobanda in functie de suma detinuta in cont
    if (getSuma() > 500) {
        return 0.3;
    } else {
        return 0;
    }
}

float ContBancarEuro::getSumaTotala() {//Returnam suma din cont, insa se realizeaza o conversie deoarece suma este salvata in euro
    return getSuma() * 36000;
}

void ContBancarEuro::transfer(ContBancarEuro &contDestinatie, float suma) {/*Realizam un transfer bancar intre contul curent si contul destinatie(primit ca parametru)*/
    contDestinatie.setSuma(contDestinatie.getSumaTotala() + suma);
    setSuma(this->getSuma() - suma);
}

