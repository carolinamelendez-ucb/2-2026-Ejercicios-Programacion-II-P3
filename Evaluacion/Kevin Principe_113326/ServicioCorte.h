#pragma once
#include "Servicio.h"
class ServicioCorte :
    public Servicio
{
private:
public:
    ServicioCorte(string codigo) : Servicio(codigo) {
        this->nombre = "Servicio Corte";
        this->costoBase = 50;
    }

    ~ServicioCorte(){}

    void mostrar() override {
        cout << "Codigo Servicio: " << codigo << endl;
        cout << "Nombre Servicio: " << nombre << endl;
        cout << "Costo Corte: " << costoBase << endl;
    }
};

