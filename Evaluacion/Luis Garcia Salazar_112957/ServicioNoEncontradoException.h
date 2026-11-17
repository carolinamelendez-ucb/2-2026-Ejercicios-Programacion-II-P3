#pragma once
#include "Exception.h"
class ServicioNoEncontradoException :
    public Exception
{
public:
    ServicioNoEncontradoException(string codigo) : Exception() {
        mensaje = "El servicio no se ha encontrado " + codigo;
    }
};

