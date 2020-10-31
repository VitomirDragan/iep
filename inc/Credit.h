#ifndef PROJECT1_CREDIT_H
#define PROJECT1_CREDIT_H

#include <iostream>

using namespace std;

class Credit {
private:
    int idCredit;
    int suma;
    int perioada;
public:
    Credit(int idCredit, int suma, int perioada);

    Credit(const Credit &c);

    ~Credit();

    Credit &operator=(const Credit &t);

    int getSuma();

    int getId();

    int getPeriod();

    int calculRata();
};

#endif //PROJECT1_CREDIT_H
