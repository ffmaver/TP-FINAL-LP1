#pragma once
#include "cEquipo.h"
class cMesa :
    private cEquipo
{
    int FlujoFijado;
    int FlujoPaciente;
    bool AlarmaFrecuencia;
    bool AlarmaSuenio;
public:
    cMesa();
    ~cMesa();
    void RealizarMantPreventivo();
};

