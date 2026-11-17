#pragma once
#include <iostream>
#include <string>

using namespace std;


class Exception {
protected:
    string mensaje;
public:
    Exception(string m = "Error en el sistema.") : mensaje(m) {}
    string getMensaje() { return mensaje; }
};
