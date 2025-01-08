#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Televizor {
private:
    string brand;
    int diagonala;
    bool esteSmart;
    const int idTV;
    static string categorie;
    string* pretTV;
    int nrTV;

public:
    // Constructor default
    Televizor() : idTV(0) {
        this->brand = "anonim";
        this->diagonala = 0;
        this->esteSmart = false;
        this->pretTV = nullptr;
        this->nrTV = 0;
    }

    // Constructor cu parametru pentru brand
    Televizor(string brand) : idTV(1) {
        this->brand = brand;
        this->diagonala = 0;
        this->esteSmart = false;
        this->pretTV = nullptr;
        this->nrTV = 0;
    }

    // Constructor complet
    Televizor(string brand, int diagonala, bool esteSmart, string* pretTV, int nrTV) : idTV(123) {
        this->brand = brand;
        this->diagonala = diagonala;
        this->esteSmart = esteSmart;
        this->nrTV = nrTV;
        this->pretTV = new string[this->nrTV];
        for (int i = 0; i < this->nrTV; i++) {
            this->pretTV[i] = pretTV[i];
        }
    }

    // Destructor
    ~Televizor() {
        if (this->pretTV != nullptr) {
            delete[] this->pretTV;
        }
    }

    // Func?ia de afisare
    void afisare() const {
        cout << "Brand Televizor: " << this->brand << endl;
        cout << "Diagonala: " << this->diagonala << " inch" << endl;
        cout << "Este Smart: " << (this->esteSmart ? "DA" : "NU") << endl;
        cout << "ID Televizor: " << this->idTV << endl;
        cout << "Numar TV: " << this->nrTV << endl;
        cout << "Categorie: " << Televizor::categorie << endl;
    }

    Televizor(const Televizor& obj) : idTV(obj.idTV) {
        this->brand = obj.brand;
        this->diagonala = obj.diagonala;
        this->esteSmart = obj.esteSmart;
        this->nrTV = obj.nrTV;

        if (obj.pretTV != nullptr) {
            this->pretTV = new string[obj.nrTV];
            for (int i = 0; i < obj.nrTV; i++) {
                this->pretTV[i] = obj.pretTV[i];
            }
        }
        else {
            this->pretTV = nullptr;
        }
    }
    //operatorul =
    Televizor& operator=(const Televizor& obj) {
        if (this != &obj) {
            this->brand = obj.brand;
            this->diagonala = obj.diagonala;
            this->esteSmart = obj.esteSmart;
            this->nrTV = obj.nrTV;

            if (this->pretTV != nullptr) {
                delete[] this->pretTV;
            }

            if (obj.pretTV != nullptr) {
                this->pretTV = new string[obj.nrTV];
                for (int i = 0; i < obj.nrTV; i++) {
                    this->pretTV[i] = obj.pretTV[i];
                }
            }
            else {
                this->pretTV = nullptr;
            }
        }
        return *this;
    }
    // Operatorul << de afisare pe consola
    friend ostream& operator<<(ostream& out, const Televizor& obj) {
        out << "Brand Televizor: " << obj.brand << endl;
        out << "Diagonala: " << obj.diagonala << " inch" << endl;
        out << "Este Smart: " << (obj.esteSmart ? "DA" : "NU") << endl;
        out << "ID Televizor: " << obj.idTV << endl;
        out << "Numar TV: " << obj.nrTV << endl;
        out << "Categorie: " << obj.categorie << endl;
        out << "Preturi: ";
        if (obj.pretTV != nullptr) {
            for (int i = 0; i < obj.nrTV; i++) {
                out << obj.pretTV[i] << " ";
            }
        }
        else {
            out << "N/A";
        }
        out << endl;
        return out;
    }

    // Operatorul >> de citire de la tastatura
    friend istream& operator>>(istream& in, Televizor& obj) {
        cout << "Introduceti brandul: ";
        in >> obj.brand;
        cout << "Introduceti diagonala: ";
        in >> obj.diagonala;
        cout << "Este smart? (1 - DA, 0 - NU): ";
        in >> obj.esteSmart;
        if (obj.pretTV != nullptr) {
            delete[] obj.pretTV;
        }
        cout << "Introduceti numarul de televizoare: ";
        in >> obj.nrTV;
        obj.pretTV = new string[obj.nrTV];
        for (int i = 0; i < obj.nrTV; i++) {
            cout << "Introduceti pretul pentru TV " << i + 1 << ": ";
            in >> obj.pretTV[i];
        }
        return in;
    }
    //OPERATOR ++
	Televizor operator++() {
		this->diagonala++;
		return *this;
	}

    // --- Getterii ---
    string getBrand() {
        return this->brand;
    }

    int getDiagonala() {
        return this->diagonala;
    }

    bool getEsteSmart() {
        return this->esteSmart;
    }

    int getIdTV() {
        return this->idTV;
    }

    static string getCategorie() {
        return Televizor::categorie;
    }

    string* getPretTV() {
        return this->pretTV;
    }

    int getNrTV() {
        return this->nrTV;
    }

    // --- Setterii ---
    void setBrand(string brandNou) {
        this->brand = brandNou;
    }

    void setDiagonala(int diagonalaNoua) {
        this->diagonala = diagonalaNoua;
    }

    void setEsteSmart(bool esteSmartNou) {
        this->esteSmart = esteSmartNou;
    }

    static void setCategorie(string categorieNoua) {
        Televizor::categorie = categorieNoua;
    }

    void setPretTV(int nrNouTV, string* pretNou) {
        if (this->pretTV != nullptr) {
            delete[] this->pretTV;
        }
        this->nrTV = nrNouTV;
        this->pretTV = new string[nrTV];
        for (int i = 0; i < nrTV; i++) {
            this->pretTV[i] = pretNou[i];
        }
    }

    void setNrTV(int nrTVNou) {
        this->nrTV = nrTVNou;
    }
};
string Televizor::categorie = "ELECTROCASNICE";

