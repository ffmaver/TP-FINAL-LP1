#pragma once
#include "cEquipo.h"

using namespace std;

class cMesa :
    private cEquipo
{
    int FlujoFijado;
    int FlujoPaciente;           //al crear el objeto, va a estar en 0
    bool AlarmaFrecuencia;       //al crearlo estara en false
    bool AlarmaSuenio;           //idem
public:                         
    cMesa(int flujoFijado, int altura, int peso, string codigo, string descripcion, estado eestado, string lugarAct, string lugarGuarda, int costoMantenimiento, cFecha** fechasMant);
    ~cMesa();
    void RealizarMantPreventivo();
};

