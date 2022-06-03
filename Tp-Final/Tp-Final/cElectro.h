#pragma once
#include "cEquipo.h"

using namespace std;



class cElectro :
    public cEquipo
{
    bool Enchufado;  //por defecto false
    bool Derivaciones;
    bool Traficacion;
public:
    cElectro( int altura, int peso, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda);
    ~cElectro();
    void RealizarMantPreventivo();
    void RealizarVisualizacion();
};

