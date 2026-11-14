#pragma once
#include <iostream>
#include <string.h>
using namespace std;
template<class T>
class ListaGenerica
{
private:
	T** elementos;
	int indice;
	int capacidad;
public:
	ListaGenerica(int capacidad) {
		this->capacidad = capacidad;
		indice = 0;
		elementos = new T * [capacidad];
	}
	~ListaGenerica() {
		for (int i = 0;i < indice;i++) {
			delete elementos[i];
		}
		delete[]elementos;
	 }
	void Registrar(T* elemento) {
		if (indice < capacidad) {
			elementos[indice] = elemento;
			indice++;
		}
	}
	T* Buscar(string elementobuscado, string(*funciongetter)(T*)) {
		for (int i = 0;i < indice;i++) {
			string nuevoval = funciongetter(elementos[i]);
			if (nuevoval == elementobuscado) {
				return elementos[i];
			}
		}
		return nullptr;
	}
	void Mostrar() {
		for (int i = 0;i < indice;i++) {
			elementos[i]->Mostrar();
		}
	}
	T* MostrarConCondicion(string elementobsucdo, string(*funcionget)(T*)) {
		for (int i = 0;i < indice;i++) {
			string nuevoval = funcionget(elementos[i]);
			if (nuevoval == elementobsucdo) {
				elementos[i]->Mostrar();
			}
		}
		return nullptr;
	}
	T* acumularCondicion(float elementobuscado, float(*funciongetter)(T*)) {
		for (int i = 0;i < indice;i++) {
			float nuevoval = funciongetter(elementos[i]);
			if (elementobuscado == nuevoval) {
				cout << nuevoval = nuevoval + elementobuscado;
			}
		}
	}
};