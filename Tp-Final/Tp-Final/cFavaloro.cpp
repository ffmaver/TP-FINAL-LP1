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

void cFavaloro::DondeEstanLosEquipos()
{
	for (int i = 0; i < this->ListaEquipos->getCant(); i++) {
		try {
			(*(this->ListaEquipos))[i]->ChequearLugar();
		}
		catch (exception e) {
			cout << "El equipo " << (*(this->ListaEquipos))[i]->getCodigo() <<" no esta en su lugar"<< endl;
			cout << e.what() << endl;
		}
	}
}
