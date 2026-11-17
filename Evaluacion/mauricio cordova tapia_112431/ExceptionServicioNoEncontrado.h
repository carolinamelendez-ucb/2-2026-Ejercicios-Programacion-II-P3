#pragma once
#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;

class ServicioNoEncontrado :public Exception {
public:
	ServicioNoEncontrado(string codigo) {
		this->mensaje = "El servicio de codigo " + codigo + " no fue encontrado.";
	}
};