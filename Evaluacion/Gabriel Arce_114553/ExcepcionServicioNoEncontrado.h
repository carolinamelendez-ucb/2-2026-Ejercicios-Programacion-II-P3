#pragma once
#include "Excepcion.h"

class ExcepcionServicioNoEncontrado :
    public Excepcion {
private:
public:
    ExcepcionServicioNoEncontrado() {
        mensaje = "El servicio que buscas no ha sido encontrado";
    }
    ~ExcepcionServicioNoEncontrado() {};
    string getMensaje() {
        return mensaje;
    }
};