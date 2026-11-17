#pragma once
#include "Servicio.h"
class ServicioBano :
    public Servicio
{
private:
public:
    ServicioBano(string codigo) : Servicio(codigo){
        this->nombre = "Servicio Bano";
        this->costoBase = 100;
    }

    ~ServicioBano(){}

    void mostrar() override {
        cout << "Codigo Servicio: " << codigo << endl;
        cout << "Nombre Servicio: " << nombre << endl;
        cout << "Costo Productos: " << costoBase << endl;
    }
};

