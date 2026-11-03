#include <iostream>
#include <string>
#include "Sistema.h"
#include <stdexcept>

int main() {
    ListaGenerica<Cliente> Clientes;
    ListaGenerica<Paquete> Paquetes;
    ListaGenerica<Envio> envios;
    int edad = 18;
    string codigo = "ABC";
    int semanas = 0;

    try {
        if (edad < 0) {
            throw runtime_error("Edad invalida");
        }

        if (codigo == "ABC") {
            throw runtime_error("Codigo duplicado");
        }

        if (semanas < 1) {
            throw runtime_error("Semanas invalidas");
        }

        cout << "Registro correcto";

    }
    catch (const exception& e) {
        cout << "Error: " << e.what();
    }
}