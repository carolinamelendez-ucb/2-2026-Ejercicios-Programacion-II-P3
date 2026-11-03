#pragma once
#include "Exception.h"
class ClienteDuplicadoException :
    public Exception
{
public:
    ClienteDuplicadoException() {
        this->mensaje = "El CI es repetido.";
    }
};

