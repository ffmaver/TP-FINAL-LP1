#pragma once
#include "cMantenimiento.h"
#include "cEquipo.h"

class cPreventivo :
    private cMantenimiento
{
public:
    cPreventivo();
    ~cPreventivo();
    void ControlarAlarmaPresion();
    void ControlarAlarmaFlujo();
    void ProbarVisualizacion();
    void ProbarModos();
    void ControlVolumen();
    void ControlAlarma();
    void RealizarMantenimiento(cEquipo* equipo);
};

