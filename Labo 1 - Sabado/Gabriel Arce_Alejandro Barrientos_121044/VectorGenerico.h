#include<iostream>
#include<string.h>
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
		this->elementos = new  T*[capacidad];
	}
	~VectorGenerico() {
		for (int i = 0; i < cantidad; i++)
		{
			delete elementos[i] ;
		}delete[] elementos;
	}
	void mostrar() {
		for (int i = 0; i < cantidad; i++)
		{
			elementos[i]->mostrar();
		}
	}

	void agregarElemento(T* nuevoElemento) {
		if (cantidad<capacidad)
		{
			elementos[cantidad] = nuevoElemento;
			cantidad++;
		}
	}

	T* buscar(string codBuscado, bool (*comparador)(T*, string)) {
		for (int i = 0; i < cantidad; i++)
		{
			if (comparador(elementos[i], codBuscado) == true) {
				return elementos[i];
			}
		}return nullptr;
	}


};

