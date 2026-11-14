#pragma once
#include <iostream>
#include <exception>
using namespace std;

class Exception: public exception {
protected:
	string mensaje;
public:
	Exception() {
		this->mensaje = "ERROR";
	}
};