#pragma once
#include <iostream>
#include <string>
#include "Exception.h"

using namespace std;

class PerroNoEncontradoException : public Exception {
public:
    PerroNoEncontradoException() : Exception("Perro no encontrado en el sistema.") {}
};
