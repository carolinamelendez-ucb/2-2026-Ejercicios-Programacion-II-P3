#pragma once
#include "Excepcion.h"

class EnvioNoEnconradoExcapcion :
    public Excepcion
{
private:
public:
    EnvioNoEnconradoExcapcion() {
        mensaje = "Envio No Enconrado Excapcion";
    }
};