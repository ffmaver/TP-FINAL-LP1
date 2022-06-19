#include "cPreventivo.h"
#include "cEquipo.h"
#include "cElectro.h"
#include "cMesa.h"
#include "cRespirador.h"

cPreventivo::cPreventivo(int costo):cMantenimiento(costo)
{
}

cPreventivo::~cPreventivo()
{
}

void cPreventivo::RealizarMantenimiento(cEquipo* equipo)
{
    cRespirador* auxRespirador = dynamic_cast<cRespirador*>(equipo);
    cElectro* auxElectro = dynamic_cast<cElectro*>(equipo);
    cMesa* auxMesa = dynamic_cast<cMesa*>(equipo);


    if (auxRespirador != NULL) {  //si es un respirador
        for (int i = 0; i < 10; i++) {    //lo hago 10 veces para asegurarme de que no falle nunca
            try {
                this->ControlarAlarmaPresion();   //se controlan las alarmas, si alguna no funciona bien, salta una excepcion

            }
            catch (exception e) {
                cout << e.what();
                equipo->setNecesitaCorrectivo(true);  //este equipo necesita mantenimiento correctivo
                break;  //si el equipo falla cortamos el bucle
            }
            try {
                
                this->ControlarAlarmaFlujo(); //se controlan las alarmas, si alguna no funciona bien, salta una excepcion
            }
            catch (exception e) {
                cout << e.what();
                equipo->setNecesitaCorrectivo(true);   
                break;
            }

            int flujo = auxRespirador->Funcionar(10);     //se prueba que el flujo de salida sea igual al configurado
            if (flujo != auxRespirador->FlujoConfigSalida) {
                equipo->setNecesitaCorrectivo(true);
                cout<<"El flujo de salida no es igual al configurado";
                break;
            }
        }
    }


    
}

ostream& operator<<(ostream& out, cPreventivo& prev)
{
    out << "Mantenimiento Preventivo" << endl;
    cMantenimiento* aux = dynamic_cast<cMantenimiento*>(&prev);
    out << *aux;
    return out;
}
