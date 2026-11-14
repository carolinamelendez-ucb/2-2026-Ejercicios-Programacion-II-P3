#pragma once
#include <iostream>
using namespace std;

template<typename T>

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
	~VectorGenerico() {
		for (int i = 0; i < cantidad; i++)
		{
			delete elementos[i];
		}delete[] elementos;
	}
	void mostrar() {
		for (int i = 0; i < cantidad; i++) {
			elementos[i]->mostrar();
		}
	}
	void mostrarDeUnElento(string codigo ,bool(*comparador)(T*, string)) {
		for (int i = 0; i < cantidad; i++) {
			bool elementoEncontrado = comparador(elementos[i], codigo);
			if (elementoEncontrado == true)
			{
				elementos[i]->mostrar();
			}
		}
	}
	int totalDeUnElemento(string codigo, bool(*comparador)(T*, string)) {
		int acumulador = 0;
		for (int i = 0; i < cantidad; i++) {
			bool elementoEncontrado = comparador(elementos[i], codigo);
			if (elementoEncontrado == true)
			{
				acumulador= acumulador + elementos[i]->getter();
			}
		}
	}
	void agregarElemento(T* nuevoElemento) {
		if (cantidad<capacidad)
		{
			elementos[cantidad] = nuevoElemento;
			cantidad++;
		}
	}
	T* buscar(string codBuscado, bool(*comparador)(T*, string)) {
		
		for (int i = 0; i < cantidad; i++)
		{
			bool elementoEncontrado = comparador(elementos[i], codBuscado);
			if (elementoEncontrado == true)
			{
				return elementos[i];
			}
		}return nullptr;
	}

};

