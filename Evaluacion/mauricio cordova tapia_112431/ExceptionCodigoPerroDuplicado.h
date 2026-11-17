#pragma once
#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;

class CodigoPerroDuplicado :public Exception {
public:
	CodigoPerroDuplicado(string codigo) {
		this->mensaje = "El codigo " + codigo + " esta suplicado.";
	}
};