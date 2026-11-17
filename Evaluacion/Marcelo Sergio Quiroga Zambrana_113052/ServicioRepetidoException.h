#pragma once
#include "Exception.h"
class ServicioRepetidoException :
    public Exception
{
public:
    ServicioRepetidoException():Exception() {
        this->mensaje = "El servicio ya existe en el registro";
    }
};

