#pragma once
#include "cMantenimiento.h"

using namespace std;


class cCorrectivo :
    public cMantenimiento
{

public:
    cCorrectivo(int costo);
    ~cCorrectivo();
    void RealizarMantenimiento(int plata);

};

