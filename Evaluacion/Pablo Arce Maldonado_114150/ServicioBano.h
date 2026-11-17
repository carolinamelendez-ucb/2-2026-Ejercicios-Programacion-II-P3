#include <iostream>
#include <string>
#include "ListaGenerica.h"
#include "Perro.h"
#include "Servicios.h"
using namespace std;


class ServicioBano : public Servicios {
private:

public:
    ServicioBano():Servicios(codigo,nombre,CostoMaterial){
        this->codigo = codigo;
        this->nombre = nombre;
        this->CostoMaterial = CostoMaterial;
    }

    
    double calcularCostoTotal() {
        cout << "Costo total: " << endl;
        return CostoMaterial;
    }

    void mostrar() override {
        Servicios::mostrar();
        cout << " Tipo de Servicio: Servicio de Baño " << endl;
    }

    
};
