#pragma once
#include "Exception.h"

class PerroNoEncontradoException : public Exception {
public:
    PerroNoEncontradoException(string codigo) : Exception() {
        mensaje = "No se encontro un ninio con el CI: " + codigo;
    }
};