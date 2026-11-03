#include "PaqueteExpress.h"

PaqueteExpress::PaqueteExpress(string codigo,string descripcion,float peso,float costoPorKilo,int horasEntrega) :PaqueteNormal(codigo,descripcion,peso,costoPorKilo) {
	this->codigo = codigo;
	this->descripcion = descripcion;
	this->peso = peso;
	this->costoPorkilo = costoPorkilo;
	if (this->horasEntrega <= 0){
		//exception
	}
	else if (this->horasEntrega < 24) {
		this->costoPrioridad = 30;
	}
	else if ((this->horasEntrega >= 24)&&(this->horasEntrega <= 48)) {
		this->costoPrioridad = 20;
	}
	else if (this->horasEntrega > 48) {
		this->costoPrioridad = 10;
	}
}

float PaqueteExpress::calcularCosto() {
	return (peso * costoPorkilo) + costoPrioridad;
}

void PaqueteExpress::mostrarDatos() {
	cout << "Tipo Paquete: Express" << endl;
	cout << "Codigo: " << codigo << endl;
	cout << "Descripcion: " << descripcion << endl;
	cout << "Peso: " << peso << endl;
	cout << "Horas Entrega: " << horasEntrega << endl;
	cout << "Costo por Prioridad: " << costoPrioridad << endl;
	cout << "Costo Paquete: " << calcularCosto() << endl;
}