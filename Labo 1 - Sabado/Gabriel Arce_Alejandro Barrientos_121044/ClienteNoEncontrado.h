#pragma once
#include "Excepcion.h"

class ClienteNoEncontrado :
    public Excepcion
{
private:
public:
    ClienteNoEncontrado() {
        mensaje = "Cliente No Encontrado";
    }
};

