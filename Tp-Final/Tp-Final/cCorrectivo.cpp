#include "cCorrectivo.h"

void cCorrectivo::RealizarMantenimiento(int plata)
{
}

ostream& operator<<(ostream& out, cCorrectivo& correct)
{
    out << "Mantenimiento Correctivo" << endl;
    cMantenimiento* aux = dynamic_cast<cMantenimiento*>(&correct);
    out << *aux;
    return out;
}
