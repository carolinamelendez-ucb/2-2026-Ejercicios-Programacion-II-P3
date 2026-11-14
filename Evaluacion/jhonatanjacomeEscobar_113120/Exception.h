#pragma once
#include <iostream>
#include <string>
using namespace std;
class Exception {

protected:
	string mensaje;


public:
	Exception(string mensaje ) {
		this->mensaje = mensaje;
	}

	string getmensaje() {
		return mensaje;
	}
};