#pragma once
#include<iostream>
#include<string>

using namespace std;

template<class T>
class ListaGenerica {
private:
	int cantidad;
	int capacidad;
	T** elementos;

public:
	ListaGenerica(int capacidad) {
		this->cantidad = 0;
		this->capacidad = capacidad;
		this->elementos = new T * [capacidad];
	}
	
	~ListaGenerica() {
		for (int i = 0;i < this->cantidad;i++) {
			delete this->elementos[i];
		
		}
		delete[] this->elementos;
	}

	int getCapacidad() {
		return  this->capacidad;
	}
	int getCantidad() {
		return this->cantidad;
	}

	bool estaLleno() {
		return this->cantidad >= this->capacidad;
	}
	

	//obtener
	T* obtener(int indice)
	{
		if (indice >= 0 && indice < this->capacidad) {
			return this->elementos[indice];
	   }
		return nullptr;

	}

	//registrar
	void registrar(T* nuevo) {
		if (this->estaLleno()) {
			cout << "esta lleno." << endl;
		}
		this->elementos[this->cantidad] = nuevo;
		this->cantidad++;

	}




	//buscar
	T* buscar(string valor, string(*getter)(T*))
	{
		for (int i = 0;i < this->cantidad;i++)
		{
			if (getter(this->elementos[i]) == valor) {
				return this->elementos[i];
			}
			return nullptr;

		}

	}




};
