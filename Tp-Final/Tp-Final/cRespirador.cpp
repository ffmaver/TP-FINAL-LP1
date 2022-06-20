#include "cRespirador.h"

cRespirador::cRespirador(int altura, int peso, float error ,string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda):FlujoConfigSalida(FLUJO_CONFIG), cEquipo(altura, peso,error, codigo, descripcion, fechaMant, LugarGuarda, 50, 80)
{
	this->AlarmaPresion = false;
	this->AlarmaFlujoCero = false;
	this->FlujoSalida = 0;
	this->PresionPaciente = sano;

}

cRespirador::~cRespirador()
{
}

int cRespirador::Funcionar(int flujo)
{
	this->FlujoSalida = flujo;
	if (this->FlujoSalida == 0)  //si el flujo es 0, activamos la alarma de flujo 0
	{
		int a = rand();
		if(a<this->getError())  
			this->AlarmaFlujoCero = false;  //pusimos un rand para que no todas las veces ande bien el equipo
		else
			this->AlarmaFlujoCero = true;  //si a es mayor al error, va a andar bien (si error fuera 0, va a andar siempre bien)

	}
		

	if (this->PresionPaciente == baja || this->PresionPaciente == alta)  //si la presion del paciente es alta o baja, activamos la alarma de presion
	{
		int a = rand();
		if (a < this->getError())
			this->AlarmaPresion = false;  //pusimos un rand para que no todas las veces ande bien el equipo
		else
			this->AlarmaPresion = true;  //si a es mayor al error, va a andar bien (si error fuera 0, va a andar siempre bien)

	}
	else this->AlarmaPresion = false;

	if (this->getError() == 0)
		return this->FlujoConfigSalida;   //si no tiene error, siempre devuelve el flujo configurado
	else
		return this->FlujoSalida;
}

void cRespirador::setPresionPaciente(presion presionPaciente)
{
	this->PresionPaciente = presionPaciente;
}

istream& operator>>(istream& in, cRespirador& respirador)
{
	cEquipo* aux = dynamic_cast<cEquipo*>(&respirador);
	in >> *aux;
	return in;
}
