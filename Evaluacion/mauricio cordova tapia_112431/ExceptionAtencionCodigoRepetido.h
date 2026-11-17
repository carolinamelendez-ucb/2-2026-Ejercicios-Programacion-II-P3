#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;
#pragma once

class AtencionCodigoDuplicado :public Exception {
public:
	AtencionCodigoDuplicado(string codigo) {
		this->mensaje = "El codigo de atencion " + codigo + " esta duplicado.";
	}
};