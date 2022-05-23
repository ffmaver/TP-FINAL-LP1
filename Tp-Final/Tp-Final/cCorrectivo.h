#pragma once
#include "cMantenimiento.h"
class cCorrectivo :
    private cMantenimiento
{

public:
    cCorrectivo();
    ~cCorrectivo();
    void RealizarMantenimiento(int plata);

};

