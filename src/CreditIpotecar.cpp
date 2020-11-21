#include <CreditIpotecar.h>

CreditIpotecar::CreditIpotecar(int idCredit, int suma, int perioada, char *ipoteca, int valoareIpoteca)
: Credit(idCredit, suma, perioada) {
    this->ipoteca = new char[100];
    this->valoareIpoteca = new int(valoareIpoteca);
}

CreditIpotecar::~CreditIpotecar() {
    delete ipoteca;
    delete valoareIpoteca;
}

CreditIpotecar::CreditIpotecar(const CreditIpotecar &creditIpotecar) : Credit(creditIpotecar), ipoteca(creditIpotecar.ipoteca), valoareIpoteca(creditIpotecar.valoareIpoteca){}

CreditIpotecar & CreditIpotecar::operator=(const CreditIpotecar & c) {
    Credit::operator=(c);
    char *ipotecaO = ipoteca;
    int *valoareIpotecaO = valoareIpoteca;

    ipoteca = new char(*c.ipoteca);
    valoareIpoteca = new int(*c.valoareIpoteca);

    delete ipotecaO;
    delete valoareIpotecaO;

    return *this;
}
