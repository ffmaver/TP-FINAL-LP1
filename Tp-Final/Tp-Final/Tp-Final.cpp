#include <iostream>
#include "cFecha.h"
#include "cRespirador.h"
#include "cElectro.h"
#include "cMesa.h"
#include "cCorrectivo.h"
#include "cPreventivo.h"
#include "cFavaloro.h"

#define MAX_FECHAS 12

using namespace std;

int main()
{
	cFavaloro* Favaloro = new cFavaloro(23456789);

	cFecha* Dia1 = new cFecha(1, 1, 2022);
	cFecha* Dia2 = new cFecha(12, 2, 2022);
	cFecha* Dia3 = new cFecha(9, 3, 2022);
	cFecha* Dia4 = new cFecha(3, 4, 2022);
	cFecha* Dia5 = new cFecha(12, 5, 2022);
	cFecha* Dia6 = new cFecha(2, 6, 2022);
	cFecha* Dia7 = new cFecha(24, 7, 2022);
	cFecha* Dia8 = new cFecha(9, 8, 2022);
	cFecha* Dia9 = new cFecha(3, 9, 2022);
	cFecha* Dia10 = new cFecha(12, 10, 2022);
	cFecha* Dia11 = new cFecha(2, 11, 2022);
	cFecha* Dia12 = new cFecha(24, 12, 2022);

	cListaFechas* Calendario1 = new cListaFechas(MAX_FECHAS);
	cListaFechas* Calendario2 = new cListaFechas(MAX_FECHAS);
	cListaFechas* Calendario3 = new cListaFechas(MAX_FECHAS);

	Calendario1->Agregar(Dia1);     //usamos un calendario para cada tipo de equipo
	Calendario1->Agregar(Dia6);		//calendario 1 para las mesas de anestesia
	Calendario1->Agregar(Dia12);

	Calendario2->Agregar(Dia2);		//para los electro
	Calendario2->Agregar(Dia4);
	Calendario2->Agregar(Dia6);
	Calendario2->Agregar(Dia8);

	Calendario3->Agregar(Dia3);		//para los respiradores
	Calendario3->Agregar(Dia6);
	Calendario3->Agregar(Dia9);

	cPreventivo* MantPrevElectro = new cPreventivo(100);
	cPreventivo* MantPrevMesas = new cPreventivo(90);
	cPreventivo* MantPrevRespiradores = new cPreventivo(110);

	cCorrectivo* MantCorrectElectro = new cCorrectivo(800);
	cCorrectivo* MantCorrectMesas = new cCorrectivo(1000);
	cCorrectivo* MantCorrectRespirador = new cCorrectivo(1200);




	cRespirador* respirador1 = new cRespirador(MantPrevRespiradores, MantCorrectRespirador, 20, 34, "Respirator2000", "es un respirador flaco", Calendario3, habitacion);
	cRespirador* respirador2 = new cRespirador(MantPrevRespiradores, MantCorrectRespirador, 20, 34, "Respirator2001", "es un respirador flaco", Calendario3, habitacion);
	cRespirador* respirador3 = new cRespirador(MantPrevRespiradores, MantCorrectRespirador, 20, 34, "Respirator2002", "es un respirador flaco", Calendario3, habitacion);

	cElectro* electro1 = new cElectro(MantPrevElectro, MantCorrectElectro, 40, 50, "electro1", "es un electro flaco", Calendario3, cardiologia);
	cElectro* electro2 = new cElectro(MantPrevElectro, MantCorrectElectro, 40, 50, "electro2", "es un electro flaco", Calendario3, cardiologia);
	cElectro* electro3 = new cElectro(MantPrevElectro, MantCorrectElectro, 40, 50, "electro3", "es un electro flaco", Calendario3, cardiologia);

	cMesa* Mesa1 = new cMesa(MantPrevRespiradores, MantCorrectRespirador, 30, 76, "Mesa1", "es una mesa flaco", Calendario3, sala_operaciones);
	cMesa* Mesa2 = new cMesa(MantPrevRespiradores, MantCorrectRespirador, 30, 76, "Mesa2", "es una mesa flaco", Calendario3, sala_operaciones);


	/*
	NUESTRA IDEA: en RealizarMantPreventivo se chequea que la fecha actual corresponda con alguna de las fechas del calendario,
	si no coincide, lanza una excepcion que diga algo asi como "Hoy no se debe realizar el mant preventivo de este equipo"

	Si coincide, se realiza el mantenimiento preventivo que corresponde y si este encuentra una falla, cambia el estado del equipo a
	fuera de servicio

	cuando favaloro haga los mant correctivos, todos los equipos que esten en estado fuera de servicio seran reparados

	*/

	try {
		respirador1->RealizarMantPreventivo();
	}
	catch (exception e) {
		cout << string(e.what());
	}
	try {
		respirador2->RealizarMantPreventivo();
	}
	catch (exception e) {
		cout << string(e.what());
	}
	try {
		respirador3->RealizarMantPreventivo();
	}
	catch (exception e) {
		cout << string(e.what());
	}



	Favaloro->DondeEstanLosEquipos();  //imprime donde esta cada equipo y senala cual esta fuera de lugar
	Favaloro->RealizarMantCorrectivo();


	delete Mesa2;
	delete Mesa1;

	delete electro3;
	delete electro2;
	delete electro1;

	delete respirador3;
	delete respirador2;
	delete respirador1;

	delete MantCorrectRespirador;
	delete MantCorrectMesas;
	delete MantCorrectElectro;

	delete MantPrevRespiradores;
	delete MantPrevMesas;
	delete MantPrevElectro;

	delete Calendario3;
	delete Calendario2;
	delete Calendario1;

	delete Dia12;
	delete Dia11;
	delete Dia10;
	delete Dia9;
	delete Dia8;
	delete Dia7;
	delete Dia6;
	delete Dia5;
	delete Dia4;
	delete Dia3;
	delete Dia2;
	delete Dia1;

	delete Favaloro;

}