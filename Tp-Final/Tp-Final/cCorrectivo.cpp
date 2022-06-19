#include "cCorrectivo.h"
#include "cEquipo.h"

ostream& operator<<(ostream& out, cCorrectivo& correct)
{
    out << "Mantenimiento Correctivo" << endl;
    cMantenimiento* aux = dynamic_cast<cMantenimiento*>(&correct);
    out << *aux;
    return out;
}

cCorrectivo::cCorrectivo(int costo):cMantenimiento(costo)
{
}

cCorrectivo::~cCorrectivo()
{
}

void cCorrectivo::RealizarMantenimiento(cEquipo* equipo)
{
    equipo->setError(0);
    equipo->setNecesitaCorrectivo(false);
}
