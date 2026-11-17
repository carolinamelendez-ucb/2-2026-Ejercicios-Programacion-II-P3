#pragma once
#include "Perro.h"
class PerroPequenho :
    public Perro
{
public:
    PerroPequenho() : Perro() {
        this->codigo = "";
        this->nombre = "";
        this->raza = "";
        this->tamanio = "";
    }

};

