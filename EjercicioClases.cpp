#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
	string ci;
	string nombre;
	int aniosAntiguedad;

public:
	Cliente(const string& ci, const string& nombre, int aniosAntiguedad = 0) {
		this->ci = ci;
		this->nombre = nombre;
		setAniosAntiguedad(aniosAntiguedad);
	}

	void setAniosAntiguedad(int anios) {
		if (anios >= 0) {
			this->aniosAntiguedad = anios;
		}
		else {
			cout << "Error" << endl;
		}
	}

	int getAniosAntiguedad() const {
		return aniosAntiguedad;
	}

	void mostrar() const {
		cout << "CI: " << ci << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Antiguedad: " << aniosAntiguedad << endl;
	}
};

class Vehiculo {
private:
	string placa;
	string modelo;
	double tarifaDia;

public:
	Vehiculo(const string& placa, const string& modelo, double tarifaDia) {
		this->placa = placa;
		this->modelo = modelo;
		setTarifaDia(tarifaDia);
	}

	void setTarifaDia(double tarifa) {
		if (tarifa > 0) {
			this->tarifaDia = tarifa;
		}
		else {
			cout << "Error" << endl;
			this->tarifaDia = 0;
		}
	}

	double getTarifaDia() const {
		return tarifaDia;
	}

	void mostrar() const {
		cout << "Placa: " << placa << endl;
		cout << "Modelo: " << modelo << endl;
		cout << "Tarifa Dia: " << tarifaDia << endl;
	}
};

class Reserva {
private:
	string fechaInicio;
	int cantidadDias;
	Cliente cliente;
	Vehiculo vehiculo;
	double costoBase;

	void calcularCostoBase() {
		costoBase = vehiculo.getTarifaDia() * cantidadDias;
	}

public:
	Reserva(const string& fechaInicio, int cantidadDias, const Cliente& cliente, const Vehiculo& vehiculo)
		: fechaInicio(fechaInicio), cliente(cliente), vehiculo(vehiculo) {
		if (cantidadDias > 0) {
			this->cantidadDias = cantidadDias;
		}
		else {
			cout << "Error" << endl;
			this->cantidadDias = 1;
		}
		calcularCostoBase();
	}

	double calcularCostoFinal() const {
		double costoFinal = costoBase;

		if (cliente.getAniosAntiguedad() > 10) {
			costoFinal -= costoFinal * 0.10;
		}

		if (cantidadDias >= 7) {
			costoFinal -= costoFinal * 0.05;
		}

		return costoFinal;
	}

	void setCantidadDias(int nuevaCantidad) {
		if (nuevaCantidad > 0) {
			cantidadDias = nuevaCantidad;
			calcularCostoBase();
		}
		else {
			cout << "Error" << endl;
		}
	}

	void setVehiculo(const Vehiculo& vehiculo) {
		this->vehiculo = vehiculo;
		calcularCostoBase();
	}

	void mostrar() const {
		cout << "Fecha Inicio: " << fechaInicio << endl;
		cout << "Cantidad Dias: " << cantidadDias << endl;
		cliente.mostrar();
		vehiculo.mostrar();
		cout << "Costo Base: " << costoBase << endl;
		cout << "Costo Final: " << calcularCostoFinal() << endl;
	}
};

int main() {
	Cliente cliente1("1234567", "Juan Perez", 12);
	Vehiculo vehiculo1("ABC-123", "Toyota", 50.0);
	Reserva reser1("2026-08-20", 8, cliente1, vehiculo1);

	reser1.mostrar();

	cliente1.setAniosAntiguedad(5);
	reser1.setCantidadDias(3);

	Vehiculo vehiculo2("XYZ-789", "Nissan", 100.0);
	reser1.setVehiculo(vehiculo2);

	reser1.mostrar();

	return 0;
}