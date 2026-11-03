#pragma once
#include "PaqueteNormal.h"
class PaqueteExpress :
    public PaqueteNormal
{
private:
    int horasEntrega;
    float costoPrioridad;
public:
    PaqueteExpress(string codigo,string descripcion,float peso,float costoPorKilo,int horasEntrega);
    float calcularCosto()override;
    void mostrarDatos()override;
};

