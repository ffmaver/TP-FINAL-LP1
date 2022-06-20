#pragma once
#include "cEquipo.h"

using namespace std;



class cElectro :
    public cEquipo
{
    friend class cPreventivo;
    bool Enchufado;  //por defecto false
    bool Derivaciones;
    bool Traficacion;
public:
    cElectro( int altura, int peso, float error, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda);
    ~cElectro();
    int Funcionar();
    friend ostream& operator<<(ostream& out, cElectro& electro);
    friend istream& operator>>(istream& in, cElectro& electro);
};

