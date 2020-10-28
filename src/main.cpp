#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Uncopyable{
public:
    Uncopyable(){}
    ~Uncopyable(){}
private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};

class Credit {
    private:
       int idCredit;
       int suma;
       int perioada;
    public:
       Credit(int idCredit, int suma, int perioada):idCredit(idCredit), suma(suma), perioada(perioada){}

       Credit(const Credit &c){
           this->idCredit = c.idCredit;
           this->suma = c.suma;
           this->perioada = c.perioada;
       }

       ~Credit(){
           cout << "Deleted credit " << idCredit << "\n";
       }

       Credit& operator=(const Credit& t){
        return *this;
       }

       int getSuma(){
        return suma;
       }

       int getId(){
        return idCredit;
       }
       
       int getPeriod(){
           return perioada;
       }

       int calculRata(){
           return suma/(perioada * 12) + 0.09 * suma/(perioada * 12);
       }
};

class Tranzactie{
private:
    int idTranzactie;
    int suma;

public:
    Tranzactie(int idTranzactie, int suma) : idTranzactie(idTranzactie), suma(suma){}

    Tranzactie(const Tranzactie &t){
        this->suma = t.suma;
        this->idTranzactie = t.idTranzactie;
    }

    ~Tranzactie(){
        cout << "Deleted trazaction " << idTranzactie << "\n";
    }

    Tranzactie& operator=(const Tranzactie& t){
        return *this;
    }

    int getSuma(){
        return suma;
    }

    int getId(){
        return idTranzactie;
    }
};

class SumaTotala : private Uncopyable {
public:
    virtual float getSumaTotala() = 0;
};

class ContBancar : public SumaTotala {
private:
    string numarCont;
    float suma;
public:
    ContBancar(string nrCont, float sumaTotala) : numarCont(nrCont), suma(sumaTotala) {}

    string getNumarCont() {
        return numarCont;
    }

    void setNumarCont(string numarCont) {
        this->numarCont = numarCont;
    }

    float getSuma() {
        return suma;
    }

    void setSuma(float suma) {
        this->suma = suma;
    }
};

class ContBancarLei : public ContBancar {
public:
    ContBancarLei(string nrCont, float sumaTotala) : ContBancar(nrCont, sumaTotala) {}

    float getSumaTotala() override {
        return getSuma();
    }

    void transfer(ContBancarLei &contDestinatie, float suma) {
        contDestinatie.setSuma(contDestinatie.getSumaTotala() + suma);
        setSuma(this->getSuma() - suma);
    }
};

class ContBancarEuro : public ContBancar {
public:
    ContBancarEuro(string nrCont, float sumaTotala) : ContBancar(nrCont, sumaTotala) {}

    float getDobanda() {
        if (getSuma() > 500) {
            return 0.3;
        } else {
            return 0;
        }
    }

    float getSumaTotala() override {
        return getSuma() * 36000;
    }

    void transfer(ContBancarEuro &contDestinatie, float suma) {
        contDestinatie.setSuma(contDestinatie.getSumaTotala() + suma);
        setSuma(this->getSuma() - suma);
    }
};

class Client : private Uncopyable{
private:
    string nume;
    string adresa;
    vector<ContBancar *> conturi;
    vector<Tranzactie*> tranzactii;
    vector<Credit*> credite;

public:
    Client(string numeP, string adresaP, vector<ContBancar *> conturiP) : nume(numeP), adresa(adresaP), conturi(conturiP) {}

    string getNume() {
        return nume;
    }

    void setNume(string nume) {
        this->nume = nume;
    }

    string getAdresa() {
        return adresa;
    }

    void setAdresa(string adresa) {
        this->adresa = adresa;
    }

    string toString() {
        string output = "";

        output += nume + " " + adresa + "\n";
        for (int i = 0; i < conturi.size(); i++) {
            output += " Cont: " + to_string(i) + " suma: "
                      + to_string(conturi[i]->getSumaTotala()) + "\n";
        }

        return output;
    }

    void addTranzaction(Tranzactie* t){
        tranzactii.push_back(t);
    }

    void printTranzactions(){
        for(int i = 0; i < tranzactii.size(); i++){
            cout << "Tranzactie " << tranzactii[i]->getId() << " - " << tranzactii[i]->getSuma() << '\n';
        }
    }

