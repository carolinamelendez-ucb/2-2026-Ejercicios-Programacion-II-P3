#pragma once
#include "Perro.h"
class PerroGrande :
    public Perro
{
public:
    PerroGrande() : Perro() {
        this->codigo = "";
        this->nombre = "";
        this->raza = "";
        this->tamanio = "";
    }

};

