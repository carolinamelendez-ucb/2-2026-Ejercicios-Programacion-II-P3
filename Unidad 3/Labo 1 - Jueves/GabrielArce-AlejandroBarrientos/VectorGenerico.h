#pragma once
#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
class VectorGenerico
{
private:
	int cantidad;
	int capacidad;
	T** elementos;

public:
	VectorGenerico(int capacidad) {
		this->cantidad = 0;
		this->capacidad = capacidad;
		this->elementos = new T*[capacidad];
	}
	~VectorGenerico();
	void mostrar() {
		for (int i = 0; i < cantidad; i++)
		{
			elementos[i]->mostrar();
		}
	}
	int getCantidad() {
		return cantidad;
	}
	void agregar(T* nuevoElemento) {
		if (cantidad<capacidad)
		{
			elementos[cantidad] = nuevoElemento;
			cantidad++;
		}
	}
	T* buscar(string ciBuscado, bool (*comparador)(T*, string) ){
		for (int i = 0; i < cantidad; i++)
		{
			if (comparador(elementos[i], ciBuscado) == true) {
				return elementos[i];
			}
		}return nullptr;
	}
};

