#include "cRespirador.h"

cRespirador::cRespirador(int altura, int peso, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda):FlujoConfigSalida(FLUJO_CONFIG), cEquipo(altura, peso, codigo, descripcion, fechaMant, LugarGuarda, 50, 80)
{
	this->AlarmaPresion = false;
	this->AlarmaFlujoCero = false;
	this->FlujoSalida = 0;
	this->PresionPaciente = sano;

}

cRespirador::~cRespirador()
{
}

void cRespirador::setPresionPaciente(presion presionPaciente)
{
	this->PresionPaciente = presionPaciente;
}
