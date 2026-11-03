#pragma once
#include "Excepcion.h"

class ExcepcionClienteDupicado :
    public Excepcion
{
private:
public:
    ExcepcionClienteDupicado() {
        mensaje = "Excepcion Cliente Dupicado";
    }
};

