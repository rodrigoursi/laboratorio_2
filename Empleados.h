#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include <string>
#include <cstring>
#include "fecha.h"

using namespace std;

class Empleados{
private:
    int leg;
    int pin;
    char nombre[50];
    char apellido[50];
    int dni;
    char domicilio[50];
    char localidad[50];
    char provincia[50];
    char pais[50];
    FechaHora fNacimiento;
    char genero[10];
    FechaHora fechaIngreso;
    FechaHora horarioTrabajo;
    int cargaHoraria;
    bool activo;
public:
    ///CONSTRUCTOR
    //Empleados::Empleados(){pin=0000;}
    ///GETS
    const char *getnombre(){return nombre;}
    const char *getapellido(){return apellido;}
    int getleg(){return leg;}
    int getpin(){return pin;}
    int getdni(){return dni;}
    const char *getdomicilio(){return domicilio;}
    const char *getlocalidad(){return localidad;}
    const char *getprovincia(){return provincia;}
    const char *getpais(){return pais;}
    //FechaHora getFnacimiento(){return .Fnacimiento;}
    const char *getgenero(){return genero;}
    //FechaHora getFechaIngreso(){return .FechaIngreso;}
    //FechaHora getHorarioTrabajo(){return .HorarioTrabajo;}
    int getcargaHoraria(){return cargaHoraria;}
    bool getEliminado(){return activo;}

    ///////////////////////////////////////////////
    ///////////////////////////////////////////////

    ///SETS
    void setnombre(const char *n){strcpy(nombre,n);}
    void setapellido(const char *a){strcpy(apellido,a);}
    void setleg(int l){leg=l;}
    void setpin(int p){pin=p;}
    void setdni(int d){dni=d;}
    void setdomicilio(const char *d){strcpy(domicilio,d);}
    void setlocalidad(const char *l){strcpy(localidad,l);}
    void setprovincia(const char *p){strcpy(provincia,p);}
    void setpais(const char *p){strcpy(pais,p);}

    //sets de (Fnacimiento-FechaIngreso-HorarioTrabajo)

    void setgenero(const char *g){strcpy(genero,g);}
    void setcargaHoraria(int c){cargaHoraria=c;}
    void setEliminado(bool e){activo=e;}

    ///DECLARACION DE FUNCIONES DE LA CLASE
    void cargar();
    void mostrar();
    void cargararchivo();
    void mostrararchivo();
    bool LeerDeDisco(int nroRegistro);
    bool GuardarEnDisco();
    bool GuardarEnDisco(int nroRegistro);
    void menu_FICHAR();
};

///DECLARACION DE FUNCIONES GLOBALES
int cantidad_registros_empleados();
void listar_empleados();
int buscar_empleados(int pin);
void listar_empleados_x_PIN();
bool editar_empleados();
bool eliminar_empleados();

#endif // EMPLEADOS_H_INCLUDED
