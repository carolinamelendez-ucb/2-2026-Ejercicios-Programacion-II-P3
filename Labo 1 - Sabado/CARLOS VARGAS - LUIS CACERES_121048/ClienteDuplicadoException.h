#pragma once
#include<iostream>
#include<string>
#include"Exception.h"
using namespace std;

class ClienteDuplicadoException : public Exception{
public:
	ClienteDuplicadoException(string ci) {
		this->mensaje = "El cliente ya esta registrado (duplicado)";
	}
};

