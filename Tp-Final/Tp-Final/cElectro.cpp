#include "cElectro.h"

cElectro::cElectro(int altura, int peso, float error, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda):cEquipo(altura, peso, error,codigo, descripcion, fechaMant, LugarGuarda, 50, 80)
{
	this->Enchufado = false;
	this->Derivaciones = false;
	this->Traficacion = false;

}

int cElectro::Funcionar()
{

	return 0;
}

istream& operator>>(istream& in, cElectro& electro)
{
	cEquipo* aux = dynamic_cast<cEquipo*>(&electro);
	in >> *aux;
	return in;
}
