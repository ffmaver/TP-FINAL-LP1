#pragma once
#include "cMantenimiento.h"

using namespace std;


class cCorrectivo :
    private cMantenimiento
{

public:
    cCorrectivo();
    ~cCorrectivo();
    void RealizarMantenimiento(int plata);

};

