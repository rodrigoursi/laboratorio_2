#include "jornada.h"
#include "Empleados.h"
/*
Jornada::Jornada(FechaHora fecha, Empleados legajo, Empleados apellido,
                Empleados nombre, FechaHora hsEntradaTeorica,
                FechaHora horaEnt, FechaHora horaSalida, FechaHora horaTotal,
                char estado, bool ausente)
{
    _fecha=fecha;
    _legajo=legajo;
    _apellido=apellido;
    _nombre=nombre;
    _hsEntradaTeorica=hsEntradaTeorica;
    _horaEntrada=horaEnt;
    _horaSalida=horaSalida;
    _horaTotal=horaTotal;
    _estado=estado;
    _ausente=ausente;
}
/// ///GET///

    FechaHora Jornada::getFecha(){return _fecha;}
    Empleados Jornada::getLegajo(){return _legajo;}
    Empleados Jornada::getApellido(){return _apellido;}
    Empleados Jornada::getNombre(){return _nombre;}
    FechaHora Jornada::getHsTeorica(){return _hsEntradaTeorica;}
    FechaHora Jornada::getHoraEntrada(){return _horaEntrada;}
    FechaHora Jornada::getHoraSalida(){return _horaSalida;}
    Fechahora Jornada::getHoraTotal(){return _horaTotal;}
    string getEstado(){
        string estado(_estado);
        return estado;}
    bool getAusente(){ return _ausente;}

/// ///SET///

void Jornada::setFecha(FechaHora fecha){_fecha=fecha;}
void Jornada::setLegajo(Empleados legajo){_legajo=legajo;}
void Jornada::setApellido(Empleados apellido){_apellido=apellido;}
void Jornada::getNombre(Empleados nombre){_nombre=nombre;}
void Jornada::setHsTeorica(FechaHora horaTeorica){_hsEntradaTeorica=horaTeorica;}
void Jornada::setHoraEntrada(FechaHora entrada){_horaEntrada=entrada;}
void Jornada::setHoraSalida(FechaHora salida){_horaSalida=salida;}
void Jornada::setHoraTotal(FechaHora total){_horaTotal=total;}
void Jornada::setEstado(string estado){strcpy(_estado, estado.c_str());}
void Jornada::setAusente(bool aus){_ausente=aus;}

/// ///DISCO///

bool Jornada::guardarEnDisco(){
    FILE *p = fopen("jornada.dat","ab");
        if(p==NULL){
            return false;
        }
        bool guardo= fwrite(this,sizeof (Jornada),1,p);
        fclose(p);
        return guardo;
}

bool Jornada::guardarEnDisco(int pos){
    FILE *p = fopen("jornada.dat","rb+");
        if(p==NULL){
            return false;
        }
        fseek(p,pos*sizeof(Estudiante),SEEK_SET);
        bool guardo= fwrite(this,sizeof (Jornada),1,p);
        fclose(p);
        return guardo;
}

bool Jornada::leerDeDisco(int pos){
    FILE *p=fopen("jornada.dat","rb");
    if(p==NULL){
        false;
    }
    fseek(p,pos*sizeof(jornada),SEEK_SET);
    bool ok= fread(this,sizeof(Estudiante),1,p);
    fclose(p);
    return ok;
}
*/
