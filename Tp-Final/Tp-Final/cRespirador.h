#pragma once
#include "cEquipo.h"
enum presion{baja, alta};

class cRespirador :
    private cEquipo
{
    int FlujoConfig;
    presion AlarmaPresion;
    bool AlarmaFlujoCero;
    int FlujoPaciente;
    presion PresionPaciente;
public:
    cRespirador();
    ~cRespirador();
    void RealizarMantPreventivo(int flujo_salida);
};

