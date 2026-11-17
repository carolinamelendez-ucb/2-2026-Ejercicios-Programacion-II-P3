#pragma once
#include "Exception.h"
class CapacidadMaximaException :
    public Exception
{
public:
    CapacidadMaximaException() {
        this->mensaje = "Se alcanzo la capacidad maxima";
    }

    string getMensaje() {
        return mensaje;
    }
};

