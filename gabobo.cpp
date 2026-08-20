#include<string>
#include <iostream>
using namespace std;

class Remitente {
private:
    int ci;
    string nombre;
    string tipoRemitente;
public:
   Remitente(int ci,  string nombre,  string tipoRemitente)
    {
        this->ci = ci;
        this->nombre = nombre;
        this->tipoRemitente = "Particular";
    }
    void mostrar() {
        cout << "Ci: " << ci << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo de remitente: " << tipoRemitente << endl;
    }
    string getTipoRemitente() {
        return tipoRemitente;
    }
};

class Paquete {
private:
    int codigo;
    double peso;
    string tipoEnvio;
public:
    Paquete(int codigo, int peso,  string tipoEnvio)
        : codigo(codigo), peso(peso), tipoEnvio(tipoEnvio)
    {
        this->codigo = codigo;
        this->peso = peso;
        this->tipoEnvio = "Normal";
    }
    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Peso: " << peso << endl;
        cout << "Tipo de envio: " << tipoEnvio << endl;
    }
    void setNewPeso(double peso) {
        if (peso > 0) {
            this->peso = peso;
        }else {
            cout << "Peso ingresado negativo o nulo." << endl;
        }
    }
    double getPeso() {
        return peso;
    }
    string getTipoEnvio() {
        return tipoEnvio;
    }
};

class Envio {
private:
    int numero;
    string destino;
    Remitente* remis;
    Paquete* paquetes;
    double distancia;
    double costo;
public:

    double calcularCosto(int distancia, Paquete* paquetes,Remitente* remis) {
        double peso = paquetes->getPeso();
        string tipoenvio = paquetes->getTipoEnvio();
        string tiporemi= remis->getTipoRemitente();
        double pes = paquetes->getPeso();
        double cost = peso * distancia * 0.5;
        if (tipoenvio == "Express") {
            costo = costo+(costo*0.25);
        }
        if (tiporemi == "Empresa") {
            costo = costo-(costo*0.10);
        }
        if (pes > 10) {
            costo = costo -10 *(costo * 0.05);
        }
        return costo;
    }
    Envio(int numero, const string destino, Remitente* remis, Paquete* paquetes, double distancia)
        : numero(numero), destino(destino), remis(remis), paquetes(paquetes), distancia(distancia)
    {
        this->numero = numero;
        this->destino = destino;
        this->remis = nullptr;
        this->paquetes = nullptr;
        if (distancia > 0) { this->distancia = distancia; }
        else {
            cout << "Distancia establecia en 0 por distancia negativa";   this->distancia = 0;
        }
        this->costo = calcularCosto(distancia,paquetes,remis);
    }
    void mostrar() {
        cout << "Numero: " << numero << endl;
        cout << "Destino: " << destino << endl;
        cout << "Remitente: " << endl;
        remis->mostrar();
        cout << "Paquetes: " << endl;
        paquetes->mostrar();
        cout << "Distancia: " << distancia << endl;
        cout << "Costo: " << costo << endl;
    }
   
};


int main()
{
    std::cout << "Hello World!\n";
}