class Telefon {
private:
    string model;
    int baterie;
    bool dualSIM;
    const int idTlf;
    static string categorie;
    int* pozitieRaft;
    int nrTelefoane;

public:
    // Constructor default
    Telefon() : idTlf(0) {
        this->model = "Anonim";
        this->baterie = 0;
        this->dualSIM = false;
        this->pozitieRaft = nullptr;
        this->nrTelefoane = 0;
    }

    // Constructor cu parametru pentru baterie
    Telefon(int baterie) : idTlf(1) {
        this->model = "Anonim";
        this->baterie = baterie;
        this->dualSIM = false;
        this->pozitieRaft = nullptr;
        this->nrTelefoane = 0;
    }

    // Constructor complet
    Telefon(string model, int baterie, bool dualSIM) : idTlf(0) {
        this->baterie = baterie;
        this->dualSIM = dualSIM;
        this->model = model;
        this->pozitieRaft = nullptr;
        this->nrTelefoane = 0;
    }
    // Destructor
    ~Telefon() {
        if (this->pozitieRaft != nullptr) {
            delete[] this->pozitieRaft;
        }
    }

    // Func?ia de afisare
    void afisare() const {
        cout << "Model: " << this->model << endl;
        cout << "Baterie: " << this->baterie << "%" << endl;
        cout << "Este dual SIM: " << (this->dualSIM ? "DA" : "NU") << endl;
        cout << "ID Telefon: " << this->idTlf << endl;
        cout << "Categorie: " << Telefon::categorie << endl;
    }

