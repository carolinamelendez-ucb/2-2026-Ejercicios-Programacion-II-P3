// Ejercicio5_TareaPrograII.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream> 
#include <string> 

using namespace std;

enum tipoReminente
{
    PARTICULAR,
    EMPRESA
};

class Remitente
{
private:
    int CI;
    string nombre;
    tipoReminente tiporeminente;
public:
    Remitente()
    {
        CI = 0;
        nombre = "";
        tiporeminente = PARTICULAR;
    }

    Remitente(int CI, const string& nombre, const tipoReminente& tiporeminente)
        : CI(CI), nombre(nombre), tiporeminente(tiporeminente)
    {
        this->CI = CI;
        this->nombre = nombre;
        this->tiporeminente = tiporeminente;
    }

    void mostrarInfoReminente()
    {
        cout << "nombre: " << nombre << endl;
        cout << "CI: " << CI << endl;
        if (tiporeminente == PARTICULAR)
        {
            cout << "tipo de reminente es PARTICULAR. " << endl;
        }
        else
        {
            cout << "tipo de reminente es de EMPRESA. " << endl;
        }
    }

    tipoReminente getTipoReminente()
    {
        return tiporeminente;
    }

    void setTipoReminente(tipoReminente nuevoTipo)
    {
        if (nuevoTipo == PARTICULAR || nuevoTipo == EMPRESA)
        {
            tiporeminente = nuevoTipo;
        }
        else
        {
            cout << "Tipo de remitente invalido." << endl;
        }
    }

};

enum tipoEnvio
{
    NORMAL,
    EXPRESS
};


class Paquete
{
private:
    int codigo;
    int peso;
    tipoEnvio tipoenvio;
public:
    Paquete()
    {
        codigo = 0;
        peso = 0;
        tipoenvio = NORMAL;
    }

    Paquete(int codigo, int peso, const tipoEnvio& tipoenvio)
        : codigo(codigo), peso(peso), tipoenvio(tipoenvio)
    {

    }


    void setPeso(int nuevoPeso)
    {
        if (nuevoPeso < 0)
        {
            cout << "Valor de peso invalido , el peso que ingreso fue: " << nuevoPeso << endl;
        }
        else
        {
            this->peso = nuevoPeso;
        }

    }

    int getPeso()
    {
        return peso;
    }

    tipoEnvio getTipoEnvio()
    {
        return tipoenvio;
    }

    void setTipoEnvio(tipoEnvio nuevoTipo)
    {
        if (nuevoTipo == NORMAL || nuevoTipo == EXPRESS)
        {
            tipoenvio = nuevoTipo;
        }
        else
        {
            cout << "Tipo de envio invalido." << endl;
        }
    }

    void mostrarPaquete()
    {
        if (tipoenvio == NORMAL)
        {
            if (peso >= 1)
            {
                cout << "CODIGO: " << codigo << endl;
                cout << "PESO: " << peso << endl;
                cout << "TIPO DE ENVIO NORMAL" << endl;
            }
            else
                cout << "Error en el peso , no se pudo establecer " << endl;
        }
        else
        {
            if (peso >= 1)
            {
                cout << "CODIGO: " << codigo << endl;
                cout << "PESO: " << peso << endl;
                cout << "TIPO DE ENVIO EXPRESS" << endl;
            }
            else
                cout << "Error en el peso , no se pudo establecer " << endl;
        }
    }


};

class Envio
{
private:
    int numero;
    string destino;
    Remitente* remitente;
    Paquete* paquete;
    int distancia;
    int costo;
public:

    Envio()
    {
        numero = 0;
        destino = "";
        costo = 0;
        distancia = 0;
    }

    Envio(int numero, const string& destino, Remitente* remitente, Paquete* paquete, int distancia, int costo)
        : numero(numero), destino(destino), remitente(remitente), paquete(paquete), distancia(distancia), costo(costo)
    {
        this->numero = numero;
        this->destino = destino;
        this->remitente = remitente;
        this->paquete = paquete;
        if (distancia < 0)
        {
            cout << "No es posiblke poner esa distancia , distancia puesta: " << distancia << endl;
        }
        else this->distancia = distancia;
        this->costo = costo;
    }

    void setDistancia(int nuevaDistancia)
    {
        if (nuevaDistancia > 0)
        {
            distancia = nuevaDistancia;
            calcularCostoFinal();
        }
        else
        {
            cout << "Error: la distancia debe ser mayor que 0." << endl;
        }
    }

    void calcularCostoFinal()
    {
        costo = paquete->getPeso() * distancia * 0.50;

        if (paquete->getTipoEnvio() == EXPRESS)
        {
            costo = costo + (costo * 0.25);
        }

        if (remitente->getTipoReminente() == EMPRESA)
        {
            costo = costo - (costo * 0.10);
        }

        if (paquete->getPeso() > 10)
        {
            costo = costo + ((paquete->getPeso() - 10) * 5);
        }
    }

    void mostrarEnvio()
    {
        cout << "NUMERO: " << numero << endl;
        cout << "DESATINO: " << destino << endl;
        remitente->mostrarInfoReminente();
        paquete->mostrarPaquete();
        cout << "DISTANCIA: " << distancia << endl;
        cout << "COSTO: " << costo << endl;
    }

};

int main()
{
    Remitente r1(123456, "Alejandro", PARTICULAR);

    Paquete p1(1001, 15, EXPRESS);

    Envio e1(1, "SANTA PUEJ", &r1, &p1, 100, 0);


    e1.calcularCostoFinal();

    cout << " ENVIO INICIAL " << endl;
    e1.mostrarEnvio();

    cout << " MODIFICANDO DISTANCIA " << endl;
    e1.setDistancia(200);
    e1.mostrarEnvio();

    cout << " DISTANCIA INVALIDA " << endl;
    e1.setDistancia(-50);

    cout << " CAMBIANDO TIPO DE ENVIO " << endl;
    p1.setTipoEnvio(NORMAL);

    e1.calcularCostoFinal();
    e1.mostrarEnvio();


    cout << " CAMBIANDO TIPO DE REMITENTE " << endl;
    r1.setTipoReminente(EMPRESA);

    e1.calcularCostoFinal();
    e1.mostrarEnvio();
}