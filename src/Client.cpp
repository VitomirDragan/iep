#include "../inc/Client.h"

Client::Client(string numeP, string adresaP, vector<ContBancar *> conturiP, int varstaP) : nume(numeP), adresa(adresaP),
                                                                                           conturi(conturiP) {
    varsta = new int;
    *varsta = varstaP;
}

Client::~Client() {
    cout << "Deleted client " << nume << endl;
    delete varsta;
}

string Client::getNume() {
    return nume;
}

void Client::setNume(string nume) {
    this->nume = nume;
}

string Client::getAdresa() {
    return adresa;
}

void Client::setAdresa(string adresa) {
    this->adresa = adresa;
}

string Client::toString() {
    string output = "";

    output += nume + " " + adresa + "\n";
    for (int i = 0; i < conturi.size(); i++) {
        output += " Cont: " + to_string(i) + " suma: "
                  + to_string(conturi[i]->getSumaTotala()) + "\n";
    }

    return output;
}

void Client::addTranzaction(Tranzactie *t) {
    tranzactii.push_back(t);
}

void Client::printTranzactions() {
    for (int i = 0; i < tranzactii.size(); i++) {
        cout << "Tranzactie " << tranzactii[i]->getId() << " - " << tranzactii[i]->getSuma() << '\n';
    }
}

void Client::addCredit(Credit *c) {
    credite.push_back(c);
}

void Client::printCredits() {
    if (credite.size() == 0) {
        cout << "Credite inexistente pe acest cont bancar\n";
        return;
    }

    for (int i = 0; i < credite.size(); i++) {
        cout << "Credit " << credite[i]->getId() << " : in valoare de " << credite[i]->getSuma() << "lei pe "
             << credite[i]->getPeriod() << " ani\n";
    }
}

int Client::calculRataTotala() {
    int rataCumulata = 0;
    if (credite.size() != 0) {
        for (int i = 0; i < credite.size(); i++) {
            rataCumulata += credite[i]->calculRata();
        }
    }
    return rataCumulata;
}