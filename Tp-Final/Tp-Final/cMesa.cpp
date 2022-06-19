#include "cMesa.h"

cMesa::cMesa(int altura, int peso, float error, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda):  cEquipo(altura,peso,error,codigo,descripcion,fechaMant,LugarGuarda,50,100), FlujoFijado(FLUJO_FIJADO)
{
	this->FlujoPaciente = 0;
	this->AlarmaFrecuencia = false;
	this->AlarmaSuenio = false;
}

cMesa::~cMesa()
{
}

istream& operator>>(istream& in, cMesa& mesa)
{
	cEquipo* aux = dynamic_cast<cEquipo*>(&mesa);
	in >> *aux;
	return in;
}
