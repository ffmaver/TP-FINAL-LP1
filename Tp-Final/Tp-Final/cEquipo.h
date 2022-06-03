#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "cLista.h"


using namespace std;
enum estado{en_uso, en_espera, fuera_de_servicio, en_mantenimiento};
enum lugar{almacenamiento, sala_mantenimiento, cardiologia, habitacion, sala_operaciones};
class cMantenimiento;
class cFecha; 

//hacer lista template con fecha
typedef cLista<cFecha>cListaFechas;

class cEquipo
{
	int Altura;
	int Peso;
	string Codigo;
	string Descripcion;
	estado Estado;          //por defecto en_uso
	int CostoMantenimiento;   
	bool NecesitaCorrectivo;  //por defecto en false
	cListaFechas* FechasMant;
	cPreventivo* Preventivo;
	cCorrectivo* Correctivo;

protected:
	lugar LugarAct;   //por defecto en almacenamiento
	lugar LugarGuarda;  

public:
	cEquipo(int altura, int peso, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda);
	virtual ~cEquipo();
	void virtual RealizarMantPreventivo();
	void ChequearLugar();
	void RealizarMantCorrectivo();
	void setNecesitaCorrectivo(bool patito);
};

