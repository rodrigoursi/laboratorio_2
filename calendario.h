#ifndef CALENDARIO_H_INCLUDED
#define CALENDARIO_H_INCLUDED

#include <string>
#include <cstring>
#include "fecha.h"
#include "Empleados.h"

using namespace std;

class Calendario{

private:
    FechaHora _fecha;
    Empleados _legajo;
    FechaHora _horaEntrada;
    FechaHora _horaSalida;

public:
    ///constructor
    Calendario(FechaHora, Empleados, FechaHora, FechaHora);
    Calendario(){};
    ///
    ///get
    FechaHora getFecha();
    Empleados getLegajo();
    FechaHora getHoraEntrada();
    FechaHora getHoraSalida();
    ///
    ///set
    void setFecha(FechaHora);
    void setLegajo(Empleados);
    void setHoraEntrada(FechaHora);
    void setHoraSalida(FechaHora);
    ///
    bool guardarEnDisco();
    bool guardarEnDisco(int);
    bool leerDeDisco(int pos);
    int contarRegistros();

};

void cargarCalendario();
void actualizarCalendario();
void editarCalendario();
void CalendarioDeHorarios();
void mostrarHorarioXMes();

#endif // CALENDARIO_H_INCLUDED
