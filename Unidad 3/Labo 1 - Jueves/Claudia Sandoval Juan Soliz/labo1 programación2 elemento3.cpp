// labo1 programación2 elemento3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>

using namespace std;

class Exception {
protected:
    string mensaje;
public:
    Exception(string mensaje) {
        this->mensaje = mensaje;
    }
    string getMensaje() {
        return this->mensaje;
    }
};

class CapacidadMaximaEspaciosException : public Exception {
public:
    CapacidadMaximaEspaciosException() : Exception("Se alcanzo la capacidad maxima") {};
};

class CapacidadMaximaVehiculosException : public Exception {
public:
    CapacidadMaximaVehiculosException() : Exception("Se alcanzo la capacidad maxima") {};
};

template <class T>
class listaGenerica { // nomvre de clases empezar con Mayuscula
private:
    T** lista;
    int cantidad;
    int capacidad;
public:
    listaGenerica(int capacidad) {
        this->cantidad = 0;
        this->capacidad = capacidad;
        this->lista = new T * [capacidad];
    }

    ~listaGenerica() {
        for (int i = 0; i < this->cantidad; i++)
        {
            delete this->lista[i];
        }
        delete[] lista;
    }

    void agregar(T* nuevoElemento) {
        if (this->cantidad < this->capacidad) {
            lista[cantidad] = nuevoElemento;
            cantidad++;
        }
    }

    int getCantidad() {
        return this->cantidad;
    }

    int getCapacidad() {
        return this->capacidad;
    }

    bool estaLleno() {
        if (this->cantidad < this->capacidad){
            return false;
        }
        else {
            return true;
        }
    }

    // option 1
    T* buscar(string valorBuscado, string(*functionGetter)(T*)) {
        for (int i = 0; i < this->cantidad; i++)
        {
            string valorActual = functionGetter(this->lista[i]);
            if (valorActual == valorBuscado) {
                return this->lista[i];
            }
        }
        return nullptr;
    }

    // option 2
    T* buscar(string valorBuscado, bool (*functionConparador)(string, T*)) {
        for (int i = 0; i < this->cantidad; i++)
        {
            if (functionConparador(valorBuscado, this->lista[i]) == true) {
                return  this->lista[i];
            }
        }

        return nullptr;
    }

    
};

class Espacio {
private:
    string codigoEspacio;
    string nivel;
    string sector;
    bool ocupado;
public:
    Espacio(string codigoEspacio, string nivel, string sector) {
        this->codigoEspacio = codigoEspacio;
        this->nivel = nivel;
        this->sector = sector;
        this->ocupado = false;
    }

    string getCodigoEspacio() {
        return this->codigoEspacio;
    }

    // option 1
    static string getterCodigo(Espacio* espacio) {
        return espacio->codigoEspacio;
    }

    // option 2
    static bool compararCodigo(string codigoAComparar,  Espacio* espacio) {
        return codigoAComparar == espacio->codigoEspacio;
    }
    
};

class Vehiculo {
private:
    string placa;
    string marca;
    string modelo;
    string tipoVehiculo;
    Espacio* espacioAsignado;
public:
    Vehiculo(string placa, string marca, string modelo, string tipoVehiculo) {}

};

class SistemaParqueo {
private:
    string nombreEmpresa;
    string direccion;
    listaGenerica<Espacio>* listaEspacios;
    listaGenerica<Vehiculo>* listaVehiculo;
public:
    SistemaParqueo(string nombreEmpresa, string direccion, int capacidadMaximaEspacios, int capacidadMaximaVehiculos) {
        this->nombreEmpresa = nombreEmpresa;
        this->direccion = direccion;
        this->listaEspacios = new listaGenerica<Espacio>(capacidadMaximaEspacios);
        this->listaVehiculo = new listaGenerica<Vehiculo>(capacidadMaximaVehiculos);
    }

    /*T* getElemento(int) {

    }*/
    
    void registrarEspacio(Espacio* espacioNuevo) {

        try {
            if (listaEspacios->estaLleno() != false)
            {
                throw CapacidadMaximaEspaciosException();
            }
            if (listaEspacios->buscar(espacioNuevo->getterCodigo(), Espacio::compararCodigo)
            {
                listaEspacios->agregar(espacioNuevo);
            }
                
     

        }
        catch (Exception& e) {
            cout << "Error" << e.getMensaje();
        }
    }

    void registrarVehiculo(Vehiculo* vehiculoNuevo) {
        try {
            if (listaVehiculo->estaLleno() != false)
            {
                throw CapacidadMaximaVehiculosException();
            }
            listaVehiculo->agregar(vehiculoNuevo);
        }
        catch (Exception& e) {
            cout << "Error" << e.getMensaje();
        }
    }
    
    
};




int main()
{
    SistemaParqueo* h1 = new SistemaParqueo("Hupemall", "Pando", 10, 10);


    h1->registrarEspacio(new Espacio("E1", "piso1", "motos"));
    h1->registrarEspacio(new Espacio("E2", "piso1", "motos"));
    h1->registrarEspacio(new Espacio("E3", "piso12", "autos"));
    
    

}