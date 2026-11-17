#pragma once
#include "Exception.h"


class PerroDuplicadoException : public Exception {
public:
    PerroDuplicadoException(string codigo) : Exception() {
        mensaje = "Ya existe un perro registrado " + codigo;
    }
};