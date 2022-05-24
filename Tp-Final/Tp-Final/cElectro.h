#pragma once
#include "cEquipo.h"

using namespace std;

class cElectro :
    private cEquipo
{
    bool Enchufado;  //por defecto false
    //derivacione Derivaciones;
    //modos Traficacion;
public:
    cElectro(int altura, int peso, string codigo, string descripcion, estado eestado, string lugarAct, string lugarGuarda, int costoMantenimiento, cFecha** fechasMant);
    ~cElectro();
    void RealizarMantPreventivo();
    void RealizarVisualizacion();
};

