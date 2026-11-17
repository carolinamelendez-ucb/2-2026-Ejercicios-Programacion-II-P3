#pragma once
#include "Exception.h"
class PerroDuplicadoException :
    public Exception
{
public:
    PerroDuplicadoException() {
        this->mensaje = "El codigo del perro ya se encuentra en el sistema";
    }

    string getMensaje() {
        return mensaje;
    }
};

