#pragma once
#include "Servicio.h"
class ServicioBano : public Servicio
{
private:

public:
	ServicioBano(string codigo, string nombre, float costoproducto):Servicio(codigo,nombre,costoproducto) {

	}
	~ServicioBano(){}

	void Mostrar() {
		Servicio::Mostrar();

	}

};