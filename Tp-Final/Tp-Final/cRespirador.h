#pragma once
#include "cEquipo.h"

using namespace std;
enum presion{baja, alta, sano};

class cRespirador :
    public cEquipo
{
    const int FlujoConfigSalida; // const
    presion AlarmaPresion;    //al crear el objeto, va a estar en sano
    bool AlarmaFlujoCero;     //al crearlo estara en false
    int FlujoSalida;        //al crear va a estar en 0
    presion PresionPaciente;  //idem
  
public:
    cRespirador(int altura, int peso, string codigo, string descripcion, cListaFechas* fechaMant, lugar lugarGuarda);
    ~cRespirador();
    void RealizarMantPreventivo();  //llama a Realizar mantenimiento preventivo desde el atributo (no nos queda claro la parte del flujo)
    int Funcionar(int flujo);  //va a chequear el flujo y la presion del paciente y dar una alarma si corresponde      el mant prev va a llamar a esta funcion y despues ver que las alarmas "suenen" cuando corresponde
    void setPresionPaciente(presion presionPaciente);
};

