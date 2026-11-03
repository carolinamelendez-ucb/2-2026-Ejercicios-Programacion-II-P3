#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Exception
{
protected:
	string mensaje;
public:
	Exception() {
		this->mensaje = "";
	}
	string getrror() {
		return mensaje;
	}
};