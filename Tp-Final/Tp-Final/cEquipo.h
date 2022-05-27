#pragma once
#include <iostream>
#include <string>
#include <string.h>


using namespace std;
enum estado{en_uso, en_espera, fuera_de_servicio, en_mantenimiento};
enum lugar{almacenamiento, sala_mantenimiento, cardiologia, habitacion, sala_operaciones};
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
	
	int CostoMantenimiento;
	bool NecesitaCorrectivo;  //por defecto en false
	cFecha** FechasMant;
protected:
	lugar LugarAct;   //podriamos hacer un enum de posibles lugares para que no sea tan insoportable
	lugar LugarGuarda;  
public:
	cEquipo(int altura, int peso, string codigo, string descripcion, estado estado,	int costoMantenimiento, cFecha** fechaMant, lugar lugarAct, lugar lugarGuarda);
	virtual ~cEquipo();
	void virtual RealizarMantPreventivo();
	void ChequearLugar();
	void RealizarMantCorrectivo();
	void setNecesitaCorrectivo(bool);
};

