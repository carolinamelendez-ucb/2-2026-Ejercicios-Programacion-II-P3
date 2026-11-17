#pragma once
#include "Exception.h"
class ServicioDuplicadoException :
    public Exception
{
public:
    ServicioDuplicadoException() {
        this->mensaje = "El codigo del servicio ya se encuentra en el sitema";
    }

    string getMensaje() {
        return mensaje;
    }
};