    void addCredit(Credit* c){
        credite.push_back(c);
    }

    void printCredits(){
        if(credite.size() == 0)
        {
            cout<<"Credite inexistente pe acest cont bancar\n";
            return;
        }

        for(int i = 0; i < credite.size(); i++){
            cout << "Credit "<<credite[i]->getId() << " : in valoare de " << credite[i]->getSuma() << "lei pe " << credite[i]->getPeriod() << " ani\n";
        }
    }

    int calculRataTotala(){
        int rataCumulata = 0;
        if(credite.size() != 0){ 
            for(int i = 0; i < credite.size(); i++){
                rataCumulata+= credite[i]->calculRata();
            }
        }
        return rataCumulata;
    }
};

class Banca : private Uncopyable{
private:
    vector<Client *> clienti;
    string codBanca;
public:
    Banca(vector<Client *> clientiP, string codBancaP) : clienti(clientiP), codBanca(codBancaP) {}

    void add(Client &c) {
        clienti.push_back(&c);
    }

    void afisareClient(string nume) {
        for (int i = 0; i < clienti.size(); i++)
            if (nume == clienti[i]->getNume())
                cout << clienti[i]->toString();
    }
};

int main() {
    ContBancarEuro contEuro1("contEuro1", 12000);
    contEuro1.setSuma(12001);
    contEuro1.setNumarCont("contEuro1Modificat");

    ContBancarEuro contEuro2("contEuro2", 18000);

    ContBancarLei contLei1("contLei1", 100);

    ContBancarLei contLei2("contLei2", 500);


    cout << contEuro1.getNumarCont() << " " << contEuro1.getSuma() << endl;
    cout << contEuro2.getNumarCont() << " " << contEuro2.getSuma() << endl;
    cout << contLei1.getNumarCont() << " " << contLei1.getSuma() << endl;
    cout << contLei2.getNumarCont() << " " << contLei2.getSuma() << endl;

    vector<ContBancar *> conturiClient1;
    conturiClient1.push_back(&contEuro1);
    conturiClient1.push_back(&contLei1);

    vector<ContBancar *> conturiClient2;
    conturiClient2.push_back(&contEuro2);
    conturiClient2.push_back(&contLei2);

    Client client1("A", "B", conturiClient1);
    Client client2("C", "D", conturiClient2);
    Client client3("E", "F", conturiClient1);

    contLei1.transfer(contLei2, 34);
    contEuro1.transfer(contEuro2, 56);

    vector<Client *> clienti;
    clienti.push_back(&client1);
    clienti.push_back(&client2);

    Banca banca(clienti, "Banca");
    banca.afisareClient("C");

    banca.add(client3);
    banca.afisareClient("E");

    Tranzactie t11 = Tranzactie(1, 200);
    Tranzactie t21 = Tranzactie(2, 500);

    Tranzactie t12 = Tranzactie(t11);
    Tranzactie t22 = t21;

    client1.addTranzaction(&t11);
    client2.addTranzaction(&t12);

    client2.addTranzaction(&t21);
    client3.addTranzaction(&t22);

    cout << "Tranzactii client 1:\n";
    client1.printTranzactions();
    cout << '\n';

    cout << "Tranzactii client 2:\n";
    client2.printTranzactions();
    cout << '\n';

    cout << "Tranzactii client 3:\n";
    client3.printTranzactions();
    cout << '\n';
    
        
    Credit c11 = Credit(12, 200000, 10);
    Credit c21 = Credit(4, 10000, 3);
    Credit c12 = Credit(c21);

    client1.addCredit(&c11);
    client1.addCredit(&c21);

    client2.addCredit(&c12);
    
    cout<<"Clientul 1 are:\n";
    client1.printCredits();
    cout<<"Avand rata lunara totala de: "<< client1.calculRataTotala()<<"lei\n";
    cout<<'\n';

    cout<<"Clientul 2 are:\n";
    client2.printCredits();
    cout<<"Avand rata lunara totala de: "<< client2.calculRataTotala()<<"lei\n";
    cout<<'\n';

    cout<<"Clientul 3 are:\n";
    client3.printCredits();
    cout<<"Avand rata lunara totala de: "<< client3.calculRataTotala()<<"lei\n";
    cout<<'\n';

    return 0;
}
