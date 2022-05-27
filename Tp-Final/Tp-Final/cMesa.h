#pragma once
#include "cEquipo.h"

using namespace std;

class cMesa :
    public cEquipo
{
    int FlujoFijado;
    int FlujoPaciente;           //al crear el objeto, va a estar en 0
    bool AlarmaFrecuencia;       //al crearlo estara en false
    bool AlarmaSuenio;           //idem
public:                         
    cMesa(int flujoFijado, int altura, int peso, string codigo, string descripcion, estado estado, int costoMantenimiento, cFecha** fechaMant, lugar lugarAct, lugar lugarGuarda);
    ~cMesa();
    void RealizarMantPreventivo();
};

