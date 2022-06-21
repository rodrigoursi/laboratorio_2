#ifndef JORNADA_H_INCLUDED
#define JORNADA_H_INCLUDED

#include <string>
#include <cstring>
#include "fecha.h"
#include "Empleados.h"

using namespace std;

class Jornada{

private:
    FechaHora _fecha;
    Empleados _legajo;
    FechaHora _horaEntrada;
    FechaHora _horaSalida;
    FechaHora _horaTotal;
    char _estado[20];
    bool _ausente;

public:
    ///constructor
    Jornada(FechaHora, Empleados, FechaHora, FechaHora, FechaHora, string, bool ausente=0);
    ///
    ///get
    FechaHora getFecha();
    Empleados getLegajo();
    FechaHora getHoraEntrada();
    FechaHora getHoraSalida();
    FechaHora getHoraTotal();
    string getEstado();
    bool getAusente();
    ///
    ///set
    void setFecha(FechaHora);
    void setLegajo(Empleados);
    void setHoraEntrada(FechaHora);
    void setHoraSalida(FechaHora);
    void setHoraTotal(FechaHora);
    void setEstado(string);
    void setAusente(bool);
    ///
    bool guardarEnDisco();
    bool guardarEnDisco(int);
    bool leerDeDisco(int pos);

};

#endif // JORNADA_H_INCLUDED
