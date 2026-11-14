#pragma once
#include "Excepcion.h"

class ExcepcionDuplicado :
    public Excepcion {
private:
public:
    ExcepcionDuplicado() {
        mensaje = "Ya existe un perro con esos atributos";
    }
    ~ExcepcionDuplicado() {};
    string getMensaje() {
        return mensaje;
    }
};