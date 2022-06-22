#include "jornada.h"
#include "Empleados.h"
#include <cstring>
#include <string>
#include "FUNCIONES.h"

#include <iostream>

Jornada::Jornada(FechaHora fecha, Empleados legajo, FechaHora horaEnt, FechaHora horaSalida, FechaHora horaTotal, string estado, bool ausente)
{
    _fecha=fecha;
    _legajo=legajo;
    _horaEntrada=horaEnt;
    _horaSalida=horaSalida;
    _horaTotal=horaTotal;
    strcpy(_estado, estado.c_str());
    _ausente=ausente;
}
/// ///GET///

    FechaHora Jornada::getFecha(){return _fecha;}
    Empleados Jornada::getLegajo(){return _legajo;}
    FechaHora Jornada::getHoraEntrada(){return _horaEntrada;}
    FechaHora Jornada::getHoraSalida(){return _horaSalida;}
    FechaHora Jornada::getHoraTotal(){return _horaTotal;}
    string Jornada::getEstado(){string estado(_estado);return estado;}
    bool Jornada::getAusente(){ return _ausente;}

/// ///SET///

void Jornada::setFecha(FechaHora fecha){_fecha=fecha;}
void Jornada::setLegajo(Empleados legajo){_legajo=legajo;}
void Jornada::setHoraEntrada(FechaHora entrada){_horaEntrada=entrada;}
void Jornada::setHoraSalida(FechaHora salida){_horaSalida=salida;}
void Jornada::setHoraTotal(FechaHora total){_horaTotal=total;}
void Jornada::setEstado(string estado){strcpy(_estado, estado.c_str());}
void Jornada::setAusente(bool aus){_ausente=aus;}

/// ///DISCO///

bool Jornada::guardarEnDisco(){
    FILE *p = fopen("datos/jornada.dat","ab");
        if(p==NULL){
            return false;
        }
        bool guardo= fwrite(this,sizeof (Jornada),1,p);
        fclose(p);
        return guardo;
}

bool Jornada::guardarEnDisco(int pos){
    FILE *p = fopen("datos/jornada.dat","rb+");
        if(p==NULL){
            return false;
        }
        fseek(p,pos*sizeof(Jornada),SEEK_SET);
        bool guardo= fwrite(this,sizeof (Jornada),1,p);
        fclose(p);
        return guardo;
}

bool Jornada::leerDeDisco(int pos){
    FILE *p=fopen("datos/jornada.dat","rb");
    if(p==NULL){
        false;
    }
    fseek(p,pos*sizeof(Jornada),SEEK_SET);
    bool ok= fread(this,sizeof(Jornada),1,p);
    fclose(p);
    return ok;
}

int Jornada::contarRegistros(){
    FILE *p = fopen("datos/jornada.dat", "rb");
    if (p == NULL){
        return 0;
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Jornada);
    return cant_reg;
}

void fichar(){

    int legajo,PIN;
    cout<<"MENU FICHAR...!"<<endl<<endl;
    cout<<"INGRESE LEGAJO: ";
    cin>>legajo;
    cout<<endl<<"INGRESE PIN: ";
    cin>>PIN;
    system ("cls");
    if(validarLoginEmpleado(legajo,PIN)){
        guardarFichada(legajo);
        /*cout<<"EN CONSTRUCCION"<<endl;
        system ("pause");*/
    } else{
     Leg_pin_incorrecto();
    }

}

