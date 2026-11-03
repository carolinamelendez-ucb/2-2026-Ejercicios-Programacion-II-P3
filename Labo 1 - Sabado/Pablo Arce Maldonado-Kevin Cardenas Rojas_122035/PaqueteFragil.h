#pragma once
#include <iostream>
#include <string>
#include "PaqueteNormal.h"

using namespace std;


class PaqueteFragil:public PaqueteNormal {
protected:
	string nivelFragilidad;
	float costoEmbalaje;
public:
	PaqueteFragil(string nivelFragilidad, float costoEmbalaje):PaqueteNormal(codigoPaquete,descripcion, peso,costoPorKg) {
		this->nivelFragilidad = nivelFragilidad;
		this->costoEmbalaje = costoEmbalaje;
		this->codigoPaquete = codigoPaquete;
		this->descripcion = descripcion;
		this->peso = peso;
		this->costoPorKg = costoPorKg;
	}

	string getNivelFragilidad()
	{
		return this->nivelFragilidad;
	}


	float Costo() override
	{
		if (this->getNivelFragilidad() == "Bajo")
		{
			this->costoEmbalaje = 5 * this->peso * this->costoPorKg;
			return costoEmbalaje;
		}

		  else
		  {
			if (this->getNivelFragilidad() == "Medio")
			{
				this->costoEmbalaje = 10 * this->peso * this->costoPorKg;
				return costoEmbalaje;
			}
			else
			{
				if (this->getNivelFragilidad() == "Alto")
				{
					this->costoEmbalaje = 20 * this->peso * this->costoPorKg;
					return costoEmbalaje;

				}
				else
				{
					return 0.0;
				}
			}


		  }
		
          

    }

	






};