    Telefon(const Telefon& obj) : idTlf(obj.idTlf) {
        this->model = obj.model;
        this->baterie = obj.baterie;
        this->dualSIM = obj.dualSIM;
        this->nrTelefoane = obj.nrTelefoane;

        if (obj.pozitieRaft != nullptr) {
            this->pozitieRaft = new int[obj.nrTelefoane];
            for (int i = 0; i < obj.nrTelefoane; i++) {
                this->pozitieRaft[i] = obj.pozitieRaft[i];
            }
        }
        else {
            this->pozitieRaft = nullptr;
        }
    }
    //operator =
    Telefon& operator=(const Telefon& obj) {
        if (this != &obj) {
            this->model = obj.model;
            this->baterie = obj.baterie;
            this->dualSIM = obj.dualSIM;
            this->nrTelefoane = obj.nrTelefoane;

            if (this->pozitieRaft != nullptr) {
                delete[] this->pozitieRaft;
            }

            if (obj.pozitieRaft != nullptr) {
                this->pozitieRaft = new int[obj.nrTelefoane];
                for (int i = 0; i < obj.nrTelefoane; i++) {
                    this->pozitieRaft[i] = obj.pozitieRaft[i];
                }
            }
            else {
                this->pozitieRaft = nullptr;
            }
        }
        return *this;
    }
    // Operatorul << de afisare pe consola
    friend ostream& operator<<(ostream& out, const Telefon& obj) {
        out << "Model: " << obj.model << endl;
        out << "Baterie: " << obj.baterie << "%" << endl;
        out << "Este dual SIM: " << (obj.dualSIM ? "DA" : "NU") << endl;
        out << "ID Telefon: " << obj.idTlf << endl;
        out << "Categorie: " << obj.categorie << endl;
        out << "Pozitii pe raft: ";
        if (obj.pozitieRaft != nullptr) {
            for (int i = 0; i < obj.nrTelefoane; i++) {
                out << obj.pozitieRaft[i] << " ";
            }
        }
        else {
            out << "N/A";
        }
        out << endl;
        return out;
    }

    // Operatorul >> de citire de la tastatura
    friend istream& operator>>(istream& in, Telefon& obj) {
        cout << "Introduceti modelul: ";
        in >> obj.model;
        cout << "Introduceti bateria (in procent): ";
        in >> obj.baterie;
        cout << "Este dual SIM? (1 - DA, 0 - NU): ";
        in >> obj.dualSIM;

        // Citirea pozitiei rafturilor
        if (obj.pozitieRaft != nullptr) {
            delete[] obj.pozitieRaft;
        }
        cout << "Introduceti numarul de telefoane: ";
        in >> obj.nrTelefoane;
        obj.pozitieRaft = new int[obj.nrTelefoane];
        for (int i = 0; i < obj.nrTelefoane; i++) {
            cout << "Introduceti pozitia pe raft pentru telefonul " << i + 1 << ": ";
            in >> obj.pozitieRaft[i];
        }
        return in;
    }
	//OPERATOR !
    friend void operator!(Telefon& obj) {
        if (obj.dualSIM == 1) {
            obj.dualSIM = 0; // Dac? era dual SIM, îl facem SIM unic
        }
        else {
            obj.dualSIM = 1; // Dac? era SIM unic, îl facem dual SIM
        }
    }

    // --- Getterii ---
    string getModel() {
        return this->model;
    }

    int getBaterie() {
        return this->baterie;
    }

    bool getDualSIM() {
        return this->dualSIM;
    }

    int getIdTlf() {
        return this->idTlf;
    }

    static string getCategorie() {
        return Telefon::categorie;
    }

    int* getPozitieRaft() {
        return this->pozitieRaft;
    }

    int getNrTelefoane() {
        return this->nrTelefoane;
    }

    // --- Setterii ---
    void setModel(string modelNou) {
        this->model = modelNou;
    }

    void setBaterie(int baterieNoua) {
        this->baterie = baterieNoua;
    }

    void setDualSIM(bool dualSIMNou) {
        this->dualSIM = dualSIMNou;
    }

    static void setCategorie(string categorieNoua) {
        Telefon::categorie = categorieNoua;
    }

    void setPozitieRaft(int nrNou, int* pozitiiNoi) {
        if (this->pozitieRaft != nullptr) {
            delete[] this->pozitieRaft;
        }
        this->nrTelefoane = nrNou;
        this->pozitieRaft = new int[nrTelefoane];
        for (int i = 0; i < nrTelefoane; i++) {
            this->pozitieRaft[i] = pozitiiNoi[i];
        }
    }

    void setNrTelefoane(int nrNou) {
        this->nrTelefoane = nrNou;
    }
};
string Telefon::categorie = "ELECTROCASNICE";

