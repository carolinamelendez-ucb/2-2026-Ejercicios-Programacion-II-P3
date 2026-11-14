#pragma once
#include "Servicio.h"
class ServicioCorte :
    public Servicio
{
private:
    float costoCorte;
public:
    ServicioCorte(string codigo,string nombre,float costoCorte) :
        Servicio(codigo, nombre,50) {
        this->costoCorte = costoCorte;
    }
    void mostrar()override {
        Servicio::mostrar();
        cout << "costo del corte: " << costoCorte << "Bs. " << endl;
    }
    float totalServicio() {
        return this->costo + this->costoCorte;
    }
};

