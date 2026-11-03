#include<iostream>
#include<string.h>
using namespace std;

class Paquete
{
protected:
	string codigo;
	string descripcion;
	double peso;
	double costoKg;
	double costo;
public:
	Paquete();
	Paquete(string codigo, string descripcion, double peso,double costoKg) {
		this->codigo = codigo;
		this->descripcion = descripcion;
		this->peso = peso;
		this->costoKg = costoKg;
		this->costo = 0;
	}
	~Paquete();

	virtual void calcularCosto() {
		this->costo = peso * costoKg;
	}
	void mostrar() {
		calcularCosto();
		cout << "Codigo: " << codigo << endl;
		cout << "Descripcion: " << descripcion << endl;
		cout << "Peso: " << peso << endl;
		cout << "Costo por Kg: " << costoKg << endl;
		cout << "Costo : " << costo << endl;
	}
	string getCodigo() {
		return codigo;
	}
	static bool comparador(Paquete* paquete, string codigoBuscado) {
		return paquete->codigo == codigoBuscado;
	}

};

