#include "cElectro.h"

cElectro::cElectro(int altura, int peso, float error, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda):cEquipo(altura, peso, error,codigo, descripcion, fechaMant, lugarGuarda, 50, 80)
{
	this->Enchufado = false;
	this->Derivaciones = false;
	this->Traficacion = false;

}

cElectro::~cElectro()
{
}

int cElectro::Funcionar()
{
	int a = rand();
	if (a < this->getError())     //si falla
		throw new exception("No se pueden visualizar las traficaciones");
	return 0;
}

istream& operator>>(istream& in, cElectro& electro)
{
	cEquipo* aux = dynamic_cast<cEquipo*>(&electro);
	in >> *aux;
	return in;
}