class Laptop {
private:
    string brand;
    int RAM;
    float greutate;
    static string categorie;
    const int id;
    float* dimensiuni;
    int nrLaptopuri;

public:
    // Constructor default
    Laptop() : id(0) {
        this->brand = "Anonim";
        this->RAM = 0;
        this->greutate = 0;
        this->dimensiuni = nullptr;
        this->nrLaptopuri = 0;
    }

    // Constructor cu parametru pentru brand
    Laptop(string brand) : id(1) {
        this->brand = brand;
        this->RAM = 0;
        this->greutate = 0;
        this->dimensiuni = nullptr;
        this->nrLaptopuri = 0;
    }

    // Constructor complet
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

    // Destructor
    ~Laptop() {
        if (this->dimensiuni != nullptr) {
            delete[] this->dimensiuni;
        }
    }

    // Func?ia de afisare
    void afisare() const {
        cout << "Brand Laptop: " << this->brand << endl;
        cout << "RAM: " << this->RAM << " GB" << endl;
        cout << "Greutate: " << this->greutate << " kg" << endl;
        cout << "ID Laptop: " << this->id << endl;
        cout << "Categorie: " << Laptop::categorie << endl;
    }
    Laptop(const Laptop& obj) : id(obj.id) {
        this->brand = obj.brand;
        this->RAM = obj.RAM;
        this->greutate = obj.greutate;
        this->nrLaptopuri = obj.nrLaptopuri;

        if (obj.dimensiuni != nullptr) {
            this->dimensiuni = new float[obj.nrLaptopuri];
            for (int i = 0; i < obj.nrLaptopuri; i++) {
                this->dimensiuni[i] = obj.dimensiuni[i];
            }
        }
        else {
            this->dimensiuni = nullptr;
        }
    }
    //operator =
    Laptop& operator=(const Laptop& obj) {
        if (this != &obj) {
            this->brand = obj.brand;
            this->RAM = obj.RAM;
            this->greutate = obj.greutate;
            this->nrLaptopuri = obj.nrLaptopuri;

            if (this->dimensiuni != nullptr) {
                delete[] this->dimensiuni;
            }

            if (obj.dimensiuni != nullptr) {
                this->dimensiuni = new float[obj.nrLaptopuri];
                for (int i = 0; i < obj.nrLaptopuri; i++) {
                    this->dimensiuni[i] = obj.dimensiuni[i];
                }
            }
            else {
                this->dimensiuni = nullptr;
            }
        }
        return *this;
    }
    // Operatorul << de afisare pe consola
    friend ostream& operator<<(ostream& out, const Laptop& obj) {
        out << "Brand Laptop: " << obj.brand << endl;
        out << "RAM: " << obj.RAM << " GB" << endl;
        out << "Greutate: " << obj.greutate << " kg" << endl;
        out << "ID Laptop: " << obj.id << endl;
        out << "Categorie: " << obj.categorie << endl;
        out << "Dimensiuni: ";
        if (obj.dimensiuni != nullptr) {
            for (int i = 0; i < obj.nrLaptopuri; i++) {
                out << obj.dimensiuni[i] << " ";
            }
        }
        else {
            out << "N/A";
        }
        out << endl;
        return out;
    }

    // Operatorul >> de citire de la tastatura
    friend istream& operator>>(istream& in, Laptop& obj) {
        cout << "Introduceti brandul: ";
        in >> obj.brand;
        cout << "Introduceti RAM-ul: ";
        in >> obj.RAM;
        cout << "Introduceti greutatea: ";
        in >> obj.greutate;

        // Citirea dimensiunilor
        if (obj.dimensiuni != nullptr) {
            delete[] obj.dimensiuni;
        }
        cout << "Introduceti numarul de laptopuri: ";
        in >> obj.nrLaptopuri;
        obj.dimensiuni = new float[obj.nrLaptopuri];
        for (int i = 0; i < obj.nrLaptopuri; i++) {
            cout << "Introduceti dimensiunea pentru laptopul " << i + 1 << " (in inch): ";
            in >> obj.dimensiuni[i];
        }
        return in;
    }

    // --- Getterii ---
    string getBrand() {
        return this->brand;
    }

