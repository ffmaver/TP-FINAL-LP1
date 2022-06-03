#pragma once
#include "cMantenimiento.h"

using namespace std;


class cCorrectivo :
    public cMantenimiento
{

public:

    // Deberia recibir un cEquipo por parametro, y a partir de un dynamic cast 
    // Tendrian que setear el precio del Mantenimiento. Hacer lo mismo para Preventivo
    cCorrectivo(int costo);
    ~cCorrectivo();
    void RealizarMantenimiento(int plata);

};

