#pragma once
#include<iostream>
#include<string>
using namespace std;
class Paquete{
protected:
	string codPaquete;
	string descripcion;
	float peso;
	float costoKilo;
	string tipo;

public:
		Paquete(const string& codPaquete, const string& descripcion, float peso, float costoKilo, const string& tipo)
	    {
			this->codPaquete = codPaquete;
			this->costoKilo = costoKilo;
			this->descripcion = descripcion;
			this->peso = peso;
			this->tipo = tipo;
	    }
		virtual~Paquete() {

	    }
		string getcodigo() {
			return this->codPaquete;
		}
		float getpeso() {
			return this->peso;
		}
		virtual float calcularCosto() = 0;
	
		virtual void mostrar() {
			cout << "Codigo de paquete: " << this->codPaquete << endl;
			cout << "Descripcion del paquete: " << this->descripcion << endl;
			cout << "Peso del paquete: " << this->peso << endl;
			cout << "Costo por kilo: " << this->costoKilo << endl;
			cout << "Tipo de paquete: " << this->tipo << endl;
		}
		static string getterCodigo(Paquete* p) {
			return p->codPaquete;
		}
};
class Normal:public Paquete {
public:
	Normal(string codPaquete,string descripcion, float peso,float costoKilo)
		:Paquete(codPaquete, descripcion,peso,costoKilo,"NORMAL") { 

	}
	float calcularCosto() {
		return this->peso * this->costoKilo;
	}
};
class Fragil : Paquete {
private:
	string nivelFragilidad;
public:
	Fragil(string codPaquete, string descripcion, float peso, float costoKilo, string nivelFragilidad)
		:Paquete(codPaquete, descripcion, peso, costoKilo, "FRAGIL") {
		this->nivelFragilidad = nivelFragilidad;

	}
	float calcularCosto() override{
		float costoBase = this->peso * this->costoKilo;
		float costoEmbalaje = 0;
		if (nivelFragilidad == "BAJO") {
			costoEmbalaje = 5;
		}
		else if(nivelFragilidad== "MEDIO") {
			costoEmbalaje = 10;
		}
		else if (nivelFragilidad == "ALTO") {
			costoEmbalaje = 20;
		}
		return costoBase + costoEmbalaje;
	}
};

class Expres : Paquete {
private:
	int horasEntrega;
public:
	Expres(string codPaquete, string descripcion, float peso, float costoKilo, int horasEntrega)
		:Paquete(codPaquete, descripcion, peso, costoKilo, "FRAGIL") {
		this->horasEntrega = horasEntrega;

	}
	float calcularCosto() override {
		float costoBase = this->peso * this->costoKilo;
		float costoPrioridad = 0;
		if (horasEntrega <224) {
			costoPrioridad = 30;
		}
		else if (horasEntrega <= 48) {
			costoPrioridad = 20;
		}
		else if (horasEntrega>48) {
			costoPrioridad = 10;
		}
		return costoBase + costoPrioridad;
	}
};