#pragma once
#include "Exception.h"
class ServicioNoEncontradoException :
    public Exception
{
public:
    ServicioNoEncontradoException():Exception() {
        this->mensaje = "El servicio no ha sido encontrado en el registro";
    }
};

