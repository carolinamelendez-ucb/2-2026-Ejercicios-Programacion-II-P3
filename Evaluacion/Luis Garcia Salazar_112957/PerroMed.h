#pragma once
#include "Perro.h"
class PerroMed :
    public Perro
{
public:
    PerroMed() : Perro() {
        this->codigo = "";
        this->nombre = "";
        this->raza = "";
        this->tamanio = "";
    }

};

