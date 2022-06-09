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
    char genero;
    FechaHora fechaIngreso;
    FechaHora horarioTrabajo;
    bool activo;

public:
    ///CONSTRUCTOR
    //Empleados{PIN=0000;}
    ///GETS
    string getNombre();
    string getApellido();
    int getLegajo();
    int getPIN();
    int getDNI();
    string getDomicilio();
    string getLocalidad();
    string getProvincia();
    string getPais();
    FechaHora getFnacimiento();
    char getGenero();
    FechaHora getFechaIngreso();
    FechaHora getHorarioTrabajo();
    bool getEliminado();

    ///////////////////////////////////////////////
    ///////////////////////////////////////////////

    ///SETS
    void setNombre(std::string N);
    void setApellido(std::string A);
    void setCargo(std::string C);
    void setDNI(int D);
    void setHoras_trabajo(int H);
    void setHoras_extras(int H);
    void setAusencias(int A);
    void setllegadas_tarde(int L);
    void setPIN(int P);
    void setEliminado(bool E);
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
