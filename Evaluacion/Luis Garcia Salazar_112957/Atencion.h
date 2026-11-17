#pragma once
#include <iostream>
#include <string>
#include "Perro.h"
#include "Servicio.h"

using namespace std;

class Atencion

{
protected:
	string codigo;
    int costoFinal;
    Perro* perro;
    Servicio* servicio;

public:

    Atencion(string codigo, int costeFinal) {
        this->codigo = codigo;
        this->costoFinal = costeFinal;
        this->perro = perro;
        this->servicio = servicio;
    }



};