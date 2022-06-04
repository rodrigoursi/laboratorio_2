#include <iostream>
#include <cstring>
#include "administrador.h"
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

void MenuAdministrador(){

    int opc;

    while(true){
        cout << "\t\t\t\t\t\t***ADMINISTRADOR***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - LISTADO DE EMPLEADOS. " << endl << endl;
        cout << "\t\t\t\t\t2 - LISTADO DE EMPLEADOS POR TURNO. " << endl << endl;
        cout << "\t\t\t\t\t3 - LISTADO DE EMPLEADOS POR GENERO. " << endl << endl;
        cout << "\t\t\t\t\t4 - LISTADO DE LLEGADAS TARDE. " << endl << endl;
        cout << "\t\t\t\t\t5 - LISTADO DE LLEGADAS TARDE POR EMPLEADO. " << endl << endl;
        cout << "\t\t\t\t\t6 - DIAS TRABAJADOS. " << endl << endl;
        cout << "\t\t\t\t\t7 - LISTAR AUSENTISMOS. " << endl << endl;
        cout << "\t\t\t\t\t8 - CANTIDAD DE EMPLEADOS. " << endl << endl;
        cout << "\t\t\t\t\t9 - BUSCAR EMPLEADO. " << endl << endl;
        cout << "\t\t\t\t\t0 - VOLVER." << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        cin  >> opc;

        system("cls");
        //ACA VA EL SWITCH CON LAS OPCIONES
    }
    cout << "\t\t\t\t\t" << system("pause");
    system("cls");
}
