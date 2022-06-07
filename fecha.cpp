#include "fecha.h"
#include <ctime>
using namespace std;

int  Fecha::getDia(){
    return _dia;
}
int  Fecha::getMes(){
    return _mes;
}
int  Fecha::getAnio(){
    return _anio;
}
int  Fecha::getHora(){
    return _hora;
}
int  Fecha::getMinutos(){
    return _minutos;
}
void Fecha::setDia(int dia){
    _dia = dia;
}
void Fecha::setMes(int mes){
    _mes = mes;
}
void Fecha::setAnio(int anio){
    _anio = anio;
}
void Fecha::setHora(int Hora){
    _hora = Hora;
}
void Fecha::setMinutos(int Minutos){
    _minutos = Minutos;
}
Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}
Fecha::Fecha(){
    time_t rawtime;
    struct tm timeinfo;

    time (&rawtime);
    timeinfo = *(localtime (&rawtime));

    _dia = timeinfo.tm_mday;
    _mes = timeinfo.tm_mon + 1;
    _anio = timeinfo.tm_year + 1900;
}
string Fecha::toString(){
    string fecha;
    fecha = to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
    return fecha;
}

