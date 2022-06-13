#include "cEquipo.h"
#include "cCorrectivo.h"
#include "cPreventivo.h"



cEquipo::cEquipo(int altura, int peso, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda, int costoP, int costoC)
{
	/*Preventivo = new cPreventivo(this);
	Correctivo = new cCorrectivo(this);*/
	this->Altura = altura;
	this->Peso = peso;
	this->Codigo = codigo;
	this->Descripcion = descripcion;
	this->Estado = en_uso;
	this->NecesitaCorrectivo = false;
	this->FechasMant = FechasMant;   //podemos hacer que estas las haga el constructor de cada tipo de equipo asi quedan fijas
	this->LugarGuarda = lugarGuarda;
	this->LugarAct = sala_mantenimiento;
	Preventivo = new cPreventivo(costoP);
	Correctivo = new cCorrectivo(costoC);
}

cEquipo::~cEquipo()
{
	delete this->Correctivo;
	delete this->Preventivo;
}

void cEquipo::RealizarMantCorrectivo()
{
	this->Correctivo->RealizarMantenimiento(this);
}

void cEquipo::setNecesitaCorrectivo(bool a)
{
	this->NecesitaCorrectivo = a;
}

int cEquipo::CantEquipos = 0;