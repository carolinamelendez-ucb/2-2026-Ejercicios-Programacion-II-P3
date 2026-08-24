#include "Remitente.h"
#include <iostream>

using namespace std;

// Constructor
Remitente::Remitente(string ci, string nombre) {

    this->ci = ci;
    this->nombre = nombre;

    // Valor inicial
    this->tipoRemitente = PARTICULAR;
}

// Setter
void Remitente::setTipoRemitente(TipoRemitente nuevoTipo) {

    if (nuevoTipo == PARTICULAR || nuevoTipo == EMPRESA) {
        tipoRemitente = nuevoTipo;
    }
    else {
        cout << "Tipo de remitente invalido." << endl;
    }
}

// Getters
string Remitente::getCi() {
    return ci;
}

string Remitente::getNombre() {
    return nombre;
}

TipoRemitente Remitente::getTipoRemitente() {
    return tipoRemitente;
}

// Mostrar información
void Remitente::mostrarInformacion() {

    cout << "----- REMITENTE -----" << endl;

    cout << "CI: " << ci << endl;
    cout << "Nombre: " << nombre << endl;

    cout << "Tipo: "
        << mostrarTipoRemitente(tipoRemitente)
        << endl;
}

// Convertir enum a texto
string mostrarTipoRemitente(TipoRemitente tipo) {

    switch (tipo) {

    case PARTICULAR:
        return "PARTICULAR";

    case EMPRESA:
        return "EMPRESA";

    default:
        return "DESCONOCIDO";
    }
}