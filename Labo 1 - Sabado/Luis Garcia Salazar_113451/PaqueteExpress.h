#pragma once
#include "Paquete.h"

class PaqueteExpress :
	public Paquete
{
private:
	int horasEntrega;
	int costoPrioridad;
public:
	PaqueteExpress(int horasEntrega, int costoPrioridad) : Paquete(codigoPaquete, descripcion, peso, costoPorKg) {
		this->codigoPaquete = codigoPaquete;
		this->descripcion = descripcion;
		this->peso = peso;
		this->costoPorKg = costoPorKg;
		this->horasEntrega = horasEntrega;
		this->costoPrioridad = costoPrioridad;
	}
	void obtenerCosto(){
		int costoTotal;
		if (horasEntrega < 24) {
			costoPrioridad = 30;
		}
		else if(horasEntrega > 24 && horasEntrega<48) {
			costoPrioridad = 20;
		}
		else if(horasEntrega < 48) {
			costoPrioridad = 10;
		}
		costoTotal = peso * costoPorKg + costoPrioridad;
	}
};

