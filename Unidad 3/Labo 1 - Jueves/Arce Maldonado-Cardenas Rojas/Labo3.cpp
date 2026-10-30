
#include<iostream>
#include<string>
//#include"ListaGenerica.h"
//#include"SistemaParqueo.h"

using namespace std;


class Vehiculo
{
private:
    string placa;
    string marca;
    string modelo;
    string tipoVehiculo;
    Espacio* espacioAsignado;

public:
    Vehiculo(string placa, string marca, string modelo, string tipoVehiculo) {
        this->placa = placa;
        this->marca = marca;
        this->modelo = modelo;
        this->tipoVehiculo = tipoVehiculo;
        this->espacioAsignado = nullptr;
    }

    bool estaEstacionado()
    {
        return this->espacioAsignado != nullptr;
    }

    void asignarEspacio(Espacio* espacio) {
        this->espacioAsignado = espacio;
        espacio->ocupar();
    }

    void mostrar() {
        cout << "Placa: " << placa << "Marca: " << marca
            << "Modelo: " << modelo << "Tipo: " << tipoVehiculo << endl;
        if (this->espacioAsignado != nullptr) {
            this->espacioAsignado->mostrar();
        }
        else {
            cout << "Sin espacio asignado" << endl;
        }
    }

    static string getPlaca(Vehiculo* v)
    {
        return v->placa;
    }
    static bool marcaMayorQue(Vehiculo* a, Vehiculo* b) { return a->marca > b->marca; }
};

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




    T* obtener(int indice) {
        return this->elementos[indice];
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
class Espacio {
private:
    string codigoEspacio;
    int nivel;
    string sector;
    string estado;
public:
    Espacio(string codigoEspacio, int nivel, string sector) {
        this->codigoEspacio = codigoEspacio;
        this->nivel = nivel;
        this->sector = sector;
        this->estado = "Disponible";
    }

    bool estaDisponible() { return this->estado == "Disponible"; }
    void ocupar() { this->estado = "Ocupado"; }
    void mostrar() {
        cout << "  Espacio: " << codigoEspacio
            << "Nivel: " << nivel
            << "Sector: " << sector
            << "Estado: " << estado << endl;
    }

    static string getCodigo(Espacio* e) { return e->codigoEspacio; }
};

class SistemaParqueo {
private:
    string nombreEmpresa;
    string direccion;
    int capacidadMaxima;
    ListaGenerica<Espacio>* listaEspacios;
    ListaGenerica<Vehiculo>* listaVehiculos;

public:
    SistemaParqueo(string nombreEmpresa, string direccion, int capacidadMaxima) {
        this->nombreEmpresa = nombreEmpresa;
        this->direccion = direccion;
        this->capacidadMaxima = capacidadMaxima;
        this->listaEspacios = new ListaGenerica<Espacio>(capacidadMaxima);
        this->listaVehiculos = new ListaGenerica<Vehiculo>(capacidadMaxima);
    }

    ~SistemaParqueo() {
        delete listaEspacios;
        delete listaVehiculos;
    }

    void registrarEspacio(string codigo, int nivel, string sector) {
        if (listaEspacios->estaLlena()) {
            throw CapacidadMaximaEspaciosException(capacidadMaxima);
        }
        if (listaEspacios->buscar(codigo, Espacio::getCodigo) != nullptr) {
            throw CodigoEspacioDuplicadoException(codigo);
        }
        listaEspacios->agregar(new Espacio(codigo, nivel, sector));
    }

    void registrarVehiculo(string placa, string marca, string modelo, string tipo) {
        if (listaVehiculos->estaLlena()) {
            throw CapacidadMaximaVehiculosException(capacidadMaxima);
        }
        if (listaVehiculos->buscar(placa, Vehiculo::getPlaca) != nullptr) {
            throw PlacaDuplicadaException(placa);
        }
        listaVehiculos->agregar(new Vehiculo(placa, marca, modelo, tipo));
    }

    void asignarEspacioAutomatico(string placa) {
        Vehiculo* vehiculo = listaVehiculos->buscar(placa, Vehiculo::getPlaca);
        if (vehiculo == nullptr) {
            throw VehiculoNoEncontradoException(placa);
        }
        if (vehiculo->estaEstacionado()) {
            throw VehiculoYaAsignadoException(placa);
        }

        for (int i = 0; i < listaEspacios->getCantidad(); i++) {
            Espacio* actual = listaEspacios->obtener(i);
            if (actual->estaDisponible()) {
                vehiculo->asignarEspacio(actual);
                return;
            }
        }
        throw NoHayEspaciosDisponiblesException();
    }

    void mostrarVehiculosEstacionados() {
        cout << "vehiculos estacionados (" << nombreEmpresa << direccion << ")" << endl;
        bool hay = false;
        for (int i = 0; i < listaVehiculos->getCantidad(); i++) {
            Vehiculo* v = listaVehiculos->obtener(i);
            if (v->estaEstacionado()) {
                v->mostrar();
                hay = true;
            }
        }
        if (!hay) cout << "Ninguno" << endl;
    }
};

int main() 
{
    SistemaParqueo* sistema = new SistemaParqueo("Centro Comercial Las Torres", "Av. Principal 123", 3);

   
    try {
        sistema->registrarEspacio("A01", 1, "A");
        sistema->registrarEspacio("A02", 1, "A");
        sistema->registrarEspacio("A01", 2, "B"); 
    }
    catch (Exception e) {
        cout << "Error: " << e.getMensaje() << endl;
    }

    try 
    { 
       
        sistema->asignarEspacioAutomatico("1234ABC"); 
    }
    catch (Exception& e) 
    {
        
        
        cout << "Error: " << e.getMensaje() << endl; 
    }

    try {
       
        sistema->asignarEspacioAutomatico("5678DEF"); 
    }
    catch (Exception& e) 
    { 
        cout << "Error: " << e.getMensaje() << endl; 
    }

  
   
    delete sistema;
}