#pragma once
#include "Exception.h"
class TamanioNoValidoException :
    public Exception
{
public:
    TamanioNoValidoException() :Exception() {
        this->mensaje = "El tamanio no es valido.";
    }
};

