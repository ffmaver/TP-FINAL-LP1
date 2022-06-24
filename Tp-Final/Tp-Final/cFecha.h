#pragma once
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

class cFecha
{
	tm fecha;

public:
	cFecha();//Constructor por default, inicia en la fecha de hoy
	cFecha(int d, int m, int a);//Constructor inicia en dia, mes, a�o
	cFecha(int dia, int mes, int anio, int hora, int minutos);
	~cFecha();

	void SetHoy();//Cambia la fecha a la fecha actual
	bool FechaCompleta();//Verifica que la fecha est� completa //era bool en el tp3
	void SiguienteDia();

	int getDia();
	int getMes();

	bool FinaldeMes();

	bool operator ==(cFecha* fecha1);
	bool operator !=(cFecha* fecha1);
	friend ostream& operator<<(ostream& out, cFecha& fecha);


};

