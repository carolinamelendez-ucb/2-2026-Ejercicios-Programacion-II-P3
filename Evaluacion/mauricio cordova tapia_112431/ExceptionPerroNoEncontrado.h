#pragma once
#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;
class PerroNoEncontrado :public Exception {
public:
	PerroNoEncontrado(string codigo) {
		this->mensaje = "El perro de codigo " + codigo + " no fue encontrado.";
	}
};