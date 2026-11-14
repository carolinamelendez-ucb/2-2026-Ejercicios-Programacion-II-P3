#pragma once
#include <iostream>
#include <string>
using namespace std;
class Atencion
{
private:
	int codigo;
	int costoFinal;
	string servicio;
	string perro;
public:
	Atencion(int codigo,int costoFinal,string servicio,string perro);
	~Atencion();
	void AtencionRealizada();

};

