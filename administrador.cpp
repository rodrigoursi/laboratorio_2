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

    string apellido, nombre, domicilio, localidad, provincia, pais, genero;
    int DNI, legajo, pin, dia, mes, anio, carga;
    bool admin;

    cout << "\t\t\t\t\t  *** INGRESE LOS DATOS ***" << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    cout << "\t\t\t\t\t** LEGAJO  : ";
    cin>>legajo;
    cout << "\t\t\t\t\t** NOMBRE  : ";
    cin>>nombre;
    cout << "\t\t\t\t\t** APELLIDO: ";
    cin>>apellido;
    cout << "\t\t\t\t\t** DNI     : ";
    cin  >> DNI;
    cout << "\t\t\t\t\t** DOMICILIO: ";
    cin>>domicilio;
    cout << "\t\t\t\t\t** LOCALIDAD: ";
    cin>>localidad;
    cout << "\t\t\t\t\t** PROVINCIA: ";
    cin>>provincia;
    cout << "\t\t\t\t\t** PAIS: ";
    cin>>pais;
    cout << "\t\t\t\t\t** FECHA NACIMIENTO dd/mm/aaaa: ";
    cin>>dia;cout<<"/";cin>>mes;cout<<"/";cin>>anio;
    cout << "\t\t\t\t\t** GENERO: ";
    cin>>genero;
    cout << "\t\t\t\t\t** CARGA HORARIA: ";
    cin>> carga;
    cout << "\t\t\t\t\t** ROL ADMIN: ";
    cin>>admin;
    FechaHora fnac(anio,mes,dia);
    FechaHora ingreso;
    Empleados obj(legajo,pin,nombre,apellido,DNI,domicilio,localidad,provincia,pais,fnac,genero,ingreso,carga,admin);
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


