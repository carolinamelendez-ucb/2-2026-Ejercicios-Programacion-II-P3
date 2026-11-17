#pragma once
#include <iostream>
#include <string>
using namespace std;

class Exception {
protected:
    string mensaje;

public:
    Exception() {
        mensaje = "Error Desconocido en el sistema.";
    }

    string getMensaje() {
        return mensaje;
    }
};