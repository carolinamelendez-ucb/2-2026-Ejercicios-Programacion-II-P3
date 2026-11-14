#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class Excepcion
{
protected:
	string mensaje;
public:
	Excepcion() {
		this->mensaje = "Excepicion";
	}
	~Excepcion() {};

	string getMensaje() {
		return mensaje;
	}

};
