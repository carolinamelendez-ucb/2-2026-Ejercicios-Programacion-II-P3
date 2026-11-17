#pragma once
#include "Servicio.h"
class ServicioBanio :
    public Servicio
{
private:
    double costoProductos;
public:
    ServicioBanio(string codigo,string nombre,double costoProductos);
    double getCosto()override;
    void mostrarDatos()override;
};

