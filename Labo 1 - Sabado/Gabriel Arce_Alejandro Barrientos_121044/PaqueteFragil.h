#pragma once
#include "Paquete.h"
class PaqueteFragil :
    public Paquete
{
private:
    string nivelFragilidad;
    double costoEmbalaje;
public:
    PaqueteFragil(string codigo, string descripcion, double peso, double costoKg,string nivelFragilidad): Paquete( codigo,  descripcion,  peso,  costoKg) {
        this->nivelFragilidad = nivelFragilidad;
        this->costoEmbalaje = 0;
    }
    void calcularCosto() {
        if (nivelFragilidad=="Bajo") {
            costoEmbalaje = 5;
        }
        else {
            if (nivelFragilidad == "Medio") {
                costoEmbalaje = 10;
            }
            else {
                if (nivelFragilidad == "Alto")
                {
                    costoEmbalaje = 20;
                }
            }
        }costo = (peso * costoKg)+costoEmbalaje;
    }
    void mostrar() {
        calcularCosto();
        cout << "Codigo: " << codigo << endl;
        cout << "Descripcion: " << descripcion << endl;
        cout << "Peso: " << peso << endl;
        cout << "Costo por Kg: " << costoKg << endl;
        cout << "Nivel Fragilidad: " << nivelFragilidad << endl;
        cout << "Costo embalaje: " << costoEmbalaje << endl;
        cout << "Costo : " << costo << endl;
    }
};

