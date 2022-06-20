#pragma once
#include "cEquipo.h"
#define FLUJO_FIJADO 20

using namespace std;

enum frecuencia{Alta, Baja, Normal};
enum suenio{despertando, dormidisimo, dormido};

class cMesa :
    public cEquipo
{
    friend class cPreventivo;
    const int FlujoConfig;
    int Flujo;           //al crear el objeto, va a estar en 0
    bool AlarmaFrecuencia;       //al crearlo estara en false
    bool AlarmaSuenio;           //idem
    frecuencia  Frecuencia;
    suenio Suenio;
    
public:                         
    cMesa(int altura, int peso, float error, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda);
    ~cMesa();
    int Funcionar(int flujo);
    void setFrecuencia(frecuencia Frecuencia);
    void setSuenio(suenio Suenio);
    friend ostream& operator<<(ostream& out, cMesa& mesa);
    friend istream& operator>>(istream& in, cMesa& mesa);
};

