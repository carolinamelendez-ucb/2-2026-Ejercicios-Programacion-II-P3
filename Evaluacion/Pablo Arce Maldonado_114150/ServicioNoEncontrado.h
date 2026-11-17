#pragma once
#include <iostream>
#include <string>
#include "Exception.h"

using namespace std;

class ServicioNoEncontradoException : public Exception {
public:
    ServicioNoEncontradoException() : Exception("Servicio no encontrado en el sistema.") {}
};
