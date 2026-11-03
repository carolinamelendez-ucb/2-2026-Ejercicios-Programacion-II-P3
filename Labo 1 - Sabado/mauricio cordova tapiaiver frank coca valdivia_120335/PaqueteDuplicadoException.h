#pragma once
#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;

class PaqueteDuplicado :public Exception {
public:
	PaqueteDuplicado(string codigo) {
		this->mensaje = "El codigo  " + codigo + " del paquete a registrar esta duplicado.";
	}
};