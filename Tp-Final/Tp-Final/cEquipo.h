#pragma once
#include <string>
#include <string.h>

enum estado{/*blabla estado nose que va aca*/};
class cEquipo
{
	int altura;
	int peso;
	string codigo;
	string descripcion;
	estado Estado;
	string LugarAct;
	string LugarGuarda;
	int CostoMantenimiento;
	bool NecesitaCorrectivo;
public:
	cEquipo();
	virtual ~cEquipo();
	void virtual RealizarMantPreventivo();
	void ChequearLugar();
	void RealizarMantCorrectivo();

};

