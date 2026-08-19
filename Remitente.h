#include <iostream>
#include <string>
using namespace std;

class Remitente {
private:
    string ci;
    string nombre;
    string tipoRemitente;

public:
    Remitente() {
        ci = "";
        nombre = "";
        tipoRemitente = "";
    }
    Remitente(string ciNuevo, string nombreNuevo) {
        this->ci = ciNuevo;
        this->nombre = nombreNuevo;
        this->tipoRemitente = "PARTICULAR";
    }

    void setTipoRemitente(string tipoNuevo) {
        if (tipoNuevo == "PARTICULAR" || tipoNuevo == "EMPRESA") {
            tipoRemitente = tipoNuevo;
        } else {
            cout << "Error: el tipo de remitente debe ser PARTICULAR o EMPRESA" << endl;
        }
    }

    string getTipoRemitente() {
        return tipoRemitente;
    }

    void mostrar() {
        cout << "CI: " << ci << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo de remitente: " << tipoRemitente << endl;
    }
};
