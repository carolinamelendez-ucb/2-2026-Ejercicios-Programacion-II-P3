// tarea18-08-2026.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;
enum TipoRemitente { PARTICULAR, EMPRESA};
enum TipoEnvio {NORMAL,EXPRESS};

class Remitente {
private:
    string ci;
    string nombre;
    TipoRemitente tipo;
public:
    Remitente(string ci, string nombre) {
        this->ci = ci;
        this->nombre = nombre;
        this->tipo = PARTICULAR;
    }
    Remitente(string ci, string nombre, TipoRemitente tipo) {
        this->ci = ci;
        this->nombre = nombre;
        this->tipo = tipo;
    }
    TipoRemitente getTipo() const { return tipo; }
    void setTipo(TipoRemitente nuevoTipo) 
    {
        this->tipo = nuevoTipo; 
    }
    void mostrarInformacion() const {
        string strTipo = (tipo == PARTICULAR) ? "PARTICULAR" : "EMPRESA";
        cout << "Remitente CI: " << ci << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << strTipo << endl;
    }

};

class Paquete {
private:
    string codigo;
    double peso;
    TipoEnvio tipoEnvio;
public:
    Paquete(string codigo, double peso, TipoEnvio tipoEnvio) {
        this->codigo = codigo;
        this->tipoEnvio = tipoEnvio;

        if (peso > 0) {
            this->peso = peso;
        }
        else {
            cout << "Error: El peso debe ser mayor que 0. valor ingresado: " << peso << " invalido." << endl;
            this->peso = 1.0;
        }
    }
    void setPeso(double nuevoPeso) {
        if (nuevoPeso > 0) {
            this->peso = nuevoPeso;
        }
        else {
            cout << "Error al modificar: El nuevo peso debe ser mayor que 0. Valor ingresado: " << nuevoPeso << endl;
        }
    }
    void setTipoEnvio(TipoEnvio nuevoTipo) 
    {
        this->tipoEnvio = nuevoTipo; 
    }
    double getPeso() const { return peso; }
    TipoEnvio getTipoEnvio() const { return tipoEnvio; }

    void mostrarInformacion()const {
        string strEnvio = (tipoEnvio == NORMAL) ? "NORMAL" : "EXPRESS";
        cout << "Paquete Codigo: " << codigo << endl;
        cout << "Peso: " << peso << " kg" << endl;
        cout << "Tipo Envio: " << strEnvio << endl;
    }
};

class Envio {
private:
    int numero;
    string destino;
    Remitente remitente;
    Paquete paquete;
    double distancia;
public:
    Envio(int numero, string destino, Remitente remitente, Paquete paquete, double distancia) : remitente(remitente), paquete(paquete) {
        this->numero = numero;
        this->destino = destino;

        if (distancia > 0) {
            this->distancia = distancia;
        }
        else {
            cout << "Error: La distancia debe ser mayor que 0. Valor ingresado " << distancia << " invalido." << endl;
            this->distancia = 1.0;
        }
    }
    void setDistancia(double nuevaDistancia) {
        if (nuevaDistancia > 0) {
            this->distancia = nuevaDistancia;
        }
        else {
            cout << "Error: la nueva distancia debe sermayor que 0. Valor ingresado: " << nuevaDistancia << endl;
        }
    }
    double calcularCostoBase() const {
        return paquete.getPeso() * distancia * 0.50;
    }
    double calcularCostoFInal() const {
        double costoBase = calcularCostoBase();
        double costoAcumulado = costoBase;

        if (paquete.getTipoEnvio() == EXPRESS) {
            costoAcumulado += costoBase * 0.25;
        }
        if (paquete.getPeso() > 10.0) {
            double kilosExtra = paquete.getPeso() - 10.0;
            costoAcumulado += kilosExtra * 5.0;
        }
        return costoAcumulado;
    }
    void mostrarInformacion() const {
        cout << "Numero de Envio: " << numero << "destino: " << destino << endl;
        cout << "distancia: " << distancia << " km" << endl;
        remitente.mostrarInformacion();
        paquete.mostrarInformacion();
        cout << "costo base: " << calcularCostoBase() << endl;
        cout << "costo final calculado: " << calcularCostoFInal() << endl;
    }
    Remitente& getRemitente() { return remitente; }
    Paquete& getPaquete() { return paquete; }
};

int main()
{
    cout << "creacion de objetos" << endl;
    Remitente r1("1234567", "Carlos Perez");
    cout << "provando validacion de peso invalido" << endl;
    Paquete p1("PKG-100", -5.0, EXPRESS);
    Paquete p2("PKG-200", 12.0, EXPRESS);
    Envio envio1(101, "Santa Cruz", r1, p2, 100.0);
    envio1.mostrarInformacion();

    cout << "cambios y reglas de negocio" << endl;
    cout << "Cambiando Remitente a EMPRESA (Aplica 10% de descuento)" << endl;
    envio1.getRemitente().setTipo(EMPRESA);
    envio1.setDistancia(200.0);
    envio1.mostrarInformacion();
    cout << "probando setter de distancia invalida" << endl;
    envio1.setDistancia(-50.0);


    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
