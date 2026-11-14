#pragma once
#include <iostream>
#include<string>
using namespace std;
class Excepciones {
protected:
	string mensaje;
public:
	Excepciones() {
		mensaje = "";
	}
	string getMensaje() {
		return mensaje;
	}
};