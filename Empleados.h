#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include <string>
#include "fecha.h"

class Empleados{
private:
    Fecha _femp;
    char Nombre[20];
    char Apellido[20];
    char Cargo[20];
    int DNI, Horas_trabajo, Horas_extras, Ausencias, llegadas_tarde, _PIN;
public:
    Empleados
    ///SETS
//    void setNombre(const char *n){strcpy (Nombre,n);}
//    void setApellido(const char *a){strcpy (Apellido,a);}
//    void setCargo(const char *c){strcpy (Cargo,c);}
//    void setDNI(int d){DNI = d;}
//    void setHoras_trabajo(int h){Horas_trabajo = h;}
//    void setHoras_extras(int he){Horas_extras = he;}
//    void setAusencias(int a){Ausencias = a;}
//    void setllegadas_tarde(int l){llegadas_tarde = l;}
//    void setPIN(int p){PIN = p;}
    ///GETS
//    const char *getNombre(){return Nombre;}
//    const char *getApellido(){return Apellido;}
//    const char *getCargo(){return Cargo;}
//    int getDNI(){return DNI;}
//    int getHoras_trabajo(){return Horas_trabajo;}
//    int getHoras_extras(){return Horas_extras;}
//    int getAusencias(){return Ausencias;}
//    int getllegadas_tarde(){return llegadas_tarde;}
//    int getPIN(){return PIN;}
//   Fecha getFechaNacimiento();
    ///FUNCIONES DE LA CLASE
    void menuEmpleados();
    void menu_FICHAR();
    void cargar();
    void mostrar();
    void cargararchivo();
    void mostrararchivo();
    bool LeerDeDisco(int nroRegistro);
    bool GuardarEnDisco();
    bool GuardarEnDisco(int nroRegistro);
};


///FUNCIONES GLOBALES
int cantidad_registros_empleados();
void listar_empleados();
void listar_empleados_x_PIN();
int buscar_empleados(int pin);
bool editar_empleados();
bool eliminar_empleados();

#endif // EMPLEADOS_H_INCLUDED
