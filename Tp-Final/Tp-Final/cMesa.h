#pragma once
#include "cEquipo.h"
#define FLUJO_FIJADO 20

using namespace std;

class cMesa :
    public cEquipo
{
    friend class cPreventivo;
    const int FlujoFijado;
    int FlujoPaciente;           //al crear el objeto, va a estar en 0
    bool AlarmaFrecuencia;       //al crearlo estara en false
    bool AlarmaSuenio;           //idem

public:                         
    cMesa(int altura, int peso, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda);
    ~cMesa();
    //void RealizarMantPreventivo();
    friend ostream& operator<<(ostream& out, cMesa& mesa);
    friend istream& operator>>(istream& in, cMesa& mesa);
};

