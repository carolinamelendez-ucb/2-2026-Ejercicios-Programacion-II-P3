#pragma once
#include  "Paquete.h"
class PaqueteFragil :public Paquete
{
private:
	string NivelFragilidad;
	float Costoenvalaje;
public:
	PaqueteFragil(string codigo, string descripcion, float peso, float costo,string nivelfragil, float costoenvalaje):Paquete(codigo, descripcion, peso, costo) {
		this->NivelFragilidad = nivelfragil;
		this->Costoenvalaje = costoenvalaje;
	}
	~PaqueteFragil();
	void calcularcostoEnvalaje() {
		int valor = Costo * Peso;
		if (NivelFragilidad == "Bajo") {
			cout << "Costo por peso es: " << valor + 5;
		}
		if (NivelFragilidad == "Medio")
			cout << "Costo por peso es: " << valor + 10;

		if (NivelFragilidad == "Alto")
			cout << "Costo por peso es: " << valor + 20;
	}
	void Mostrar() {
		Paquete::Mostrar();
		cout << "costo Envalaje" << Costoenvalaje <<  endl;
	}
};