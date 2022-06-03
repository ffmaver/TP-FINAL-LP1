#pragma once
#include <iostream>
#include "cLista.h"
#include "cEquipo.h"

using namespace std;

typedef cLista<cEquipo> cListaEquipo;

class cFavaloro
{
	int CuentaCorriente;
	cListaEquipo* cListaEquipos; // Equipos en uso
	cListaEquipo* cListaPreventivo; // Equipos en mantenimiento preventivo
	cListaEquipo* cListaCorrectivo; // Equipos en mantenimiento correctivo

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
