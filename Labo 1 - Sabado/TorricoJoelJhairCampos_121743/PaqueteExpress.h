#pragma once
#include "PaqueteNormal.h"
class PaqueteExpress :
    public PaqueteNormal
{
private:
    int horasEntrega;
    float costoPrioridad;
public:
    PaqueteExpress(string codigo, string descripcion, float peso, float costoPorKilogramo,int horasEntrega) :
        PaqueteNormal(codigo, descripcion, peso, costoPorKilogramo)
    {
        this->costoPrioridad = 0;
        this->horasEntrega = horasEntrega;
        if (horasEntrega < 24) {
            this->costoPrioridad = 30;
        }
        if (horasEntrega >= 24 && horasEntrega<=48) {
            this->costoPrioridad = 20;
        }
        if (horasEntrega > 48) {
            this->costoPrioridad = 10;
        }
    }
    void mostrar()override {
        PaqueteNormal::mostrar();
        cout << "horas de entrega es: " << this->horasEntrega << endl;
        cout << "costo de prioridad es: " << this->costoPrioridad << endl;
        cout << "costo total: " << total() + this->costoPrioridad << endl;
    }
    virtual float calcularCosto() {
        return total() + this->costoPrioridad;
    }
};

