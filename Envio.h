#include <iostream>
#include <string>
#include "Remitente.h"
#include "Paquete.h"
using namespace std;

class Envio {
private:
    string numero;
    string destino;
    Remitente* remitente;
    Paquete* paquete;
    float distancia;
    float costo;

public:
    Envio() {
        numero = "";
        destino = "";
        remitente = nullptr;
        paquete = nullptr;
        distancia = 0;
        costo = 0;
    }
    Envio(string numeroNuevo, string destinoNuevo, Remitente* r, Paquete* p, float distanciaNueva) {
        this->numero = numeroNuevo;
        this->destino = destinoNuevo;
        this->remitente = r;
        this->paquete = p;
        this->distancia = 0;
        this->costo = 0;

        setDistancia(distanciaNueva);
    }

    void setDistancia(float distanciaNueva) {
        if (distanciaNueva > 0) {
            distancia = distanciaNueva;
            calcularCostoFinal();
        } else {
            cout << "Error: la distancia debe ser mayor que 0" << endl;
        }
    }

    float calcularCostoBase() {
        return paquete->getPeso() * distancia * 0.50;
    }

    float calcularCostoFinal() {
        costo = calcularCostoBase();

        if (paquete->getTipoEnvio() == "EXPRESS") {
            costo = costo + costo * 0.25;
        }

        if (remitente->getTipoRemitente() == "EMPRESA") {
            costo = costo - costo * 0.10;
        }

        if (paquete->getPeso() > 10) {
            costo = costo + (paquete->getPeso() - 10) * 5;
        }

        return costo;
    }

    void mostrar() {
        cout << "Numero de envio: " << numero << endl;
        cout << "Destino: " << destino << endl;
        cout << "Distancia: " << distancia << " km" << endl;

        cout << endl << "DATOS DEL REMITENTE" << endl;
        remitente->mostrar();

        cout << endl << "DATOS DEL PAQUETE" << endl;
        paquete->mostrar();

        cout << "Costo del envio: " << costo << endl;
    }
};
