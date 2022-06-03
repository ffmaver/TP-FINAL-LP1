#include "cFavaloro.h"

cFavaloro::cFavaloro(int cuenta)
{
	this->CuentaCorriente = cuenta;
	this->ListaCorrectivo = new cListaEquipo(MAXEQUIPOS);
	this->ListaEquipos =new cListaEquipo(MAXEQUIPOS);
	this->ListaPreventivo= new cListaEquipo(MAXEQUIPOS);

}

cFavaloro::~cFavaloro()
{
	delete ListaCorrectivo;
	delete ListaEquipos;
	delete ListaPreventivo;
}
