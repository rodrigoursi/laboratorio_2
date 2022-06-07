#ifndef ADMINISTRADOR_H_INCLUDED
#define ADMINISTRADOR_H_INCLUDED

class Administrador{
    private:
        char _Usuario [30], _Contrasenia[];
    public:
        Administrador();
        void setUsuarioAdmin(char *Usuario);
        void setContraseniaAdmin(char *Contrasenia);
        char *getUsuarioAdmin();
        char *getContraseniaAdmin();
        bool grabarEnDisco();
        bool leerDeDisco(int pos);
        void menuAdministrador();
};

///FUNCIONES GLOBALES
void MenuAdministrador();
void ListarEmpleados();
void ListarEmpleadosPorTurno(int IdTurno);
void ListarEmpleadosPorGenero(int IdGenero);
int  DiasTrabajados(int Pin);
void ListarLlegadasTarde();
void ListarLlegadasTardePorEmpleado(int Pin);
void ListarLlegadasTardePorFecha(int dia, int mes, int anio);
void ListarAusentimos();
int  CantidadEmpleados();
//BuscarEmpleado(int Pin); DETERMINAR PARA QUE LA USARIAMOS

#endif // ADMINISTRADOR_H_INCLUDED
