#ifndef PROJECT1_CREDITIPOTECAR_H
#define PROJECT1_CREDITIPOTECAR_H


#include <iostream>
#include "Credit.h"

using namespace std;

class CreditIpotecar : public Credit {
private:
    char *ipoteca;
    int *valoareIpoteca;
public:
    CreditIpotecar(int idCredit, int suma, int perioada, char ipoteca[100], int valoareIpoteca);

    ~CreditIpotecar();

    CreditIpotecar(const CreditIpotecar &creditIpotecar);

    CreditIpotecar&  operator =(const CreditIpotecar & c);
};

#endif
