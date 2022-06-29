#include <iostream>
#include <string>
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

    string apellido, nombre, domicilio, localidad, provincia, pais, genero;
    int DNI, legajo, pin, dia, mes, anio, carga, genNum;
    bool ok, admin, stop=false;

    cout << "\t\t\t\t\t  *** INGRESE LOS DATOS ***" << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    cout << "\t\t\t\t\t** LEGAJO       : ";
    cin  >> legajo;
    if(ValidarLegajoExistente(legajo) == false){
        MenuAdministrador();
        cout << endl << "\t\t\t\t" << system ("pause");
    }
    cout << "\t\t\t\t\t** NOMBRE       : ";
    cin.ignore();
    getline(cin,nombre);
    cout << "\t\t\t\t\t** APELLIDO     : ";
    getline(cin,apellido);
    cout << "\t\t\t\t\t** DNI          : ";
    cin  >> DNI;
    cout << "\t\t\t\t\t** DOMICILIO    : ";
    cin.ignore();
    getline(cin,domicilio);
    cout << "\t\t\t\t\t** LOCALIDAD    : ";
    getline(cin,localidad);
    cout << "\t\t\t\t\t** PROVINCIA    : ";
    getline(cin,provincia);
    cout << "\t\t\t\t\t** PAIS         : ";
    getline(cin,pais);
    cout << "\t\t\t\t\t** FECHA NACIMIENTO dd/mm/aaaa: ";
    rlutil::locate(73,13);
    cin  >> dia;
    rlutil::locate(75,13);
    cout << "/";
    rlutil::locate(76,13);
    cin  >> mes;
    rlutil::locate(78,13);
    cout << "/";
    rlutil::locate(79,13);
    cin  >> anio;
    cout << "\t\t\t\t\t** 1 para Masculino 2 para Femenino"<<endl;
    cout << "\t\t\t\t\t** GENERO       : ";
    cin  >> genNum;
    while(stop==false){
        if(genNum==1||genNum==2){
            if(genNum==1){
                genero="m";
            }else genero="F";
            stop=true;
        }
        else{
            cout << "\t\t\t\t\t** El genero es representado con un 1 para Masculino y 2 para Femenino."<<endl;
            cout << "\t\t\t\t\t** GENERO       : ";
            cin  >> genNum;
        }
    }
    cout << "\t\t\t\t\t** CARGA HORARIA: ";
    cin  >> carga;
    cout << "\t\t\t\t\t** ROL ADMIN    : ";
    cin  >> admin;
    FechaHora fnac(anio,mes,dia);
    FechaHora ingreso;
    Empleados obj(legajo,pin,nombre,apellido,DNI,domicilio,localidad,provincia,pais,fnac,genero,ingreso,carga,admin);
    ok = obj.GuardarEnDisco();
    cout << endl << "\t\t\t\t\t" << system("pause");
    system("cls");
    MenuAdministrador();
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


