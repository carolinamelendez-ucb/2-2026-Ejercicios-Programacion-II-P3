#pragma once
#include <iostream>
#include <string.h>
using namespace std;
template<class T>
class ListaGenerica
{
private:
	T** elementos;
	int capacidad;
	int indice;
public:
	ListaGenerica(int capacidad);
	~ListaGenerica();
	void Registrar(T* elemento);
	T* Buscar(string elementobuscado, string(*getter)(T*));
	void Mostrar();
};

template<class T>
inline ListaGenerica<T>::ListaGenerica(int capacidad)
{
	this->capacidad = capacidad;
	indice = 0;
	this->elementos = new T * [capacidad];
}

template<class T>
inline ListaGenerica<T>::~ListaGenerica()
{
}

template<class T>
inline void ListaGenerica<T>::Registrar(T* elemento)
{
	if (indice < capacidad) {
		elementos[indice] = elemento;
		indice++;
	}
}

template<class T>
inline T* ListaGenerica<T>::Buscar(string elementobuscado, string(*getter)(T*))
{
	for (int i = 0;i < indice;i++) {
		string valoract = getter(elementos[i]);
		if (valoract == elementobuscado) {
			return elementos[i];
		}
	}
	return nullptr;
}

template<class T>
inline void ListaGenerica<T>::Mostrar()
{
	for (int i = 0;i < indice;i++) {
		elementos[i]->Mostrar();
	}
}
