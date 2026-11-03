#pragma once
#include<iostream>
#include<string>
#include"Exception.h"
using namespace std;

class PesoMaximoExcedidoException : public Exception {
public:
	PesoMaximoExcedidoException() {
		this->mensaje = "El muemro de envio ya esta registrado (duplicado)";
	}
};


