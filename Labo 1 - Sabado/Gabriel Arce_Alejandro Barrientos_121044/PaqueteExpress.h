#pragma once
#include "Paquete.h"
class PaqueteExpress :
    public Paquete
{
private:
    double horasEntrega;
    double costoPrioridad;
public:
    PaqueteExpress(string codigo, string descripcion, double peso, double costoKg,  double horasEntrega) : Paquete(codigo, descripcion, peso, costoKg) {
        this->horasEntrega = horasEntrega;
        this->costoPrioridad = 0;
    }
    void calcularCosto() {
        if (horasEntrega >=48) {
            costoPrioridad = 10;
        }
        else {
            if (12<horasEntrega&& horasEntrega<48) {
                costoPrioridad = 20;
            }
            else {
                if (horasEntrega <=12)
                {
                    costoPrioridad = 30;
                }
            }
        }costo = (peso * costoKg) + costoPrioridad;
     }
    void mostrar() {
        calcularCosto();
        cout << "Codigo: " << codigo << endl;
        cout << "Descripcion: " << descripcion << endl;
        cout << "Peso: " << peso << endl;
        cout << "Costo por Kg: " << costoKg << endl;
        cout << "Horas de entrega: " << horasEntrega << endl;
        cout << "Costo Prioritario: " << costoPrioridad << endl;
        cout << "Costo : " << costo << endl;

    }
};

