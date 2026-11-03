#pragma once
#include "Paquete.h"
class PaqueteExpress : public Paquete
{
private:
	int Horaentrega;
	float Costoprioridad;
public:
	PaqueteExpress(string codigo, string descripcion, float peso, float costo,int horanetrega) :Paquete(codigo, descripcion, peso, costo) {
		this->Horaentrega = horanetrega;
	}
	~PaqueteExpress(){}
	int  CalcularCosto() {
		if (Horaentrega < 24) {
			return Costoprioridad = 30;
		}
		if (Horaentrega > 24 &&  Horaentrega < 48) {
			return Costoprioridad = 20;
		}
		if ( Horaentrega > 48) {
			return Costoprioridad = 10;
		}
	}
	void CalcularCostotiempo() {
		int valor = Costo * Peso;
		cout << "valor por tiempo: " << valor + CalcularCosto() << endl;
	}
	void Mostrar() {
		Paquete::Mostrar();
		cout << "costo por costototal " << CalcularCostotiempo << endl;
	}
};