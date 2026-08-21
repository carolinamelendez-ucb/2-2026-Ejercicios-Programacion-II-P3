// ejercicio_5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

using namespace std;

/////////////////////////////////////////////enums////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////clase remitente////////////////////////////////////////////////////////////////
class Remitente 
{
private:
	int ci;
	string nombre;
	TipoRemitente tipoRemitente;
public:
	Remitente() 
	{
		ci = 0;
		nombre = "";
		tipoRemitente = PARTICULAR;
	}
	Remitente(int ci, string nombre)
	{
		this->ci = ci;
		this->nombre = nombre;
		this->tipoRemitente = PARTICULAR;
	}
	int getCi() {
		return ci;
	}
	string getNombre() {
		return nombre;
	}
	TipoRemitente getTipoRemitente(){
		return tipoRemitente;
	}
	void setTipoRemitente(TipoRemitente nuevoTipoRemitente) {
			this->tipoRemitente = nuevoTipoRemitente;
		
	}
	void mostrar() {
		cout << "ci: " << ci << endl;
		cout << "nombre: " << nombre << endl;
		cout << "tipo remitente: ";
		if (tipoRemitente == PARTICULAR){
			cout << "PARTICULAR";
		}
		else{
			cout << "EMPRESA";
		}
		cout << endl;
	}
};
/////////////////////////////////////////////clase paquete////////////////////////////////////////////////////////////////
class Paquete {
private:
	int codigo;
	float peso;
	TipoEnvio tipoEnvio;
public:
	Paquete() {
		codigo = 0;
		peso = 0;
		tipoEnvio = NORMAL;
	}
	Paquete(int codigo, float peso, TipoEnvio tipoEnvio)
	{
		this->codigo = codigo;
		this->tipoEnvio = tipoEnvio;
		if (peso > 0) {
			this->peso = peso;
		}
		else cout << "el peso debe ser mayor que cero..." << endl << endl;
	}
	int getCodigo() {
		return codigo;
	}
	float getPeso() {
		return peso;
	}
	TipoEnvio getTipoEnvio() {
		return tipoEnvio;
	}
	void setPeso(float nuevoPeso) {
		if (nuevoPeso > 0) {
			this->peso = nuevoPeso;
		}
		else cout << "peso debe ser mayor a cero, no se proceso el cambio..." << endl << endl;
	}
	void setTipoEnvio(TipoEnvio nuevoTipoEnvio) {
		this->tipoEnvio = nuevoTipoEnvio;
	}
	void mostrar() {
		cout << "codigo: " << codigo << endl;
		cout << "peso: " << peso << endl;
		cout << "tipo envio: ";
		if (tipoEnvio == NORMAL){
			cout << "NORMAL";
		}
		else{
			cout << "EXPRESS";
		}
		cout << endl;
	}
};
/////////////////////////////////////////////clase envio////////////////////////////////////////////////////////////////
class Envio {
private:
	int numero;
	string destino;
	float distancia;
	float costo;

	Remitente* remitentes;
	Paquete* paquetes;
public:
	Envio() {
		numero = 0;
		destino = "";
		distancia = 0;
		costo = 0;
	}
	Envio(int numero, string destino, float distancia, float costo, Remitente* remitentes, Paquete* paquetes)
	{
		this->numero = numero;
		this->destino = destino;
		this->costo = costo;
		this->remitentes = remitentes;
		this->paquetes = paquetes;
		if (distancia > 0){
			this->distancia = distancia;
		}
		else{
			this->distancia = 0;
			cout << "error, la distancia debe ser mayor que 0..." << endl;
		}
	}
	float costoBase() {
		float costBas = 0.5 * distancia * paquetes->getPeso();
		return costBas;
	}
	float descuentoTotal() {
		if (remitentes->getTipoRemitente() == EMPRESA) {
			float descTot = costoBase() * 0.1;
			return descTot;
		}
		else return 0;	
	}
	float recargo1() {
		if (paquetes->getTipoEnvio() == EXPRESS) {
			float num1 = costoBase() * 0.25;
			return num1;
		}
		else return 0;
	}
	float recargo2() {
		float num2 = 0;
		for (float i = paquetes->getPeso(); i > 10; i--) {
			num2 += 5;
		}
		return num2;
	}
	void setDistancia(float nuevaDist) {
		if (nuevaDist > 0) {
			this->distancia = nuevaDist;
		}
		else cout << "error... solo desde 0 en arriba..." << endl << endl;
	}
	void mostrar() {
		cout << "numero: " << numero << endl;
		cout << "destino: " << destino << endl;
		cout << "distancia: " << distancia << endl;
		cout << "costo: " << costo << endl;
		cout << "-----------------------------" << endl;
		cout << "remitente: " << endl;
		remitentes->mostrar();
		cout << "-----------------------------" << endl;
		cout << "paquete: " << endl;
		paquetes->mostrar();
		cout << "-----------------------------" << endl;
		cout << "costo base -> " << costoBase() << endl;
		cout << "descuentos totales: " << descuentoTotal() << endl;
		cout << "recargos totales: " << recargo1() + recargo2() << endl;
		cout << "costo final: " << costoBase() + recargo1() + recargo2() - descuentoTotal() << endl;
	}
	~Envio() {
		delete remitentes;
		delete paquetes;
	}
};
/////////////////////////////////////////////main////////////////////////////////////////////////////////////////
int main()
{
	Remitente* remitenteRichard = new Remitente(123, "Richard");
	remitenteRichard->mostrar();
	cout << endl;

	Paquete* paqueteLinux = new Paquete(555, 24, EXPRESS);
	paqueteLinux->mostrar();
	cout << endl;

	paqueteLinux->setPeso(12);
	paqueteLinux->mostrar();
	cout << endl;

	Envio envioArgentina = Envio(1, "Argentina", 4000, 200, remitenteRichard, paqueteLinux);
	envioArgentina.mostrar();
	cout << endl;

	envioArgentina.setDistancia(3000);
	envioArgentina.mostrar();
	cout << endl;

	paqueteLinux->setTipoEnvio(NORMAL);
	envioArgentina.mostrar();
	cout << endl;

	remitenteRichard->setTipoRemitente(EMPRESA);
	envioArgentina.mostrar();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
