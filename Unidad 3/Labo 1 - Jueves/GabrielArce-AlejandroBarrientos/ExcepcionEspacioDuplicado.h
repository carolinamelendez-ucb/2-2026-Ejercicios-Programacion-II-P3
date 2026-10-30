#pragma once
#include "Excepcion.h"
class ExcepcionEspacioDuplicado :
    public Excepcion
{
private:

public:
    ExcepcionEspacioDuplicado() {
        mensaje = "Pusiste un codigo duplicado no se pueden registrar. ";
    }
};

