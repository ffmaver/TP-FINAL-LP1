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

void cPreventivo::ControlarAlarmaPresion(cRespirador* respirador)
{
    respirador->setPresionPaciente(alta); //seteamos la presion en alta para que la alrma salte
    respirador->Funcionar(15);
    if (respirador->AlarmaPresion == false)
        throw new exception("La alarma de presion no se activo.");

    respirador->setPresionPaciente(sano); //seteamos la presion en alta para que la alrma salte
    respirador->Funcionar(15);
    if (respirador->AlarmaPresion)
        throw new exception("La alarma d presion anda mal.");
}

void cPreventivo::ControlarAlarmaFlujo(cRespirador* respirador)
{
    respirador->Funcionar(0);
    if(respirador->AlarmaFlujoCero == false)
        throw new exception("La alarma de flujo anda mal.");
}

void cPreventivo::ControlarAlarmaSuenio(cMesa* mesa)
{
    mesa->setSuenio(despertando);
    mesa->Funcionar(15);
    if(mesa->AlarmaSuenio==false)
        throw new exception("La alarma de suenio anda mal.");

    mesa->setSuenio(dormido);
    mesa->Funcionar(15);
    if (mesa->AlarmaSuenio)
        throw new exception("La alarma de suenio anda mal.");
}

void cPreventivo::ControlarAlarmaFrecuencia(cMesa* mesa)
{
    mesa->setFrecuencia(Alta); //la frecuencia es alta, si es false va a estar rota, no apagada
    mesa->Funcionar(15);
    if(mesa->AlarmaFrecuencia==false)
        throw new exception("La alarma de frecuencia anda mal.");

    mesa->setFrecuencia(Normal);
    mesa->Funcionar(15);
    if (mesa->AlarmaFrecuencia)
        throw new exception("La alarma de frecuencia anda mal.");
}



void cPreventivo::RealizarMantenimiento(cEquipo* equipo)
{
    cRespirador* auxRespirador = dynamic_cast<cRespirador*>(equipo);
    cElectro* auxElectro = dynamic_cast<cElectro*>(equipo);
    cMesa* auxMesa = dynamic_cast<cMesa*>(equipo);


    if (auxRespirador != NULL) {  //si es un respirador
        for (int i = 0; i < 10; i++) {    //lo hago 10 veces para asegurarme de que no falle nunca
            try {
                this->ControlarAlarmaPresion(auxRespirador);   //se controlan las alarmas, si alguna no funciona bien, salta una excepcion

            }
            catch (exception *e) {
                cout << e->what();
                equipo->setNecesitaCorrectivo(true);  //este equipo necesita mantenimiento correctivo
                break;  //si el equipo falla cortamos el bucle
            }
            try {
                
                this->ControlarAlarmaFlujo(auxRespirador); //se controlan las alarmas, si alguna no funciona bien, salta una excepcion
            }
            catch (exception *e) {
                cout << e->what();
                equipo->setNecesitaCorrectivo(true);   
                break;
            }

            int flujo = auxRespirador->Funcionar(10);     //se prueba que el flujo de salida sea igual al configurado
            if (flujo != auxRespirador->FlujoConfigSalida) {
                equipo->setNecesitaCorrectivo(true);
                cout<<"El flujo de salida no es igual al configurado"<< endl;
                break;
            }
        }
    }
    else if (auxMesa != NULL) {
        for (int i = 0; i < 10; i++) {
            try {
                this->ControlarAlarmaFrecuencia(auxMesa);   //se controlan las alarmas, si alguna no funciona bien, salta una excepcion

            }
            catch (exception *e) {
                cout << e->what();
                equipo->setNecesitaCorrectivo(true);  //este equipo necesita mantenimiento correctivo
                break;  //si el equipo falla cortamos el bucle
            }
            try {

                this->ControlarAlarmaSuenio(auxMesa); //se controlan las alarmas, si alguna no funciona bien, salta una excepcion
            }
            catch (exception *e) {
                cout << e->what();
                equipo->setNecesitaCorrectivo(true);
                break;
            }

            int flujo = auxMesa->Funcionar(10);     //se prueba que el flujo de salida sea igual al configurado
            if (flujo != auxMesa->FlujoConfig) {
                equipo->setNecesitaCorrectivo(true);
                cout << "El flujo de salida no es igual al configurado" <<endl;
                break;
            }
        }
    }
    else if (auxElectro != NULL) {
        for (int i = 0; i < 10; i++) {
            try {
                auxElectro->Funcionar();
            }
            catch (exception *e) {
                cout << e->what();
                equipo->setNecesitaCorrectivo(true);
                break;
            }
        }


    }

    
}

ostream& operator<<(ostream& out, cPreventivo& prev)
{
    out << "Mantenimiento Preventivo" << endl;
    cMantenimiento* aux = dynamic_cast<cMantenimiento*>(&prev); //casteo a cMant
    out << *aux;
    return out;
}
