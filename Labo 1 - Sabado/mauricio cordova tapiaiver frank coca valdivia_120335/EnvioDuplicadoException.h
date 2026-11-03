#pragma once
#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;

class EnvioDuplicado:public Exception {
public:
	EnvioDuplicado(string numEnvio) {
		this->mensaje = "El numero de envio " + numEnvio + " esta duplicado";
	}
};