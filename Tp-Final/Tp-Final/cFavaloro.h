#pragma once
#include <iostream>

using namespace std;

class cFavaloro
{
	int CuentaCorriente;

public:
	cFavaloro(int cuenta);
	~cFavaloro();
	void ElegirEquipo();
	void DondeEstanLosEquipos();
	void ImprimirMantenimientos();
	void RealizarMantCorrectivo();

};
