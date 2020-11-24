#include "../inc/TranzactieOnline.h"

TranzactieOnline::TranzactieOnline(int idTranzactie, int suma, double timpAsteptare)
: Tranzactie(idTranzactie, suma) {
    this->timpAsteptare = new double(timpAsteptare);
}

TranzactieOnline::~TranzactieOnline() {
    delete timpAsteptare;
}

TranzactieOnline::TranzactieOnline(const TranzactieOnline &t) : Tranzactie(t), timpAsteptare(t.timpAsteptare){}

TranzactieOnline & TranzactieOnline::operator=(const TranzactieOnline & t) {
    Tranzactie::operator=(t);
    double *timpAsteptareO = timpAsteptare;

    timpAsteptare = new double(*t.timpAsteptare);

    delete timpAsteptareO;
    return *this;
}
