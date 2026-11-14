#pragma once
#include<iostream>
#include<string>
#include"Servicio.h"
using namespace std;

class Atencion{
private:
	string codServicio;
	string codPerro;
	//Servicio* servicios;
	float costoFinal;
public:
	Atencion(string codServicio, string codPerro, float costoFinal){
		this->codServicio = codServicio;
		this->codPerro = codPerro;
		this->costoFinal = 0;
	}

};

