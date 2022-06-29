#include "calendario.h"
#include "Empleados.h"
#include <cstring>
#include <string>
#include "FUNCIONES.h"
#include "rlutil.h"

#include <iostream>

Calendario::Calendario(FechaHora fecha, Empleados legajo, FechaHora horaEnt, FechaHora horaSalida)
{
    _fecha=fecha;
    _legajo=legajo;
    _horaEntrada=horaEnt;
    _horaSalida=horaSalida;
}
/// ///GET///

    FechaHora Calendario::getFecha(){return _fecha;}
    Empleados Calendario::getLegajo(){return _legajo;}
    FechaHora Calendario::getHoraEntrada(){return _horaEntrada;}
    FechaHora Calendario::getHoraSalida(){return _horaSalida;}

/// ///SET///

void Calendario::setFecha(FechaHora fecha){_fecha=fecha;}
void Calendario::setLegajo(Empleados legajo){_legajo=legajo;}
void Calendario::setHoraEntrada(FechaHora entrada){_horaEntrada=entrada;}
void Calendario::setHoraSalida(FechaHora salida){_horaSalida=salida;}

/// ///DISCO///

bool Calendario::guardarEnDisco(){
    FILE *p = fopen("datos/calendario.dat","ab");
        if(p==NULL){
            return false;
        }
        bool guardo= fwrite(this,sizeof (Calendario),1,p);
        fclose(p);
        return guardo;
}

bool Calendario::guardarEnDisco(int pos){
    FILE *p = fopen("datos/calendario.dat","rb+");
        if(p==NULL){
            return false;
        }
        fseek(p,pos*sizeof(Calendario),SEEK_SET);
        bool guardo= fwrite(this,sizeof (Calendario),1,p);
        fclose(p);
        return guardo;
}

bool Calendario::leerDeDisco(int pos){
    FILE *p=fopen("datos/calendario.dat","rb");
    if(p==NULL){
        false;
    }
    fseek(p,pos*sizeof(Calendario),SEEK_SET);
    bool ok= fread(this,sizeof(Calendario),1,p);
    fclose(p);
    return ok;
}

int Calendario::contarRegistros(){
    FILE *p = fopen("datos/calendario.dat", "rb");
    if (p == NULL){
        return 0;
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Calendario);
    return cant_reg;
}
