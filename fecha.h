#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <string>

class Fecha{
    public:
        int  getDia();
        int  getMes();
        int  getAnio();
        int  getHora();
        int  getMinutos();
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
        void setHora(int hora);
        void setMinutos(int minutos);
        Fecha(int dia, int mes, int anio);
        Fecha();
        std::string toString();

    private:
        int _dia, _mes, _anio;
        int _hora, _minutos;

};

#endif // FECHA_H_INCLUDED
