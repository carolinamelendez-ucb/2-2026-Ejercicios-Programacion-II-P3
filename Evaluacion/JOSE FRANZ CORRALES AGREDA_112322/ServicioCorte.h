#pragma once
#include <string>
#include <iostream>
using namespace std;

class ServicioCorte
{
private:
	int codigo;
	string nombre;
	int costoCorte;
public:
	ServicioCorte();
	~ServicioCorte();
	void Corte();
	void CostoAdicional();
};

