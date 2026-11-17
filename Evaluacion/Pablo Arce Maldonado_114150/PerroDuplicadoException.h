#pragma once
#include <iostream>
#include <string>
#include "Exception.h"

using namespace std;


class PerroDuplicadoException : public Exception {
public:
    PerroDuplicadoException() : Exception("El perro ya esta registrado") {}
};
