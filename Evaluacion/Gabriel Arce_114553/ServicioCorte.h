#pragma once
#include "Servicio.h"

class ServicioCorte :
    public Servicio
{
private:
	int costoCorte;
public:
	ServicioCorte(string codigo, string nombre, int costoCorte) : Servicio(codigo, nombre) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->costoCorte = costoCorte;
	}
	~ServicioCorte() {};
	int getCostoAdicional() {
		return costoCorte;
	}
	void mostrar() override{
		cout << "Servicio: " << endl;
		cout << "Codigo: " << codigo << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Costo Productos: " << costoCorte << endl;
	}
};

