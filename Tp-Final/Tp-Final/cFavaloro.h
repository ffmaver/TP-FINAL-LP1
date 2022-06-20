#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "cLista.h"
#include "cEquipo.h"
#define MAXEQUIPOS 40

using namespace std;

typedef cLista<cEquipo> cListaEquipo;

class cMantenimiento;
class cPreventivo;

class cFavaloro
{
	int CuentaCorriente;
	cListaEquipo* ListaEquipos; // Equipos en uso
	cListaEquipo* ListaPreventivo; // Equipos en mantenimiento preventivo por dia (cada dia ira cambiando esta lista)
	cListaEquipo* ListaCorrectivo; // Equipos en mantenimiento correctivo

public:
	cFavaloro(int cuenta);
	~cFavaloro();

	/// <summary>
	/// Se elige un equipo de forma aleatoria dentro de la lista y se lo verifica 
	/// (En la consigna no aclara si verificar es hacerle mant prev o imprimir en que lugar esta) ----- DUDA -----
	/// cListaEquipos
	/// </summary>
	void ElegirEquipo();

	/// <summary>
	/// Va recorriendo la lista de equipos que tiene favaloro y se fija cuales necesitan hoy mantenimiento preventivo,
	///  si es asi los agrega a la lista correspondiente y los manda a hacer su mantenimiento. Luego revisa cuales necesitan correctivo
	///  y si es asi los agrega a la lista correspondiente.
	/// </summary>
	/// <param name="hoy"></param>
	void LlenarListasMantenimientos(cFecha* hoy);

	/// <summary>
	/// Verifica la ubicacion de cada equipo, imprime en pantalla los que no estan en su lugar
	/// </summary>
	void DondeEstanLosEquipos();
	
	/// <summary>
	/// Al final del día, el sistema debe generar una lista con todos los mantenimientos preventivos hechos y su costo
	/// estimado.Además, una lista de todos los mantenimientos correctivos que se deban hacer o hayan quedado
	///	pendiente de días anteriores y su costo total.
	/// </summary>
	void ImprimirMantenimientos();
	

	/// <summary>
	/// Se realizan los mantenimientos correctivos y se paga con la cuenta corriente
	/// </summary>
	/// <param name="costo"></param>
	void RealizarMantCorrectivo(int costo);

	void operator+(cEquipo* nuevo_equipo);
};
