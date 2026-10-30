#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Excepcion
{
protected:
	string mensaje;

public:
	Excepcion() {
		this->mensaje = "Ha saltado una excepcion";
	}
	~Excepcion() {} ;
	
	string getMensaje() {
		return mensaje;
	}
};
