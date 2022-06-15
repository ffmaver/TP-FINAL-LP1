#include "cMantenimiento.h"

cMantenimiento::cMantenimiento(int costo)
{
	this->Costo = costo;
}

cMantenimiento::~cMantenimiento()
{
}

int cMantenimiento::getCosto()
{
	return this->Costo;
}

ostream& operator<<(ostream& out, cMantenimiento& mant)
{
	out << "Costo del mantenimiento: " << to_string(mant.Costo) << endl;
	return out;
}
