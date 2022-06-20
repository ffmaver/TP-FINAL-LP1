#include "cFecha.h"

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS


cFecha::cFecha() {
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = 0;
	fecha.tm_mon = 0;
	fecha.tm_year = 0;
	//if (next_mes) {
	// ibamos a hacer lo del mes pero al final fue opcional y no lo hicimos
	//}//setr rand
	SetHoy();

	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::cFecha(int d, int m, int a)
{
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m;
	fecha.tm_year = a - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::cFecha(int d, int m, int a, int hs, int min) {

	fecha.tm_hour = hs;
	fecha.tm_min = min;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m;
	fecha.tm_year = a - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::~cFecha() {
}
//
//int cFecha::HorasEntreFechas(cFecha* inicio, time_t aux_fin)
//{
//	int dif = 0;
//	time_t aux_inicio = mktime(&(inicio->fecha)); //paso las fechas a segundos
//	//time_t aux_fin = mktime(&(fin->fecha));
//	//if -1 falla la conversion
//	//verifico que las fechas que recibo no sean null ni estén incompletas
//	if ((inicio != NULL) && inicio->FechaCompleta())
//	{
//
//		dif = difftime(aux_fin, aux_inicio) / (3600); //calculo la diferencia de tiempo en segundos, transforma a horas, y la devuelvo
//		return dif;
//
//	}
//	else throw exception("Fechas incompletas");
//}

void cFecha::SetHoy()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha y hora actual
	fecha.tm_sec = aux->tm_sec;
	fecha.tm_min = aux->tm_min;
	fecha.tm_hour = aux->tm_hour;
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_year;
}
//
//void cFecha::setMesRand()
//{
//
//	time_t now = time(0);
//	tm* aux = localtime(&now); //obtengo fecha y hora actual
//	fecha.tm_sec = aux->tm_sec;
//	fecha.tm_min = aux->tm_min;
//	fecha.tm_hour = aux->tm_hour;
//	fecha.tm_mday = aux->tm_mday;
//	fecha.tm_mon = aux->tm_mon;
//	fecha.tm_year = aux->tm_year;
//
//	fecha.tm_mon++; //sumamos uno al mes para la consign QUE AL FINAL ERA OPCIONAL
//}

bool cFecha::FechaCompleta()
{
	if (fecha.tm_year != 0 && fecha.tm_mon != 0 && fecha.tm_mday != 0 && fecha.tm_hour >= 0 && fecha.tm_min >= 0 && fecha.tm_sec >= 0) //verifico que los parámetros de día no estén en sus valores nulos
		return true;
	return false;
}

void cFecha::SiguienteDia() 
{
	if (this->FinaldeMes()) {
		this->fecha.tm_mday = 1;
		this->fecha.tm_mon += 1;
	}
	else
		this->fecha.tm_mday += 1; //revisar que el cambio de mes funcione
}

int cFecha::getDia()
{
	return this->fecha.tm_mday;
}

int cFecha::getMes()
{
	return this->fecha.tm_mon;
}

bool cFecha::FinaldeMes()
{
	if ((this->fecha.tm_mon == 1 || this->fecha.tm_mon == 3 || this->fecha.tm_mon == 5 || this->fecha.tm_mon == 7 ||
		this->fecha.tm_mon == 8 || this->fecha.tm_mon == 10 || this->fecha.tm_mon == 12) && this->fecha.tm_mday == 31)
		return true;

	else if ((this->fecha.tm_mon == 4 || this->fecha.tm_mon == 6 || this->fecha.tm_mon == 9 || this->fecha.tm_mon == 11) && this->fecha.tm_mday == 30)
		return true;

	else if (this->fecha.tm_mon == 2 && this->fecha.tm_mday == 28)
		return true;
	else
		return false;
}

bool cFecha::operator==(cFecha* fecha1)
{
	if (this->fecha.tm_year == fecha1->fecha.tm_year && this->fecha.tm_mon == fecha1->fecha.tm_mon && this->fecha.tm_mday == fecha1->fecha.tm_mday)
		return true;
	return false;
}

bool cFecha::operator!=(cFecha* fecha1)
{
	if (this->fecha.tm_year == fecha1->fecha.tm_year && this->fecha.tm_mon == fecha1->fecha.tm_mon && this->fecha.tm_mday == fecha1->fecha.tm_mday)
		return false;
	return true;
}

//string cFecha::To_string()
//{
//	return to_string(fecha.tm_year + 1900) +
//		"/" + to_string(fecha.tm_mon + 1) +
//		"/" + to_string(fecha.tm_mday);
//}
//
//void cFecha::ImprimirFecha() {
//	cout << To_string() << endl;;
//}
//
//tm cFecha::getFecha()
//{
//	return this->fecha;
//}