#pragma once
#include "Excepcion.h"

class ExcepcionPerroNoEncontrado :
    public Excepcion {
private:
public:
    ExcepcionPerroNoEncontrado() {
        mensaje = "El perro que buscas no ha sido encontrado";
    }
    ~ExcepcionPerroNoEncontrado() {};
    string getMensaje() {
        return mensaje;
    }
};