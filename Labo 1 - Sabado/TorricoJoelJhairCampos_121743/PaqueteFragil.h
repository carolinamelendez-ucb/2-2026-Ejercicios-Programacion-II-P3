#pragma once
#include "PaqueteNormal.h"
class PaqueteFragil :
    public PaqueteNormal
{
private:
    string nivelFragilidad;
    float costoEmbalaje;
public:
    PaqueteFragil(string codigo, string descripcion, float peso, float costoPorKilogramo):
        PaqueteNormal(codigo,descripcion,peso,costoPorKilogramo)
    {
        this->costoEmbalaje = 0;
        this->nivelFragilidad = descripcion;
        if (nivelFragilidad == "BAJO") {
            this->costoEmbalaje = 5;
        }
        if (nivelFragilidad == "MEDIO") {
            this->costoEmbalaje = 10;
        }
        if (nivelFragilidad == "ALTO") {
            this->costoEmbalaje = 20;
        }
    }
    void mostrar()override {
        PaqueteNormal::mostrar();
        cout << "nivel de fragilidad es: " << this->nivelFragilidad << endl;
        cout << "costo de embalaje es: " << this->costoEmbalaje << endl;
        cout << "costo total: " << total() + this->costoEmbalaje << endl;
    }
    virtual float calcularCosto() {
        return total()+ this->costoEmbalaje;
    }

};

