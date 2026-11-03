#include<iostream>
#include<string.h>
using namespace std;

class Cliente
{
private:
	string ci;
	string nombre;
	string direccion;
public:
	Cliente(string ci, string nombre, string direccion) {
		this->ci = ci;
		this->nombre = nombre;
		this->direccion = direccion;
	}
	~Cliente();
	void mostrar() {
		cout << "Ci: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Direcion: " << direccion << endl;
	}
	string getCi() {
		return ci;
	}
	static bool comparador(Cliente* cliente, string ci) {
		return cliente->ci == ci;
	}
};

