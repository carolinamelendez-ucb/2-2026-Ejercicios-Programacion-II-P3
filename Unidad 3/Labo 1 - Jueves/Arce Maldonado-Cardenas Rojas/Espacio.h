#pragma once
/*#include <iostream>
#include<string>
#include"ListaGenerica.h"
#include"Vehiculo.h"
using namespace std;
class Espacio {
private:
    string codigoEspacio;
    int nivel;
    string sector;
    string estado;
public:
    Espacio(string codigoEspacio, int nivel, string sector) {
        this->codigoEspacio = codigoEspacio;
        this->nivel = nivel;
        this->sector = sector;
        this->estado = "Disponible";
    }

    bool estaDisponible(){ return this->estado == "Disponible"; }
    void ocupar() { this->estado = "Ocupado"; }
    void mostrar() {
        cout << "  Espacio: " << codigoEspacio
            << "Nivel: " << nivel
            << "Sector: " << sector
            << "Estado: " << estado << endl;
    }

    static string getCodigo(Espacio* e) { return e->codigoEspacio; }
};