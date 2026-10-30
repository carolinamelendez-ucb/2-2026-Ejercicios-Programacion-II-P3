#pragma once
#include "Excepcion.h"
class ExcepcionCapacidadMaximaVehiculos :
    public Excepcion
{
private:

public:
    ExcepcionCapacidadMaximaVehiculos() {
        mensaje = "Excediste el limite de vehiculos que se pueden registrar. ";
    }
};

