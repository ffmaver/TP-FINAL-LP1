#include "cEquipo.h"

cEquipo::cEquipo(int altura, int peso, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda)
{
	Preventivo = new cPreventivo(this);
	Correctivo = new cCorrectivo(this);
}
