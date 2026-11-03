#pragma once
#include<iostream>
#include<string>
#include"Exception.h"
using namespace std;

class EnvioNoEncontradoException : public Exception {
public:
	EnvioNoEncontradoException(string numero) {
		this->mensaje = "El numero de envio no esta registrado (duplicado)";
	}
};

