#pragma once
#include "Excepcion.h"

class PaqueteDuplicadoExcepcion :
    public Excepcion
{
private:
public:
    PaqueteDuplicadoExcepcion() {
        mensaje = "Paquete Duplicado Excepcion";
    }
};
