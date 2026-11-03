#pragma once
#include <string>
#include <iostream>
using namespace std;

class Exception {
protected:
	string mensaje;
public:
	Exception() {
		this->mensaje = "";
	}

	string getMensaje() { return mensaje; }
};