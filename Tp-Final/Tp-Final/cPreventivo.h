#pragma once
#include "cMantenimiento.h"
#include "cEquipo.h"

using namespace std;

class cPreventivo :
    public cMantenimiento
{
public:
    cPreventivo(int costo);
    ~cPreventivo();
    void ControlarAlarmaPresion();
    void ControlarAlarmaFlujo();
    void ProbarVisualizacion();
    void ProbarModos();
    void ControlVolumen();
    void ControlAlarma();
    void RealizarMantenimiento(cEquipo* equipo);
    friend ostream& operator<<(ostream& out, cPreventivo& prev);

};

