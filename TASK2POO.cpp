#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Televizor {
public:
    string brand;
    int diagonala;
    bool esteSmart;
    const int idTV;
    static string categorie;
    string* pretTV;
    int nrTV;

    Televizor() : idTV(0) {
        this->brand = "anonim";
        this->diagonala = 0;
        this->esteSmart = 0;
        this->pretTV = nullptr;
        this->nrTV = 0;
    }
    Televizor(string brand) : idTV(0) {
        this->brand = brand;
        this->diagonala = 0;
        this->esteSmart = 0;
        this->pretTV = nullptr;
        this->nrTV = 0;
    }
    Televizor(string brand, int diagonala, bool esteSmart, string* pretTV) : idTV(123) {
        this->brand = brand;
        this->diagonala = diagonala;
        this->esteSmart = esteSmart;
        this->nrTV = 2;
        this->pretTV = new string[this->nrTV];
        for (int i = 0; i < this->nrTV; i++) {
            this->pretTV[i] = pretTV[i];
        }
    }

    void afisare() {
        cout << "Brand Televizor: " << this->brand << endl;
        cout << "Diagonala: " << this->diagonala << " inch" << endl;
        cout << "Este Smart: " << (this->esteSmart ? "DA" : "NU") << endl;
        cout << "ID Televizor: " << this->idTV << endl;
        cout << "Numar TV: " << this->nrTV << endl;
        cout << "Categorie: " << Televizor::categorie << endl;
    }
};
string Televizor::categorie = "ELECTROCASNICE";

class Telefon {
public:
    string model;
    int baterie;
    bool dualSIM;
    const int idTlf;
    static string categorie;
    int* pozitieRaft;
    int nrTelefoane;

    Telefon() : idTlf(0) {
        this->baterie = 0;
        this->dualSIM = 0;
        this->model = "Anonim";
        this->pozitieRaft = nullptr;
        this->nrTelefoane = 0;
    }
    Telefon(int baterie) : idTlf(0) {
        this->baterie = baterie;
        this->dualSIM = 0;
        this->model = "Anonim";
        this->pozitieRaft = nullptr;
        this->nrTelefoane = 0;
    }
    Telefon(string model, int baterie, bool dualSIM) : idTlf(0) {
        this->baterie = baterie;
        this->dualSIM = dualSIM;
        this->model = model;
        this->pozitieRaft = nullptr;
        this->nrTelefoane = 0;
    }

    void afisare() {
        cout << "Model: " << this->model << endl;
        cout << "Baterie: " << this->baterie << "%" << endl;
        cout << "Este dual sim: " << (this->dualSIM ? "DA" : "NU") << endl;
        cout << "ID Telefon: " << this->idTlf << endl;
        cout << "Pozitie raft: " << this->pozitieRaft << endl;
        cout << "Categorie: " << Telefon::categorie << endl;
    }
};
string Telefon::categorie = "ELECTROCASNICE";

class Laptop {
public:
    string brand;
    int RAM;
    float greutate;
    static string categorie;
    const int id;
    float* dimensiuni;
    int nrLaptopuri;

    Laptop() : id(0) {
        this->brand = "Anonim";
        this->RAM = 0;
        this->greutate = 0;
        this->dimensiuni = nullptr;
        this->nrLaptopuri = 0;
    }
    Laptop(string brand) : id(0) {
        this->brand = brand;
        this->RAM = 0;
        this->greutate = 0;
        this->dimensiuni = nullptr;
        this->nrLaptopuri = 0;
    }
    Laptop(string brand, int RAM, float greutate, float* dimensiuni, int nrLaptopuri) : id(234) {
        this->brand = brand;
        this->RAM = RAM;
        this->greutate = greutate;
        this->nrLaptopuri = nrLaptopuri;
        this->dimensiuni = new float[this->nrLaptopuri];
        for (int i = 0; i < this->nrLaptopuri; i++) {
            this->dimensiuni[i] = dimensiuni[i];
        }
    }

    void afisare() {
        cout << "Brand Laptop: " << this->brand << endl;
        cout << "RAM: " << this->RAM << " GB" << endl;
        cout << "Greutate: " << this->greutate << " kg" << endl;
        cout << "ID Laptop: " << this->id << endl;
        cout << "Numar Laptopuri: " << this->nrLaptopuri << endl;
        cout << "Categorie: " << Laptop::categorie << endl;
        for (int i = 0; i < this->nrLaptopuri; i++) {
            cout << "Dimensiune " << i + 1 << ": " << this->dimensiuni[i] << " inch" << endl;
        }
    }
};
string Laptop::categorie = "ELECTROCASNICE";

int main() {
    Telefon t1;
    t1.afisare();
    cout << endl;

    Telefon t2(100);
    t2.afisare();
    cout << endl;

    Telefon t3("Samsung", 96, 1);
    t3.afisare();
    cout << endl;

    Televizor tv1;
    tv1.afisare();
    cout << endl;

    Televizor tv2("SONY");
    tv2.afisare();
    cout << endl;

    string preturi[] = { "1000", "1200" };
    Televizor tv3("LG", 32, 1, preturi);
    tv3.afisare();
    cout << endl;

    float dimensiuniLaptop[] = { 15.6, 14.0 };
    Laptop l1("ASUS", 16, 1.8, dimensiuniLaptop, 2);
    l1.afisare();
    cout << endl;

    Laptop l2("HP", 8, 2.3, dimensiuniLaptop, 1);
    l2.afisare();
    cout << endl;

    Laptop l3("Dell", 32, 1.5, dimensiuniLaptop, 2);
    l3.afisare();
    cout << endl;

    return 0;
}
