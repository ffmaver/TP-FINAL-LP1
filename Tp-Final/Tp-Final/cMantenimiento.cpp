#include "cMantenimiento.h"

cMantenimiento::cMantenimiento(int costo)
{
	this->Costo = costo;
}

cMantenimiento::~cMantenimiento()
{
}

ostream& operator<<(ostream& out, cMantenimiento& mant)
{
	out << "Costo del mantenimiento: " << to_string(mant.Costo) << endl;
	return out;
}
