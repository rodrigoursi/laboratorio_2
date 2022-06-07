#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include <string>
#include <iostream>

class Empleados{
private:
    char Nombre[20];
    char Apellido[20];
    char Cargo[20];
    char FechaIngreso[10];
    char FechaSalida[10];
    int DNI, Horas_trabajo, Horas_extras, Ausencias, llegadas_tarde, PIN, Hora_ingreso, Hora_salida;
    bool Eliminado;
public:
    ///CONSTRUCTOR
    //Empleados{PIN=0000;}
    ///GETS
    std::string getNombre();
    std::string getApellido();
    std::string getCargo();
    int getDNI();
    int getHoras_trabajo();
    int getHoras_extras();
    int getAusencias();
    int getllegadas_tarde();
    int getPIN();
    bool getEliminado() const;
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
