#pragma once
#include "Exception.h"
class ServicioDuplicadoException :
    public Exception
{
public:
    ServicioDuplicadoException(string codigo) : Exception() {
        mensaje = "Ya existe un servicio registrado " + codigo;
    }
};
