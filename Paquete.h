#include <iostream>
#include <string>
using namespace std;

class Paquete {
private:
    string codigo;
    float peso;
    string tipoEnvio;

public:
    Paquete() {
        codigo = "";
        peso = 0;
        tipoEnvio = "";
    }
    Paquete(string codigoNuevo, float pesoNuevo, string tipoNuevo) {
        this->codigo = codigoNuevo;
        this->peso = 0;
        this->tipoEnvio = "NORMAL";

        setPeso(pesoNuevo);
        setTipoEnvio(tipoNuevo);
    }

    void setPeso(float pesoNuevo) {
        if (pesoNuevo > 0) {
            peso = pesoNuevo;
        } else {
            cout << "Error: el peso debe ser mayor que 0" << endl;
        }
    }

    void setTipoEnvio(string tipoNuevo) {
        if (tipoNuevo == "NORMAL" || tipoNuevo == "EXPRESS") {
            tipoEnvio = tipoNuevo;
        } else {
            cout << "Error: el tipo de envio debe ser NORMAL o EXPRESS" << endl;
        }
    }

    float getPeso() {
        return peso;
    }

    string getTipoEnvio() {
        return tipoEnvio;
    }

    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "Tipo de envio: " << tipoEnvio << endl;
    }
};
