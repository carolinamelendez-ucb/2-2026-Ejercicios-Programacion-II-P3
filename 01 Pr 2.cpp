
#include <iostream>
#include <string>
using namespace std;

class Cliente {

	int ci;
	string nombre;
	int aniosAntiguedad;

public:
	Cliente(int ci, string nombre) {
		this->ci = ci;
		this->nombre = nombre;
		this->aniosAntiguedad = 0;
	}
	void setAniosAntiguedad(int anios) {
		if (anios > 0) {
			aniosAntiguedad = anios;
		}
		else {
			cout << "Error: La antig debe > 0." << endl;
		}
	}
	void mostrarInformacion() {
		cout << "CI: " << ci << ", Nombre: " << nombre << ", Anios de antig: " << aniosAntiguedad << endl;
	}

};

class Vehiculo{
	string placa;
	string modelo;
	float tarifaDia;

public:
	Vehiculo(string placa, string modelo, float tarifaDia) {
		this->placa = placa;
		this->modelo = modelo;

		if (tarifaDia > 0) {
			this->tarifaDia = tarifaDia;
		}
		else {
			cout << "Error: La tarifa xdia debe > 0." << endl;
			this->tarifaDia = 0; 
		}
	}
	void setTarifaDia(float tarifa) {
		if (tarifa > 0) {
			tarifaDia = tarifa;
		}
		else {
			cout << "Error: La nueva tarifa debe ser mayor que 0." << endl;
		}
	}
	void mostrarInformacion() {
		cout << "Placa: " << placa << ", Modelo: " << modelo << ", tarifa x dia: " << tarifaDia << endl;
	}
	float getTarifaDia() {
		return tarifaDia;
	}
};

class Reserva{
	string fechaInicio;
	int cantidadDias;
	Cliente cliente;
	Vehiculo vehiculo;
	float costoBase;
};

int main() {
	// Crear un objeto Cliente
	Cliente cliente1(12345678, "Juan Perez");
	Vehiculo vehiculo1("ABC123", "Toyota Corolla", 50.0);
	cliente1.mostrarInformacion();
	vehiculo1.mostrarInformacion();

}


