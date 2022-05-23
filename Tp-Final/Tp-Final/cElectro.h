#pragma once
#include "cEquipo.h"
class cElectro :
    private cEquipo
{
    bool Enchufado;
    //derivacione Derivaciones;
    //modos Traficacion;
public:
    cElectro();
    ~cElectro();
    void RealizarMantPreventivo();
    void RealizarVisualizacion();
};

