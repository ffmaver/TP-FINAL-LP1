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

void cEquipo::RealizarMantPreventivo()
{
	this->Preventivo->RealizarMantenimiento(this);
}

void cEquipo::ChequearLugar()
{
	if (this->LugarGuarda != this->LugarAct)
		throw new exception("El equipo no se encuentra en su lugar");

}

void cEquipo::ImprimirLugarAct()
{
	cout << "El equipo esta ";
	switch (LugarAct) {
	case almacenamiento:
		cout << "en el almacenamiento" << endl;
		break;
	case sala_mantenimiento:
		cout << "en la sala de mantenimiento" << endl;
		break;
	case cardiologia:
		cout << " en cardiologia" << endl;
		break;
	case habitacion:
		cout << "en una habitacion" << endl;
		break;
	case sala_operaciones:
		cout << "en la sala de operaciones" << endl;
		break;
	}
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

ostream& operator<<(ostream& out, cEquipo& equipo)
{
	out << "Equipo: " << equipo.Codigo << endl;
	return out;
	// TODO: insert return statement here
}

istream& operator>>(istream& in, cEquipo& eq)
{
	string aux;
	in >> aux;
	eq.Descripcion = aux;  //setea una nueva descripcion ingresada en el cin
	return in;
	// TODO: insert return statement here
}
