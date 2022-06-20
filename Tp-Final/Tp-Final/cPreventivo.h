#pragma once
#include "cMantenimiento.h"
#include "cEquipo.h"

using namespace std;

class cRespirador;
class cMesa;
class cElectro;

class cPreventivo :
    public cMantenimiento
{
public:
    cPreventivo(int costo);
    ~cPreventivo();
    void ControlarAlarmaPresion(cRespirador* respirador);
    void ControlarAlarmaFlujo(cRespirador* respirador);
    void ControlarAlarmaSuenio(cMesa* mesa);
    void ControlarAlarmaFrecuencia(cMesa* mesa);
    void RealizarMantenimiento(cEquipo* equipo);
    friend ostream& operator<<(ostream& out, cPreventivo& prev);

};

