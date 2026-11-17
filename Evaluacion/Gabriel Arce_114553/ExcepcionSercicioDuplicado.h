#pragma once
#include "Excepcion.h"

class ExcepcionServicioDuplicado :
    public Excepcion {
private:
public:
    ExcepcionServicioDuplicado() {
        mensaje = "Ya existe un servicio con esos atributos";
    }
    ~ExcepcionServicioDuplicado() {};
    string getMensaje() {
        return mensaje;
    }
};