    int getRAM() {
        return this->RAM;
    }

    float getGreutate() {
        return this->greutate;
    }

    int getId() {
        return this->id;
    }

    static string getCategorie() {
        return Laptop::categorie;
    }

    float* getDimensiuni() {
        return this->dimensiuni;
    }

    int getNrLaptopuri() {
        return this->nrLaptopuri;
    }

    // --- Setterii ---
    void setBrand(string brandNou) {
        this->brand = brandNou;
    }

    void setRAM(int RAMNou) {
        this->RAM = RAMNou;
    }

    void setGreutate(float greutateNoua) {
        this->greutate = greutateNoua;
    }

    static void setCategorie(string categorieNoua) {
        Laptop::categorie = categorieNoua;
    }

    void setDimensiuni(int nrNouLaptopuri, float* dimensiuniNoi) {
        if (this->dimensiuni != nullptr) {
            delete[] this->dimensiuni;
        }
        this->nrLaptopuri = nrNouLaptopuri;
        this->dimensiuni = new float[nrLaptopuri];
        for (int i = 0; i < nrLaptopuri; i++) {
            this->dimensiuni[i] = dimensiuniNoi[i];
        }
    }

    void setNrLaptopuri(int nrNouLaptopuri) {
        this->nrLaptopuri = nrNouLaptopuri;
    }
    // OPERATORUL CAST LA STRING
    operator string() const {
        float dimensiuneMaxima = this->dimensiuni[0];  
        string produsDimensiuneMaxima = "Laptop 1";  
        for (int i = 1; i < this->nrLaptopuri; i++) {
            if (this->dimensiuni[i] > dimensiuneMaxima) {
                dimensiuneMaxima = this->dimensiuni[i];
                produsDimensiuneMaxima = "Laptop " + to_string(i + 1);  
            }
        }

        
        return produsDimensiuneMaxima;
    }

};
string Laptop::categorie = "ELECTROCASNICE";


        int main() {
            cout << "--------------------------------APEL CONSTRUCTORI--------------------------" << endl << endl;

            string preturiTV[] = { "2000", "2500", "3000" };
            Televizor TV1;
            TV1.afisare();
            cout << endl;

            Televizor TV2("LG");
            TV2.afisare();
            cout << endl;

            Televizor TV3("Sony", 65, true, preturiTV, 3);
            TV3.afisare();
            cout << endl;

            int pozitii[] = { 1, 2, 3 };
            Telefon TLF1;
            TLF1.afisare();
            cout << endl;

            Telefon TLF2(85);
            TLF2.afisare();
            cout << endl;

            Telefon TLF3("iPhone", 90, true);
            TLF3.afisare();
            cout << endl;

            float dimensiuni[] = { 15.6, 17.3, 13.3 };
            Laptop LAPTOP1;
            LAPTOP1.afisare();
            cout << endl;

            Laptop LAPTOP2("Asus");
            LAPTOP2.afisare();
            cout << endl;

            Laptop LAPTOP3("HP", 8, 1.8, dimensiuni, 3);
            LAPTOP3.afisare();
            cout << endl;

            cout << "--------------------------------APEL SETTERI--------------------------" << endl << endl;

            cout << "Obiectul TV1 inainte de a apela setterii:" << endl << endl;
            TV1.afisare();
            cout << endl;

            TV1.setBrand("Samsung");
            TV1.setDiagonala(55);
            TV1.setEsteSmart(true);
            TV1.setNrTV(4);
            string preturiTVNew[] = { "1200", "1500", "1800", "2200" };
            TV1.setPretTV(4, preturiTVNew);
            Televizor::setCategorie("LED");
            cout << "Obiectul TV1 dupa ce au fost apelati setterii:" << endl << endl;
            TV1.afisare();
            cout << endl;

            cout << "Obiectul TLF1 inainte de a apela setterii:" << endl << endl;
            TLF1.afisare();
            cout << endl;

            TLF1.setModel("Nokia");
            TLF1.setBaterie(75);
            TLF1.setDualSIM(true);
            TLF1.setNrTelefoane(5);
            int pozitiiNou[] = { 1, 4, 5, 2, 3 };
            TLF1.setPozitieRaft(5, pozitiiNou);
            Telefon::setCategorie("SMARTPHONE");
            cout << "Obiectul TLF1 dupa ce au fost apelati setterii:" << endl << endl;
            TLF1.afisare();
            cout << endl;

            cout << "Obiectul LAPTOP1 inainte de a apela setterii:" << endl << endl;
            LAPTOP1.afisare();
            cout << endl;

            LAPTOP1.setBrand("Lenovo");
            LAPTOP1.setRAM(16);
            LAPTOP1.setGreutate(2.3);
            LAPTOP1.setNrLaptopuri(4);
            float dimensiuniNoi[] = { 14.0, 13.3, 17.3, 15.0 };
            LAPTOP1.setDimensiuni(4, dimensiuniNoi);
            Laptop::setCategorie("LAPTOP GAMING");
            cout << "Obiectul LAPTOP1 dupa ce au fost apelati setterii:" << endl << endl;
            LAPTOP1.afisare();
            cout << endl;

      
			cout << "--------------------------------APEL operator =-------------------------" << endl << endl;
            Televizor TV4;
            TV4 = TV1;  
            cout << "TV4 dupa apelul operatorului = devine TV1" << endl;
            TV4.afisare();
            cout << endl;
            Telefon TLF4;
            TLF4 = TLF1;  
            cout << "TLF4 dupa operatorul = = devine TLF1:" << endl;
            TLF4.afisare();
            cout << endl;
            Laptop LAPTOP4;
            LAPTOP4 = LAPTOP1;  
            cout << "LAPTOP4 devine LAPTOP1  dupa operatorul =" << endl;
            LAPTOP4.afisare();
            cout << endl;

            cout << "--------------------------------Operatorul <<-------------------------" << endl << endl;
            cout << "Obiectul TV1:" << endl << TV1 << endl << endl;

            cout << "--------------------------------Operatorul >>-------------------------" << endl << endl;
            cout << "Obiectul TV2 nainte de a fi citit de la tastatura:" << endl << TV2 << endl << endl;

            cout << endl;

            cout << "Obiectul TV1 dupa ce a fost citit de la tastatura:" << endl << TV1 << endl << endl;

            cout << "--------------------------------Operatorul <<-------------------------" << endl << endl;
            cout << "Obiectul TLF 2:" << endl << TLF2 << endl << endl;

            cout << "--------------------------------Operatorul >>-------------------------" << endl << endl;
            cout << "Obiectul TLF3 inainte de a fi citit de la tastatura:" << endl << TLF3 << endl << endl;

            cout << endl;

            cout << "Obiectul TLF2 dupa ce a fost citit de la tastatura:" << endl << TLF2 << endl << endl;

            cout << "--------------------------------Operatorul <<-------------------------" << endl << endl;
            cout << "Obiectul LAPTOP1:" << endl << LAPTOP1 << endl << endl;

            cout << "--------------------------------Operatorul >>-------------------------" << endl << endl;
            cout << "Obiectul LAPTOP2 inainte de a fi citit de la tastatura:" << endl << LAPTOP2<< endl << endl;

          
            cout << endl;

            cout << "Obiectul LAPTOP1 dupa ce a fost citit de la tastatura:" << endl << LAPTOP1 << endl << endl;

            cout << "--------------------------------Operatorul ! - de negatie-------------------------" << endl << endl;
            cout << "Obiectul TLF2 este dual SIM? (1-DA ; 0-NU): " << TLF2.getDualSIM() << endl;
            !TLF2;
            cout << "Obiectul TLF2 este dual SIM? (1-DA ; 0-NU): " << TLF2.getDualSIM() << endl;
            cout << endl << endl;
            cout << "--------------------------------Operatorul de cast la string-------------------------" << endl << endl;
            cout << "Afisare laptop LAPTOP2:" << endl;
            LAPTOP2.afisare();
            cout << endl;
            cout << "Denumirea produsului cu dimensiunea maxima  este:" << (string)LAPTOP2 << endl;
            cout << endl << endl;

            return 0;
        }


    


  
