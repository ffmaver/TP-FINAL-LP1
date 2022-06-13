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
class cPreventivo;
class cCorrectivo;



//hacer lista template con fecha
typedef cLista<cFecha>cListaFechas;

class cEquipo
{
	static int CantEquipos; //por defecto, empieza en cero y cada vez que creamos uno, suma uno
	int Altura;
	int Peso;
	string Codigo;
	string Descripcion;
	estado Estado;          //por defecto en_uso
	//int CostoMantenimiento;   
	bool NecesitaCorrectivo;  //por defecto en false
	cListaFechas* FechasMant;
	cPreventivo* Preventivo;
	cCorrectivo* Correctivo;  //podemos ver que el costo varie segun que tan hecho percha esta el equipo

protected:
	lugar LugarAct;   //por defecto en almacenamiento
	lugar LugarGuarda;  

public:
	cEquipo(int altura, int peso, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda, int costoP, int costoC);
	virtual ~cEquipo();
	void RealizarMantPreventivo();
	void ChequearLugar();
	void ImprimirLugarAct();
	void RealizarMantCorrectivo();
	void setNecesitaCorrectivo(bool a);
	friend istream& operator>>(istream& in, cEquipo& eq);
	string getCodigo();
};

