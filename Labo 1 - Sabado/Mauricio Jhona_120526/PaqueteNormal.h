#pragma once
#include "Paquete.h"
class PaqueteNormal : public Paquete
{
public:
	PaqueteNormal(string codigo, string descripcion, float peso, float costo):Paquete(codigo,descripcion,peso,costo) {

	}
	~PaqueteNormal(){}
	void calcularCostoPeso() {
		int valor = Costo * Peso;
		cout << "Costo por peso es: " << valor;
	}
	void Mostrar() {
		Paquete::Mostrar();
		cout << calcularCostoPeso;
	}
};