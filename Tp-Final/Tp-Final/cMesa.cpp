#include "cMesa.h"

cMesa::cMesa(int altura, int peso, float error, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda):  cEquipo(altura,peso,error,codigo,descripcion,fechaMant,LugarGuarda,50,100), FlujoConfig(FLUJO_FIJADO)
{
	this->Flujo = 0;
	this->AlarmaFrecuencia = false;
	this->AlarmaSuenio = false;
	this->Frecuencia = Normal;
}

cMesa::~cMesa()
{
}

int cMesa::Funcionar(int flujo)
{
	this->Flujo= flujo;
	
	if (this->Frecuencia == Baja || this->Frecuencia == Alta)  //si la presion del paciente es alta o baja, activamos la alarma 
	{
		int a = rand();
		if (a < this->getError())
			this->AlarmaFrecuencia = false;  //pusimos un rand para que no todas las veces ande bien el equipo
		else
			this->AlarmaFrecuencia = true;  //si a es mayor al error, va a andar bien (si error fuera 0, va a andar siempre bien)

	}
	else this->AlarmaFrecuencia = false;

	if (this->Suenio == despertando)  //si la presion del paciente es alta o baja, activamos la alarma 
	{
		int a = rand();
		if (a < this->getError())
			this->AlarmaSuenio = false;  //pusimos un rand para que no todas las veces ande bien el equipo
		else
			this->AlarmaSuenio = true;  //si a es mayor al error, va a andar bien (si error fuera 0, va a andar siempre bien)

	}
	else this->AlarmaSuenio = false;

	if (this->getError() == 0)
		return this->FlujoConfig;   //si no tiene error, siempre devuelve el flujo configurado
	else
		return this->Flujo;

}

void cMesa::setFrecuencia(frecuencia Frecuencia)
{
	this->Frecuencia = Frecuencia;
}

void cMesa::setSuenio(suenio Suenio)
{
	this->Suenio = Suenio;
}

istream& operator>>(istream& in, cMesa& mesa)
{
	cEquipo* aux = dynamic_cast<cEquipo*>(&mesa);
	in >> *aux;
	return in;
}
