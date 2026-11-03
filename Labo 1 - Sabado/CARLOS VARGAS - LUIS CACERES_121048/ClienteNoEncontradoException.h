#pragma once
#include<iostream>
#include<string>
#include"Exception.h"
using namespace std;

class ClienteNoEncontradoException: public Exception{
public:
	ClienteNoEncontradoException(string ci) {
		this->mensaje = "El cliente no existe (No encontrado)";
	}
};

