#pragma once
#include "Excepcion.h"
class ExcepcionCapacidadMaximaEspacios :
    public Excepcion
{
private:
    
public:
    ExcepcionCapacidadMaximaEspacios() {
        mensaje = "Excediste el limite de espacios que se pueden registrar. ";
    }
};

