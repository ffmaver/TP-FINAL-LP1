#pragma once
#include <iostream>
#include <string>
#include <string.h>


using namespace std;
enum estado{/*blabla estado nose que va aca*/};
class cMantenimiento;
class cFecha; 

//hacer lista template con fecha

class cEquipo
{
	int Altura;
	int Peso;
	string Codigo;
	string Descripcion;
	estado Estado;
	string LugarAct;   //podriamos hacer un enum de posibles lugares para que no sea tan insoportable
	string LugarGuarda;
	int CostoMantenimiento;
	bool NecesitaCorrectivo;  //por defecto en false
	cFecha** FechasMant;
public:
	cEquipo();
	virtual ~cEquipo();
	void virtual RealizarMantPreventivo();
	void ChequearLugar();
	void RealizarMantCorrectivo();
	void setNecesitaCorrectivo(bool);
};

