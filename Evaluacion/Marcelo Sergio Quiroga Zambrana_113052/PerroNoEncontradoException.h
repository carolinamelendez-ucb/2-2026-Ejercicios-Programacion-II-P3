#pragma once
#include "Exception.h"
class PerroNoEncontradoException :
    public Exception
{
public:
    PerroNoEncontradoException():Exception() {
        this->mensaje = "El perro no ha sido encontrado en el registro";
    }
};

