#pragma once
#include<iostream>
#include<string>
#include"Exception.h"
using namespace std;

class EnvioDuplicadoException : public Exception {
public:
	EnvioDuplicadoException(string cod) {
		this->mensaje = "El codigo ya esta registrado (duplicado)";
	}
};
