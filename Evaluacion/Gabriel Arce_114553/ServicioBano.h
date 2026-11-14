#pragma once
#include "Servicio.h"

class ServicioBano :
    public Servicio
{
private:
    int costoProductos;
public:
	ServicioBano(string codigo, string nombre,int costoProductos): Servicio(codigo,nombre) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->costoProductos = costoProductos;
	}
	~ServicioBano() {};
	int getCostoAdicional() {
		return costoProductos;
	}
	
	void mostrar() override {
		cout << "Servicio: " << endl;
		cout << "Codigo: " << codigo<<endl;
		cout << "Nombre: " << nombre<<endl;
		cout << "Costo Productos: " << costoProductos<<endl;		
	}
};

