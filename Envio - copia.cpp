#include "Envio.h"

#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
Envio::Envio(
    int numero,
    string destino,
    Remitente* remitente,
    Paquete* paquete,
    double distancia
) {

    this->numero = numero;
    this->destino = destino;

    this->remitente = remitente;
    this->paquete = paquete;

    if (distancia > 0) {
        this->distancia = distancia;
    }
    else {
        cout << "La distancia debe ser mayor que 0."
            << endl;

        this->distancia = 0;
    }

    calcularCosto();
}


// =====================================================
// COSTO BASE
// =====================================================

double Envio::calcularCostoBase() {

    return paquete->getPeso()
        * distancia
        * 0.50;
}


// =====================================================
// COSTO FINAL
// =====================================================

void Envio::calcularCosto() {

    // Costo inicial
    costo = calcularCostoBase();


    // Envío EXPRESS
    if (paquete->getTipoEnvio() == EXPRESS) {

        costo = costo * 1.25;
    }


    // Remitente EMPRESA
    if (remitente->getTipoRemitente() == EMPRESA) {

        costo = costo * 0.90;
    }


    // Más de 10 kg
    if (paquete->getPeso() > 10) {

        double kilosExtra =
            paquete->getPeso() - 10;

        double costoExtra =
            kilosExtra * 5;

        costo = costo + costoExtra;
    }
}


// =====================================================
// SET DISTANCIA
// =====================================================

void Envio::setDistancia(double nuevaDistancia) {

    if (nuevaDistancia > 0) {

        distancia = nuevaDistancia;

        calcularCosto();

    }
    else {

        cout << "La distancia debe ser mayor que 0."
            << endl;
    }
}


// =====================================================
// SET TIPO ENVIO
// =====================================================

void Envio::setTipoEnvio(TipoEnvio nuevoTipo) {

    if (nuevoTipo == NORMAL || nuevoTipo == EXPRESS) {

        paquete->setTipoEnvio(nuevoTipo);

        calcularCosto();
    }
}


// =====================================================
// SET TIPO REMITENTE
// =====================================================

void Envio::setTipoRemitente(TipoRemitente nuevoTipo) {

    if (nuevoTipo == PARTICULAR || nuevoTipo == EMPRESA) {

        remitente->setTipoRemitente(nuevoTipo);

        calcularCosto();
    }
}


// =====================================================
// GETTERS
// =====================================================

double Envio::getDistancia() {
    return distancia;
}

double Envio::getCosto() {
    return costo;
}


// =====================================================
// MOSTRAR INFORMACION
// =====================================================

void Envio::mostrarInformacion() {

    cout << endl;

    cout << "===================================="
        << endl;

    cout << "          INFORMACION ENVIO"
        << endl;

    cout << "===================================="
        << endl;

    cout << "Numero: "
        << numero
        << endl;

    cout << "Destino: "
        << destino
        << endl;

    cout << endl;

    remitente->mostrarInformacion();

    cout << endl;

    paquete->mostrarInformacion();

    cout << endl;

    cout << "Distancia: "
        << distancia
        << " km"
        << endl;

    cout << fixed << setprecision(2);

    cout << "Costo base: $"
        << calcularCostoBase()
        << endl;

    cout << "Costo final: $"
        << costo
        << endl;

    cout << "===================================="
        << endl;
}