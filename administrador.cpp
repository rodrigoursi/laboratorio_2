#include <iostream>
#include <cstring>
#include "FUNCIONES.h"
#include "rlutil.h"
#include "administrador.h"
#include "Empleados.h"
using namespace std;


Administrador::Administrador(){}

void Administrador::setUsuarioAdmin(char *Usuario){
    strcpy(_Usuario, Usuario);
}

void Administrador::setContraseniaAdmin(char *Contrasenia){
    strcpy(_Contrasenia, Contrasenia);
}

char *Administrador::getUsuarioAdmin(){
    return _Usuario;
}

char *Administrador::getContraseniaAdmin(){
    return _Contrasenia;
}

bool Administrador::grabarEnDisco(){

    FILE *p;
    p = fopen("Administradores.dat","ab");
    if(p == NULL){
        cout << "\t\t\t\t\tNO SE PUDO ABRIR EL ARCHIVO.";
        return false;
    }
    bool ok = fwrite(this,sizeof(Administrador),1,p);
    if (ok == true){
        cout << endl << "\t\t\t\t\tREGISTRO GUARDADO."<< endl << endl;
    }
    else{
        cout << endl << "\t\t\t\t\tNO SE PUDO GUARDAR EL REGISTRO."<< endl << endl;
    }
    fclose(p);
    return ok;
}

bool Administrador::leerDeDisco(int pos){
    FILE *p;
    p = fopen("Administradores.dat","rb");
    if(p == NULL){
        cout << endl << endl << "\t\t\t\t\tNO HAY USUARIOS REGISTRADOS." << endl << endl;
        cout << "\t\t\t\t\t" << system("pause");
        system("cls");
        return false;
    }
    else{
        fseek(p,sizeof(Administrador)* pos,SEEK_SET);
        bool ok = fread(this, sizeof(Administrador), 1, p);
        fclose(p);
        return ok;
    }
}

void CargarEmpleado(){

    Empleados obj;
    char apellido[50], nombre[50];
    int DNI, Horas_trabajo, PIN;

    cout << "\t\t\t\t\t  *** INGRESE LOS DATOS ***" << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    cout << "\t\t\t\t\t** NOMBRE  : ";
    cin.ignore();
    cin.getline(nombre, 50);
    obj.setnombre(nombre);
    cout << "\t\t\t\t\t** APELLIDO: ";
    cin.getline(apellido, 50);
    obj.setapellido(apellido);
    cout << "\t\t\t\t\t** DNI     : ";
    cin  >> DNI;
    obj.setdni(DNI);
    //cout<<"Cuantas son tus horas de trabajo? --> ";
    //cin>>Horas_trabajo;
    //obj.setHorarioTrabajo(Horas_trabajo);
    cout << "\t\t\t\t\t** PIN     : ";
    cin  >> PIN;
    obj.setpin(PIN);
}

/* 2 - CORREGIR EDITAR EMPLEADO
bool EditarEmpleado(){
    int  pin, nroRegistro;
    bool ok = false;
    string Nuevo_cargo;
    string Nuevo_horario;
    cout << "Legajo: ";
    cin >> pin;

    nroRegistro = buscar_empleados(pin);
    if (nroRegistro >= 0){
        Empleados reg;
        FechaHora obj;
        reg.LeerDeDisco(nroRegistro);
        int Nuevo_horario;
        char Nuevo_cargo[20];
        cout << endl;
        cout << endl << endl;
        cout << "Nuevo horario: ";
        cin >> Nuevo_horario;
        //obj.sethorarioTrabajo(Nuevo_horario);
        ok = reg.GuardarEnDisco(nroRegistro);
}
    return ok;
}
*/

bool EliminarEmpleado(){

    Empleados reg;
    int  pin, nroRegistro;
    bool ok = false;
    char confirmacion;

    cout << "\t\t\t\t\t  *** SELECCIONE EMPLEADO A ELIMINAR ***" << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    cout << "\t\t\t\t\t** PIN  : ";
    cin  >> pin;

    nroRegistro = buscar_empleados(pin);
    if (nroRegistro >= 0) {
        reg.LeerDeDisco(nroRegistro);
        cout << endl;
        cout << endl << endl;
        if (reg.getEliminado()) {
            cout << "EL EMPLEADO HA SIDO ELIMINADO" << endl;
        }
        else {
            cout << "Esta seguro de que lo quiere eliminarlo? S/N" << endl;
        }

        cin >> confirmacion;

        if (confirmacion == 'S' || confirmacion == 's') {
            reg.setEliminado(!reg.getEliminado());
            //ok = reg.GuardarEnDisco(nroRegistro);
        }
        else {
            ok = true;
        }
    }
    else {
        cout << endl << "\t\t\t\t\tNO EXISTE EMPLEADO CON ESE PIN..." << endl;
    }

    return ok;
}

//...

