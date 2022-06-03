#pragma once
#include <iostream>
#include "cLista.h"
#include "cEquipo.h"
#define MAXEQUIPOS 40

using namespace std;

typedef cLista<cEquipo> cListaEquipo;

class cFavaloro
{
	int CuentaCorriente;
	cListaEquipo* ListaEquipos; // Equipos en uso
	cListaEquipo* ListaPreventivo; // Equipos en mantenimiento preventivo
	cListaEquipo* ListaCorrectivo; // Equipos en mantenimiento correctivo

public:
	cFavaloro(int cuenta);
	~cFavaloro();

	/// <summary>
	/// Se elige un equipo de forma aleatoria dentro de la lista
	/// cListaEquipos
	/// </summary>
	void ElegirEquipo();


	void DondeEstanLosEquipos();
	
	void ImprimirMantenimientos();
	
	void RealizarMantCorrectivo();

};
