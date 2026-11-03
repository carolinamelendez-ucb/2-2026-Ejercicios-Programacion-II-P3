#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Paquete.h"
#include "Envio.h"

using namespace std;

template <typename T>
class ListaGenerica
{
private:
    T* datos;
	int cantidad;
	int capacidad;
public:
    ListaGenerica() {
        this->datos = nullptr;
        this->cantidad = 0;
        this->capacidad = 0;
    }

    ListaGenerica(const ListaGenerica<T>& otro) {
        this->datos = nullptr;
        this->cantidad = otro;
        this->capacidad = otro;
        if (capacidad > 0) {
            this->datos = new T[capacidad];
        }
    }
        ~ListaGenerica() {
            delete[] datos;
        }

        ListaGenerica<T>& operator=(const ListaGenerica<T>&otro) {
            if (this != &otro) {
                T* nuevosDatos = otro.capacidad > 0 ? new T[otro.capacidad] : nullptr;
                for (int i = 0; i < otro.cantidad; i++) {
                    nuevosDatos[i] = otro.datos[i];
                }

                delete[] datos;
                datos = nuevosDatos;
                cantidad = otro.cantidad;
                capacidad = otro.capacidad;
            }
            return *this;
        }
        void agregar( T elemento) {
            if (cantidad == capacidad) {
                cout << "Ya no hay mas cupos" << endl;
            }
            datos[cantidad++] = elemento;
        }

        int tamanio() const {
            return cantidad;
        }

        T& operator[](int indice) {
            return datos[indice];
        }

        const T& operator[](int indice) const {
            return datos[indice];
        }

        void mostrar(T elemento) {
            for (int i = 0; i < capacidad; i++)
            {
                datos[i] = elemento;
            }

        

        int getCodigo(T elemento) {
            return datos
        }
        };
