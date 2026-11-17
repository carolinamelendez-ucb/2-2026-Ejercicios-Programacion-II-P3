#pragma once
#include "Servicio.h"
class ServicioCorte :
    public Servicio
{
private:
    double costoCorte;
public:
    ServicioCorte(string codigo, string nombre, double costoCorte);
    double getCosto()override;
    void mostrarDatos()override;
};

