#pragma once
#include <string>
#include <iostream>
#include "Exception.h"
using namespace std;

class ClienteDuplicado:public Exception{
public:
	ClienteDuplicado(string codigo) {
		this->mensaje = "El CI " + codigo + " esta duplicado.";
	}
};