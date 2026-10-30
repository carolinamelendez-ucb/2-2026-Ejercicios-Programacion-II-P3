#pragma once
#include "Excepcion.h"
class ExcepcionVehiculoDuplicado :
    public Excepcion
{
private:

public:
    ExcepcionVehiculoDuplicado() {
        mensaje = "Pusiste una placa duplicada no se pueden registrar. ";
    }
};

