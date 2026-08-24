#ifndef ENVIO_H
#define ENVIO_H

#include <string>

#include "Remitente.h"
#include "Paquete.h"

using namespace std;

class Envio {

private:

    int numero;
    string destino;

    Remitente* remitente;
    Paquete* paquete;

    double distancia;
    double costo;

public:

    Envio(
        int numero,
        string destino,
        Remitente* remitente,
        Paquete* paquete,
        double distancia
    );

    double calcularCostoBase();

    void calcularCosto();

    void setDistancia(double nuevaDistancia);

    void setTipoEnvio(TipoEnvio nuevoTipo);

    void setTipoRemitente(TipoRemitente nuevoTipo);

    double getDistancia();

    double getCosto();

    void mostrarInformacion();
};

#endif