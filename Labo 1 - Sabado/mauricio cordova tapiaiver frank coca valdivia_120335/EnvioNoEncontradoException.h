#pragma once
#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;

class EnvioNoEncontrado:public Exception {
public:
	EnvioNoEncontrado(string numEnvio) {
		this->mensaje = "El envio de numero " + numEnvio + " no existe";
	}
};