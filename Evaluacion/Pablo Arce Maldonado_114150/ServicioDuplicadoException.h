#pragma once
#include <iostream>
#include <string>
#include "Exception.h"

using namespace std;

class ServicioDuplicadoException : public Exception {
public:
    ServicioDuplicadoException(string cod) : Exception("El Servicio " + cod + " ya esta registrado.") {}
};
