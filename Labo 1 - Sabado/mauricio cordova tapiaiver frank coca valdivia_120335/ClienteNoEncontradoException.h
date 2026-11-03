#pragma once
#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;

class ClienteNoEncontrado :public Exception {
public:
	ClienteNoEncontrado(string ci) {
		this->mensaje = "El ci " + ci + " de un cliente no fue encontrado";
	}
};