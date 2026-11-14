#pragma once
#include "Servicio.h"
class ServicioBano :
    public Servicio
{
private:
    float costoProductos;
public:
    ServicioBano(string codigo,string nombre,float costoProductos) :
        Servicio(codigo, nombre,50) {
        this->costoProductos = costoProductos;
    }
    void mostrar()override {
        Servicio::mostrar();
        cout << "costo de los productos: " << costoProductos << "Bs. " << endl;
    }
    float totalServicio() {
        return this->costo + this->costoProductos;
    }
};

