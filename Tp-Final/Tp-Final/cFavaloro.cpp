#include "cFavaloro.h"
#include "cMantenimiento.h"
#include "cPreventivo.h"
#include "cCorrectivo.h"

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

void cFavaloro::ElegirEquipo()
{
	int a = rand() % (this->ListaEquipos->getCant());
	try {
		(*(this->ListaEquipos))[a]->ChequearLugar();
	}
	catch (exception *e) {
		cout << "El equipo " << (*(this->ListaEquipos))[a]->Codigo << " no esta en su lugar" << endl;
	}

}

void cFavaloro::LlenarListasMantenimientos(cFecha* hoy)
{

	for(int k=0;k< this->ListaEquipos->getCant(); k++)
		for (int i = 0; i < (*(this->ListaEquipos))[k]->FechasMant->getCant(); i++) {
			if ((*((*(this->ListaEquipos))[k]->FechasMant))[i] == hoy) {
				(*(this->ListaPreventivo)) + (*(this->ListaEquipos))[k]; //si la fecha de hoy coincide con alguna de las fechas en las que 
				(*(this->ListaEquipos))[k]->RealizarMantPreventivo();   //este equipo debe tener mant prev, lo agrego a la lista de mant prev
			}															//y le realizamos dicho mantenimiento
		}															
		

	for (int i = 0; i < this->ListaEquipos->getCant(); i++) {        //recorro la lista de equipos para ver cual necesita mant correctivo
		if ((*(this->ListaEquipos))[i]->NecesitaCorrectivo)
			(*(this->ListaCorrectivo)) + (*(this->ListaEquipos))[i];
	}
	


}

void cFavaloro::DondeEstanLosEquipos()
{
	for (int i = 0; i < this->ListaEquipos->getCant(); i++) {
		try {
			(*(this->ListaEquipos))[i]->ChequearLugar();
		}
		catch (exception *e) {
			cout << "El equipo " << (*(this->ListaEquipos))[i]->getCodigo() <<" no esta en su lugar"<< endl;
			cout << e->what() << endl;
		}
	}
}

void cFavaloro::ImprimirMantenimientos()
{
	int costoPreventivos = 0, costoCorrectivos = 0;

	for (int i = 0; i < this->ListaPreventivo->getCant(); i++) {
		costoPreventivos += (*(this->ListaPreventivo))[i]->Preventivo->getCosto();
		cout << "Mantenimientos Preventivos de hoy" << endl; //podiamos aclarar la fecha pero es un caos
		cout << (*(this->ListaPreventivo))[i] << (*(this->ListaPreventivo))[i]->Preventivo << endl;

	}

	cout << "Costo total de los preventivos: " << to_string(costoPreventivos) << endl;

	for (int i = 0; i < this->ListaCorrectivo->getCant(); i++) {
		costoCorrectivos += (*(this->ListaCorrectivo))[i]->Correctivo->getCosto();
		cout << "Mantenimientos correctivos pendientes" << endl; 
		cout << (*(this->ListaCorrectivo))[i] << (*(this->ListaCorrectivo))[i]->Correctivo << endl;
		
	}

	cout << "Costo total de los correctivos: " << to_string(costoCorrectivos) << endl;


	if (this->ListaCorrectivo->getCant() > 4 && costoCorrectivos>2000) {   //Si el costo total es menor a U$D2.000 o la cantidad de equipos es
		this->RealizarMantCorrectivo(costoCorrectivos);					   //menor que 5 se desestima.De no ser así, se realizan las reparaciones
	}
}

void cFavaloro::RealizarMantCorrectivo(int costo)
{
	this->CuentaCorriente -= costo;   //se paga
	for (int i = 0; i < this->ListaCorrectivo->getCant(); i++) {
		(*(this->ListaCorrectivo))[i]->RealizarMantCorrectivo();   //se realizan los mantenimientos

	}
}

void cFavaloro::operator+(cEquipo* nuevo_equipo)
{
	(*(this->ListaEquipos)) + nuevo_equipo;

}
