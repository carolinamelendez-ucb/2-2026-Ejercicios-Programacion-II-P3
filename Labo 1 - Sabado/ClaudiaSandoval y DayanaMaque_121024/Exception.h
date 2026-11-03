#pragma once
#include <iostream>
#include <string>
using namespace std;
class Exception {
protected:
	string mensaje;
public:
	Exception(string mensaje) {
		this->mensaje=mensaje;
	}


	virtual string getMensaje() {
		return mensaje;

	}
	/*class ClienteDuplicadoException {
public:
	ClienteDuplicadoException(string si)  {
		mensaje
	};

};*/
};