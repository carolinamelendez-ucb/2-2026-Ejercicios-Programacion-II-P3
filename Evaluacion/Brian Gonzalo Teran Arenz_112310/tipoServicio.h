#pragma once
#include"Servicio.h"
class ServicioBano : public Servicio {
private:
	float costoProductos;
public:
	ServicioBano(string codigo, string nombre, float costoProductos)
		: Servicio(codigo,nombre)
	{
		this->costoProductos = costoProductos;
	}
	float Costototal() {
		return costoProductos;
	}
	void Mostrar() {
		cout << "============ Servicio Bano =============" << endl;
		Servicio::Mostrar();
		cout << "El Costo de los productos del  Servicio es: " << costoProductos << endl;
	}
};
class ServicioCorte : public Servicio {
private:
	float costoCorte;
public:
	ServicioCorte(string codigo, string nombre, float costoCorte)
		: Servicio(codigo, nombre)
	{
		this->costoCorte = costoCorte;
	}
	float Costototal() {
		return costoCorte;
	}
	void Mostrar() {
		cout << "============ Servicio Corte =============" << endl;
		Servicio::Mostrar();
		cout << "El Costo de los productos del  Servicio es: " << costoCorte << endl;
	}
};
