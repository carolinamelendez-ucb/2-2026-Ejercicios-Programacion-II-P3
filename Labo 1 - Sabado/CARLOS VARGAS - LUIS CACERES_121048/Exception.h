#pragma once
#include<iostream>
#include<string>
using namespace std;

class Exception
{
protected:
	string mensaje;
public:
	Exception() {
		mensaje = "";
	}
	string getMensaje() {
		return this->mensaje;
	}
};

