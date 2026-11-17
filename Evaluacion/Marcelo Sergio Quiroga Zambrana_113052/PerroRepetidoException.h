#pragma once
#include "Exception.h"
class PerroRepetidoException :
    public Exception
{
public:
    PerroRepetidoException():Exception() {
        this->mensaje = "El perro ya existe en el registro";
    }
};

