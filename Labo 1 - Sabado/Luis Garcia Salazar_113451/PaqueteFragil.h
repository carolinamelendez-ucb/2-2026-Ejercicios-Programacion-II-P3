#pragma once
#include "Paquete.h"
class PaqueteFragil :
    public Paquete
{
private:
    string nivelFragilidad;
    int costoEmbalaje;
public:
    PaqueteFragil():Paquete(codigoPaquete, descripcion ,peso ,costoPorKg ) {
        this->codigoPaquete = codigoPaquete;
        this->descripcion = descripcion;
        this->peso = peso;
        this->costoPorKg = costoPorKg;
        this->nivelFragilidad = "";
        this->costoEmbalaje = 0;
    }

    void obtenerCosto() {
        int costoTotal;
        if (nivelFragilidad== "Bajo")
        {
            costoEmbalaje = 5;
        }
        else if (nivelFragilidad == "Medio")
        {
            costoEmbalaje = 10;
        }
        else if (nivelFragilidad == "Alto")
        {
            costoEmbalaje = 20;
        }
        costoTotal = peso * costoPorKg + costoEmbalaje;
    }
};

