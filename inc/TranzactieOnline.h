#ifndef PROJECT1_TRANZACTIEONLINE_H
#define PROJECT1_TRANZACTIEONLINE_H

#include <iostream>
#include "Tranzactie.h"
using namespace std;

class TranzactieOnline : public Tranzactie{
private:
    double *timpAsteptare;

public:
    TranzactieOnline(int idTranzactie, int suma, double timpAsteptare);

    TranzactieOnline(const TranzactieOnline &t);

    ~TranzactieOnline();
    
    TranzactieOnline &operator=(const TranzactieOnline &t);

    double getTimpAsteptare(){return *timpAsteptare;};

};

#endif //PROJECT1_TRANZACTIEONLINE_H