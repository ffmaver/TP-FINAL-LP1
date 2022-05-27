#pragma once
#include "cEquipo.h"

using namespace std;

class cElectro :
    public cEquipo
{
    bool Enchufado;  //por defecto false
    //derivacione Derivaciones;
    //modos Traficacion;
public:
    cElectro(int altura, int peso, string codigo, string descripcion, estado estado, int costoMantenimiento, cFecha** fechaMant, lugar lugarAct, lugar lugarGuarda);
    ~cElectro();
    void RealizarMantPreventivo();
    void RealizarVisualizacion();
};

