#include "Paquete.h"
#include <iostream>

using namespace std;

// Constructor
Paquete::Paquete(string codigo, double peso, TipoEnvio tipoEnvio) {

    this->codigo = codigo;

    if (peso > 0) {
        this->peso = peso;
    }
    else {
        cout << "El peso debe ser mayor que 0." << endl;
        this->peso = 0;
    }

    this->tipoEnvio = tipoEnvio;
}

// Setter peso
void Paquete::setPeso(double nuevoPeso) {

    if (nuevoPeso > 0) {
        peso = nuevoPeso;
    }
    else {
        cout << "El peso debe ser mayor que 0." << endl;
    }
}

// Setter tipo de envío
void Paquete::setTipoEnvio(TipoEnvio nuevoTipo) {

    if (nuevoTipo == NORMAL || nuevoTipo == EXPRESS) {
        tipoEnvio = nuevoTipo;
    }
    else {
        cout << "Tipo de envio invalido." << endl;
    }
}

// Getters
string Paquete::getCodigo() {
    return codigo;
}

double Paquete::getPeso() {
    return peso;
}

TipoEnvio Paquete::getTipoEnvio() {
    return tipoEnvio;
}

// Mostrar información
void Paquete::mostrarInformacion() {

    cout << "----- PAQUETE -----" << endl;

    cout << "Codigo: " << codigo << endl;

    cout << "Peso: "
        << peso
        << " kg"
        << endl;

    cout << "Tipo de envio: "
        << mostrarTipoEnvio(tipoEnvio)
        << endl;
}

// Convertir enum a texto
string mostrarTipoEnvio(TipoEnvio tipo) {

    switch (tipo) {

    case NORMAL:
        return "NORMAL";

    case EXPRESS:
        return "EXPRESS";

    default:
        return "DESCONOCIDO";
    }
}