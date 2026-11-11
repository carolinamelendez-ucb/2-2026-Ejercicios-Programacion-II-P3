// Juan Soliz, Jorge Vargas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//necesitamos que tenga lista genernica, punteros a funciones y gerarquia de exceptions en clases solo iostream, string y std
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

class EnvioDuplicadoException : public Exception {
public:
    EnvioDuplicadoException() :Exception("El envio esta duplicado") {}
};

class ClienteDuplicadoException : public Exception {
public:
    ClienteDuplicadoException() :Exception("El codigo del cliente esta duplicado") {}
};

class ClienteNoEncontradoException : public Exception {
public:
    ClienteNoEncontradoException() :Exception("El cliente no fue encontrado") {}
};

template <class T>

class ListaGenerica {
private:
    int cantidad;
    int capacidad;
    T** lista;
public:
    ListaGenerica(int capacidad) {
        this->cantidad = 0;
        this->capacidad = capacidad;
        this->lista = new T * [capacidad];
    }

    ~ListaGenerica() {
        for (int i = 0; i < capacidad; i++)
        {
            delete lista[i];
        }
        delete[] lista;
    }

    int getCantidad() {
        return cantidad;
    }

    string getElemento(int indice) {
        if (indice >= 0 && indice < cantidad)
        {
            
        }
    }

    T* buscar(string elementoBuscado, string(*funcionGetter)(T*)) {
        for (int i = 0; i < cantidad; i++)
        {
            string elementoActual = funcionGetter(lista[i]);
            if (elementoActual == elementoBuscado)
            {
                return lista[i];
            }
        }
        return nullptr;
    }

    void agregar(T* nuevoElemento) {
        if (cantidad < capacidad)
        {
            lista[cantidad] = nuevoElemento;
            cantidad++;  
        }
    }

};

class Cliente {
private:
    string ci;
    string nombre;
    string telefono;
    string direccion;
public:
    Cliente(string ci, string nombre, string telefono, string direccion) {
        this->ci = ci;
        this->nombre = nombre;
        this->telefono = telefono;
        this->direccion = direccion;
    }

    string getCi() {
        return this->ci;
    }

    static string getCiEstatico(Cliente* c) {
        return c->ci;
    }
};

class PaqueteNormal {
private:
    string codigoPaquete;
    string description;
    double peso;
    double costoPorKg;
public:
    PaqueteNormal(string codigoPaquete, string description, double peso, double costo) {
        this->codigoPaquete = codigoPaquete;
        this->description = description;
        this->peso = peso;
        this->costoPorKg = costo;
    }

    double calcularCosto() {
        double costo;
        return costo = this->costoPorKg * this->peso;
    }

};

class Envio {
private:
    string numeroEnvio;
    string fechaEnvio;
    double pesoMax;
    Cliente* cliente;
    ListaGenerica<PaqueteNormal>* listaPaquetes;
public:
    Envio(string numeroEnvio, string fechaEnvio, double pesoMax, int capPaquetes) {
        this->numeroEnvio = numeroEnvio;
        this->fechaEnvio = fechaEnvio;
        this->pesoMax = pesoMax;
        this->cliente = nullptr;
        this->listaPaquetes = new ListaGenerica<PaqueteNormal>(capPaquetes);
    }

    string getCodigo() {
        return this->numeroEnvio;
    }

    static string getCodigoEstatico(Envio* e) {
        return e->numeroEnvio;
    }


};

class SistemaEnvios {
    private:
        string nombreEmpresa;
        ListaGenerica<Cliente>* listaClientes;
        ListaGenerica<Envio>* listaEnvios;

        
public:
    SistemaEnvios(string nombreEmpresa, int maxClientes, int macEnvios) {
        this->nombreEmpresa = nombreEmpresa;
        this->listaClientes = new ListaGenerica<Cliente>(maxClientes);
        this->listaEnvios = new ListaGenerica<Envio>(macEnvios);
    }

    void registrarCliente(Cliente* nuevoCliente) {
        //Cliente* clienteConCiDuplicado = listaClientes->buscar(nuevoCliente->getCi(), Cliente::getCiEstatico);

        // clienteConCiDuplicado == nullptr?
        // clienteConCiDuplicado != nullptr?
        
        if (listaClientes->buscar(nuevoCliente->getCi(), Cliente::getCiEstatico) != nullptr)
        {
            throw ClienteDuplicadoException();
        }
        listaClientes->agregar(nuevoCliente);
    }

    void registrarEnvio(Envio* nuevoEnvio) {
        //Cliente* clienteConCiDuplicado = listaClientes->buscar(nuevoCliente->getCi(), Cliente::getCiEstatico);

        // clienteConCiDuplicado == nullptr?
        // clienteConCiDuplicado != nullptr?

        if (listaEnvios->buscar(nuevoEnvio->getCodigo(), Envio::getCodigoEstatico) != nullptr)
        {
            throw EnvioDuplicadoException();
        }
        listaEnvios->agregar(nuevoEnvio);
    }

    void registrarEnvioParaCliente(string ciCliente, Envio* nuevoEnvio) {

    }

};


int main()
{
    SistemaEnvios* s1 =new SistemaEnvios("Copacabana", 10, 10);

    try {
        s1->registrarCliente(new Cliente("12713688", "juanSoliz", "75915586", "Arturo Daza Rojas"));
        s1->registrarCliente(new Cliente("12713688", "juanSoliz", "75915586", "Arturo Daza Rojas"));
        s1->registrarCliente(new Cliente("12345678", "juanPerez", "71234567", "Antonio Avila"));
    }
    catch (Exception& e) {
        cout << "Error: " << e.getMensaje() << endl;
    }

    try {
        s1->registrarEnvio(new Envio("001", "12-11-2026", 20, 3));
        s1->registrarEnvio(new Envio("002", "15-11-2026", 20, 3));
        s1->registrarEnvio(new Envio("003", "14-11-2026", 20, 3));
        s1->registrarEnvio(new Envio("002", "13-11-2026", 20, 3));

    }
    catch (Exception& e) {
        cout << "Error: " << e.getMensaje() << endl;
    }



}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
