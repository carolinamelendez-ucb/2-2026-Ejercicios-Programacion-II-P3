#pragma once
#include "PaqueteNormal.h"
class PaqueteFragil :
    public PaqueteNormal
{
private:
    int nivelFragilidad;
    float costoEmbalaje;
public:
    PaqueteFragil(string codigo,string descripcion,float peso,float costoPorKilo,int nivelFragilidad);
    float calcularCosto()override;
    void mostrarDatos()override;
};

