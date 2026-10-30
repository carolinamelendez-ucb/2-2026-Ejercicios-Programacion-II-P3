#pragma once
/*#include <iostream>
#include<string>
#include"ListaGenerica.h"


using namespace std;



class Exception 
{
protected:
    string mensaje;
public:
    Exception() { mensaje = ""; }
    string getMensaje() { 
        return this->mensaje; 
    }
};

class CapacidadMaximaEspaciosException : public Exception {
public:
    CapacidadMaximaEspaciosException(int capacidad) {
        this->mensaje = "Se supero la capacidad maxima de espacios: ";
    }
};

class CodigoEspacioDuplicadoException : public Exception {
public:
    CodigoEspacioDuplicadoException(string codigo) {
        this->mensaje = "El codigo de espacio " + codigo + " esta duplicado";
    }
};

class CapacidadMaximaVehiculosException : public Exception {
public:
    CapacidadMaximaVehiculosException(int capacidad) {
        this->mensaje = "Se supero la capacidad maxima de vehiculos: ";
    }
};

class PlacaDuplicadaException : public Exception {
public:
    PlacaDuplicadaException(string placa) {
        this->mensaje = "La placa " + placa + " esta duplicada";
    }
};

class VehiculoNoEncontradoException : public Exception {
public:
    VehiculoNoEncontradoException(string placa) {
        this->mensaje = "El vehiculo con placa " + placa + " no existe";
    }
};

class NoHayEspaciosDisponiblesException : public Exception {
public:
    NoHayEspaciosDisponiblesException() {
        this->mensaje = "No existen espacios disponibles";
    }
};

class VehiculoYaAsignadoException : public Exception {
public:
    VehiculoYaAsignadoException(string placa) {
        this->mensaje = "El vehiculo con placa " + placa + " ya tiene un espacio asignado";
    }
};

template <class T>
class ListaGenerica 
{
private:
    int cantidad;
    int capacidad;
    T** elementos;

public:
    ListaGenerica(int capacidad) 
    {
        this->cantidad = 0;
        this->capacidad = capacidad;
        this->elementos = new T * [capacidad];
    }





    ~ListaGenerica()
    {
        for (int i = 0; i < cantidad; i++) 
        {
            delete elementos[i];
        }
        delete[] elementos;
    }






    int getCantidad() {
        return this->cantidad; 
    }




    bool estaLlena() { 
        return this->cantidad >= this->capacidad; 
    }




    T* obtener(int indice) { return this->elementos[indice]; 
    }





    void agregar(T* nuevo) {
        if (this->cantidad < this->capacidad) 
        {
            this->elementos[this->cantidad] = nuevo;
            this->cantidad++;
        }
    }

    T* buscar(string valor, string(*getter)(T*)) 
    
    
    {
        for (int i = 0; i < this->cantidad; i++) 
        {
            if (getter(this->elementos[i]) == valor) 
            {
                return this->elementos[i];
            }
        }
        return nullptr;
    }


    void ordenar(bool (*mayorQue)(T*, T*)) 
    {
       for (int i = 0; i < this->cantidad - 1; i++) 
       {
       for (int j = 0; j < this->cantidad - i - 1; j++) 
       {
          if (mayorQue(this->elementos[j], this->elementos[j + 1])) 
          {
               T* aux = this->elementos[j];
                  this->elementos[j] = this->elementos[j + 1];
                    this->elementos[j + 1] = aux;
           }
        }
        }
        }
};



	







