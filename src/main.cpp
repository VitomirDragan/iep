#include <TranzactieOnline.h>
#include "../inc/ContBancarEuro.h"
#include "../inc/ContBancarLei.h"
#include "../inc/Client.h"
#include "../inc/Banca.h"

int main() {
    ContBancarEuro contEuro1("contEuro1", 12000);//Cream obiect de tip ContBancarEuro
    contEuro1.setSuma(12001);
    contEuro1.setNumarCont("contEuro1Modificat");

    ContBancarEuro contEuro2("contEuro2", 18000);

    ContBancarLei contLei1("contLei1", 100);

    ContBancarLei contLei2("contLei2", 500);


    cout << contEuro1.getNumarCont() << " " << contEuro1.getSuma() << endl;
    cout << contEuro2.getNumarCont() << " " << contEuro2.getSuma() << endl;
    cout << contLei1.getNumarCont() << " " << contLei1.getSuma() << endl;
    cout << contLei2.getNumarCont() << " " << contLei2.getSuma() << endl;

    vector < ContBancar * > conturiClient1;
    conturiClient1.push_back(&contEuro1);//Functia push_back face o adaugare la sfasit in vectorul conturiClient
    conturiClient1.push_back(&contLei1);

    vector < ContBancar * > conturiClient2;
    conturiClient2.push_back(&contEuro2);
    conturiClient2.push_back(&contLei2);

    Client client1("A", "B", conturiClient1, 30);
    Client client2("C", "D", conturiClient2, 38);
    Client client3("E", "F", conturiClient1, 45);

    contLei1.transfer(contLei2, 34);
    contEuro1.transfer(contEuro2, 56);

    vector < Client * > clienti;
    clienti.push_back(&client1);
    clienti.push_back(&client2);

    Banca banca(clienti, 1);
    banca.afisareClient("C");

    banca.add(client3);
    banca.afisareClient("E");

    Tranzactie t11(1, 200);
    Tranzactie t21(2, 500);
    Tranzactie t22(3, 800);
    Tranzactie t31(t22);

    Tranzactie t12(
            t11); /* Folosim copy-constructor pentru a crea t12. Copy constructorul este apelat atunci cand un nou obiect este creat dintr-un obiect existent*/
    t22 = t21; /*Folosim assignment operator. Acesta este apelat cand unui obiect care a fost deja initializat i se atribuie o noua valoare de la un obiect existent*/


    TranzactieOnline to11(4, 950, 2);
    TranzactieOnline to21(5, 800, 3);
    TranzactieOnline to22(6, 750, 1.5);
    TranzactieOnline to31(to22);
    TranzactieOnline to12(to11);

    t22 = t21;

    client1.addTranzaction(&t11);
    client1.addTranzaction(&to11);

    client2.addTranzaction(&t12);
    client2.addTranzaction(&to12);

    client2.addTranzaction(&t21);
    client2.addTranzaction(&to21);

    client3.addTranzaction(&t22);
    client3.addTranzaction(&to22);

    cout << "Tranzactii client 1:\n";
    client1.printTranzactions();
    cout << '\n';

    cout << "Tranzactii client 2:\n";
    client2.printTranzactions();
    cout << '\n';

    cout << "Tranzactii client 3:\n";
    client3.printTranzactions();
    cout << '\n';


    Credit c11(12, 200000, 10);
    Credit c21(4, 10000, 3);
    Credit c12(c21);// Apel copy-constructor pentru a crea un nou obiect de tip credit

    client1.addCredit(&c11);
    client1.addCredit(&c21);

    client2.addCredit(&c12);

    cout << "Clientul 1 are:\n";
    client1.printCredits();
    cout << "Avand rata lunara totala de: " << client1.calculRataTotala() << "lei\n";
    cout << '\n';

    cout << "Clientul 2 are:\n";
    client2.printCredits();
    cout << "Avand rata lunara totala de: " << client2.calculRataTotala() << "lei\n";
    cout << '\n';

    cout << "Clientul 3 are:\n";
    client3.printCredits();
    cout << "Avand rata lunara totala de: " << client3.calculRataTotala() << "lei\n";
    cout << '\n';

    return 0;
}
