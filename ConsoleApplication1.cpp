// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include<string>
#include <iostream>
using namespace std;
class Cliente {
private:
	int ci;
	string nombre;
	int aniosAntiguedad;
public:
	Cliente() {
		ci = 0;
		nombre = "";
		aniosAntiguedad = 0;

	}
	Cliente(int ci, string nombre, int aniosAntiguedad) {
		this->ci = ci;
		this->nombre = nombre;
		this->aniosAntiguedad = aniosAntiguedad;
	}
	void mostrar() {
		cout << "ci: " << ci << endl;
		cout << "nombre: " << nombre << endl;
		cout << "anios de antiguedad: " << aniosAntiguedad << endl;
	}
	void setAniosDeAntoguedad(int nuevoValor) {
		this->aniosAntiguedad = nuevoValor;
	}
	};
class Vehiculo {
private:
	int placa;
	string modelo;
	double tarifa;
public:
	Vehiculo() {
		placa = 0;
		modelo = "";
		tarifa = 0;

	}
	Vehiculo(int placa, string modelo, double tarifa) {
		this->placa = placa;
		this->modelo = modelo;
		this->tarifa = tarifa;
	}
	void mostrar() {
		cout << "placa: " << placa << endl;
		cout << "modelo: " << modelo << endl;
		cout << "tarifa diaria: " << tarifa << endl;
	}
};
	int main()
	{
		Cliente* nuevoCliente = new Cliente(1, "joel", 20);
		Vehiculo* nuevoVehiculo = new Vehiculo(10, "trufi", 10);
		nuevoCliente->mostrar();

		nuevoCliente->setAniosDeAntoguedad(30);
		nuevoCliente->mostrar();

		cout << "---------------------------" << endl;
		nuevoVehiculo->mostrar();

	}
