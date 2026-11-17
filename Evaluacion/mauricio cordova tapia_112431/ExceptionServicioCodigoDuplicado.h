#pragma once
#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;

class CodigoServicioDuplicado:public Exception {
public:
	CodigoServicioDuplicado(string codigo) {
		this->mensaje = "El codigo de servicio " + codigo + " esta duplicado.";
	}
};