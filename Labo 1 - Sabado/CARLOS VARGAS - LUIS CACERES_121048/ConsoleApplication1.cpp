
#include<iostream>
#include<string>
#include"Cliente.h"
#include"Envio.h"
#include"Exception.h"
#include"ClienteDuplicadoException.h"
#include"ListaGenerica.h"
#include"SistemaEnvios.h"
using namespace std;

int main(){
	SistemaEnvios* sis1 = new SistemaEnvios("E1", 10,10);
	//1
	sis1->registrarCliente(new Cliente("123", "Luis", "12345678", "Av.Abra"));
	sis1->registrarCliente(new Cliente("234", "Juan", "23456789", "Av.America"));
	//Exception
	sis1->registrarCliente(new Cliente("123", "Ana", "11111111", "Av.Aroma"));
	//2
	sis1->registrarEnvio(new Envio("13", "12-12-29", 25, new Cliente("445566", "Luis", "12345678", "Av.Abra")));
	sis1->registrarEnvio(new Envio("12", "12-12-27",25,new Cliente("7785783", "Messi", "12345678", "Av.Petrolera")));
	//exception 
	sis1->registrarEnvio(new Envio("13", "12-12-29", 25, new Cliente("445566", "Luis", "12345678", "Av.Abra")));

}
