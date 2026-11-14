#pragma once
#include <iostream>
#include <string>
using namespace std;
class ServicioBano
{
private:
	int codigo;
	string nombre;
	int costoProductos;
public:
	ServicioBano(int codigo,string nombre,int costoProductos);
	~ServicioBano();
	void Servicios();
	void CostosServicios();
};

