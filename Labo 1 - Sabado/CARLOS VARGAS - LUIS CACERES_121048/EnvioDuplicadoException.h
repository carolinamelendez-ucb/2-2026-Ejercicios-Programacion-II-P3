#pragma once
#include<iostream>
#include<string>
#include"Exception.h"
using namespace std;

class EnvioDuplicadoException : public Exception {
public:
	EnvioDuplicadoException(string numero) {
		this->mensaje = "El muemro de envio ya esta registrado (duplicado)";
	}
};


