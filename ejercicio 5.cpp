#include <iostream>

using namespace std;
enum TipoRemitente
{
    PARTICULAR,
    EMPRESA
};
enum TipoEnvio
{
    NORMAL,
    EXPRESS
};
class Remitente
{
private:
    string ci;
    string nombre;
    TipoRemitente tipoRemitente;

public:
    Remitente(string ci, string nombre)
    {
        this->ci = ci;
        this->nombre = nombre;
        this->tipoRemitente = PARTICULAR;
    }

    void setTipoRemitente(TipoRemitente tipo)
    {
        this->tipoRemitente = tipo;
    }

    TipoRemitente getTipoRemitente()
    {
        return this->tipoRemitente;
    }
    void mostrar()
    {
        cout << "CI: " << this->ci << endl;
        cout << "Nombre: " << this->nombre << endl;

        cout << "Tipo de remitente: ";

        if (this->tipoRemitente == PARTICULAR)
        {
            cout << "PARTICULAR" << endl;
        }
        else
        {
            cout << "EMPRESA" << endl;
        }
    }
};
class Paquete
{
private:
    string codigo;
    float peso;
    TipoEnvio tipoEnvio;

public:
    Paquete(string codigo, float peso, TipoEnvio tipoEnvio)
    {
        this->codigo = codigo;

        if (peso > 0)
        {
            this->peso = peso;
        }
        else
        {
            cout << "Error: el peso debe ser mayor que 0." << endl;
            this->peso = 1;
        }

        this->tipoEnvio = tipoEnvio;
    }
    
    void setPeso(float peso)
    {
        if (peso > 0)
        {
            this->peso = peso;
        }
        else
        {
            cout << "Error: el peso debe ser mayor que 0." << endl;
        }
    }
    float getPeso()
    {
        return this->peso;
    }
    void setTipoEnvio(TipoEnvio tipo)
    {
        this->tipoEnvio = tipo;
    }
    TipoEnvio getTipoEnvio()
    {
        return this->tipoEnvio;
    }
    void mostrar()
    {
        cout << "Codigo: " << this->codigo << endl;
        cout << "Peso: " << this->peso << " kg" << endl;

        cout << "Tipo de envio: ";

        if (this->tipoEnvio == NORMAL)
        {
            cout << "NORMAL" << endl;
        }
        else
        {
            cout << "EXPRESS" << endl;
        }
    }
};
class Envio
{
private:
    int numero;
    string destino;

    Remitente remitente;
    Paquete paquete;

    float distancia;
    float costo;

public:
    Envio(
        int numero,
        string destino,
        Remitente remitente,
        Paquete paquete,
        float distancia
    ) : remitente(remitente), paquete(paquete)
    {
        this->numero = numero;
        this->destino = destino;

        if (distancia > 0)
        {
            this->distancia = distancia;
        }
        else
        {
            cout << "Error: la distancia debe ser mayor que 0." << endl;
            this->distancia = 1;
        }

        this->costo = calcularCostoFinal();
    }
    float calcularCostoBase()
    {
        return this->paquete.getPeso()
            * this->distancia
            * 0.50;
    }


 
    float calcularCostoFinal()
    {
        float costoFinal = calcularCostoBase();


        
        if (this->paquete.getTipoEnvio() == EXPRESS)
        {
            costoFinal = costoFinal * 1.25;
        }
        if (this->remitente.getTipoRemitente() == EMPRESA)
        {
            costoFinal = costoFinal * 0.90;
        }


     
        if (this->paquete.getPeso() > 10)
        {
            float kilosExtra = this->paquete.getPeso() - 10;

            costoFinal = costoFinal + (kilosExtra * 5);
        }


        return costoFinal;
    }


   

    void setDistancia(float distancia)
    {
        if (distancia > 0)
        {
            this->distancia = distancia;

            this->costo = calcularCostoFinal();
        }
        else
        {
            cout << "Error: la distancia debe ser mayor que 0." << endl;
        }
    }



    void setTipoEnvio(TipoEnvio tipo)
    {
        this->paquete.setTipoEnvio(tipo);

        this->costo = calcularCostoFinal();
    }


  

    void setTipoRemitente(TipoRemitente tipo)
    {
        this->remitente.setTipoRemitente(tipo);

        this->costo = calcularCostoFinal();
    }




    void mostrar()
    {
        cout << endl;
        cout << "==================================" << endl;
        cout << "             ENVIO                " << endl;
        cout << "==================================" << endl;

        cout << "Numero: " << this->numero << endl;
        cout << "Destino: " << this->destino << endl;
        cout << "Distancia: " << this->distancia << " km" << endl;

        cout << endl;

        cout << "--- REMITENTE ---" << endl;
        this->remitente.mostrar();

        cout << endl;

        cout << "--- PAQUETE ---" << endl;
        this->paquete.mostrar();

        cout << endl;

        cout << "Costo base: " << calcularCostoBase() << endl;
        cout << "Costo final: " << calcularCostoFinal() << endl;
    }
};




int main()
{

    cout << "===== CREANDO REMITENTE =====" << endl;

    Remitente remitente1("1234567", "Juan Perez");

    remitente1.mostrar();
    cout << endl;
    cout << "===== CAMBIANDO REMITENTE A EMPRESA =====" << endl;

    remitente1.setTipoRemitente(EMPRESA);

    remitente1.mostrar();
    cout << endl;
    cout << "===== CREANDO PAQUETE =====" << endl;

    Paquete paquete1(
        "PK001",
        15,
        EXPRESS
    );
    paquete1.mostrar();
    cout << endl;
    cout << "===== MODIFICANDO PESO =====" << endl;

    paquete1.setPeso(20);

    paquete1.mostrar();


    cout << endl;
    cout << "Probando peso invalido..." << endl;

    paquete1.setPeso(-5);
    cout << endl;
    cout << "===== CREANDO ENVIO =====" << endl;

    Envio envio1(
        1001,
        "Cochabamba",
        remitente1,
        paquete1,
        200
    );
    envio1.mostrar();
    cout << endl;
    cout << "===== CALCULOS =====" << endl;

    cout << "Costo base: "
        << envio1.calcularCostoBase()
        << endl;

    cout << "Costo final: "
        << envio1.calcularCostoFinal()
        << endl;



    cout << endl;
    cout << "===== MODIFICANDO DISTANCIA =====" << endl;
    envio1.setDistancia(300);
    envio1.mostrar();
    cout << endl;
    cout << "Probando distancia invalida..." << endl;
    envio1.setDistancia(-50);
    cout << endl;
    cout << " CAMBIANDO TIPO DE ENVIO " << endl;
    envio1.setTipoEnvio(NORMAL);
    envio1.mostrar();
    cout << endl;
    cout << " CAMBIANDO REMITENTE A PARTICULAR" << endl;
    envio1.setTipoRemitente(PARTICULAR);
    envio1.mostrar();
    return 0;
}