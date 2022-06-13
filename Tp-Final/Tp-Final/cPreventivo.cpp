#include "cPreventivo.h"

cPreventivo::cPreventivo(int costo):cMantenimiento(costo)
{
}

cPreventivo::~cPreventivo()
{
}

void cPreventivo::RealizarMantenimiento(cEquipo* equipo)
{
}

ostream& operator<<(ostream& out, cPreventivo& prev)
{
    out << "Mantenimiento Preventivo" << endl;
    cMantenimiento* aux = dynamic_cast<cMantenimiento*>(&prev);
    out << *aux;
    return out;
}
