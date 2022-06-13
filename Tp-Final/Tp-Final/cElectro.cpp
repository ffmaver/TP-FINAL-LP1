#include "cElectro.h"

cElectro::cElectro(int altura, int peso, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda):cEquipo(altura, peso, codigo, descripcion, fechaMant, LugarGuarda, 50, 80)
{
	this->Enchufado = false;
	this->Derivaciones = false;
	this->Traficacion = false;

}
