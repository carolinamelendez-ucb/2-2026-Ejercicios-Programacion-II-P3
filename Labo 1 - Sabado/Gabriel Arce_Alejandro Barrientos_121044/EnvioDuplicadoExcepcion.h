#pragma once
#include "Excepcion.h"

class EnvioDuplicadoExcepcion :
    public Excepcion
{
private:
public:
    EnvioDuplicadoExcepcion() {
        mensaje = "Envio Duplicado Excepcion";
    }
};

