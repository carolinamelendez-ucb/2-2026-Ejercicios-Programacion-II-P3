#pragma once
#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;

class PesoExedido :public Exception {
public:
	PesoExedido(int peso) {
		this->mensaje = "El peso " + std::to_string(peso) + " exede el limite.";
	}
};