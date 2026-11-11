#pragma once
#include<iostream>
#include<string>
using namespace std;

template <typename T>

class ListaGenerica
{
private:
	int capacidad;
	int cantidad;
	T** elemento;
public:

	ListaGenerica(int capacidad, int cantidad , T** elemento)
	{
		this->capacidad = capacidad ;
		this->cantidad =0;
		this->elementos = new T*[elemento];
	}

	~ListaGenerica()
	{
		for (int i = 0; i < cantidad; i++)
		{
			delete elementos[i];
		}
		delete[] elementos;
	}

	void Agregar(T* elemento)
	{

	}

};