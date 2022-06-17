#include <cstring>
#include <iostream>
using namespace std;
#include "rlutil.h"
#include "administrador.h"
#include "FUNCIONES.h"
#include "Reportes.h"
#include "Empleados.h"


void MenuPrincipal(){

    int  opcion;
    char confirmarSalida;
    while(true){
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::cls();
        cout << "\t\t\t\t\t  *** MENU PRINCIPAL ***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - FICHAR. " << endl << endl;
        cout << "\t\t\t\t\t2 - ADMINISTRADOR. " << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        rlutil::locate(60,11);
        cin  >> opcion;
        if(opcion >= 0 && opcion < 3){
            system("cls");
        }
        switch(opcion){
            case 1: cout << "fichar";//MenuFichar();
                break;
            case 2: MenuAdministrador();
                break;
            case 0: cout << "¿Confirma salir? (S/N) ";
                    cin >> confirmarSalida;
                    if (tolower(confirmarSalida) == 's'){
                        exit -1;
                    }
                break;
        }
        cin.ignore();
        rlutil::anykey();
    }
}

void MenuAdministrador(){

    int  opcion;
    char confirmarSalida;
    if(pedirContrasenia()){
        while(true){
            rlutil::setColor(rlutil::WHITE);
            rlutil::setBackgroundColor(rlutil::DARKGREY);
            rlutil::cls();
            cout << "\t\t\t\t\t  *** MENU ADMINISTRADOR ***" << endl << endl;
            cout << "\t\t\t\t*******************************************" << endl << endl;
            cout << "\t\t\t\t\t1 - CARGAR EMPLEADO. " << endl << endl;
            cout << "\t\t\t\t\t2 - EDITAR EMPLEADO. " << endl << endl;
            cout << "\t\t\t\t\t3 - ELIMINAR EMPLEADO. " << endl << endl;
            cout << "\t\t\t\t\t4 - RESET PIN. " << endl << endl;
            cout << "\t\t\t\t\t5 - REPORTES. " << endl << endl;
            cout << "\t\t\t\t\t0 - VOLVER. " << endl << endl;
            cout << "\t\t\t\t*******************************************" << endl << endl;
            cout << "\t\t\t\t\tSELECCIONE OPCION: ";
            rlutil::locate(60,19);
            cin  >> opcion;
            if(opcion >= 1 && opcion < 5){
                system("cls");
            }
            switch(opcion){
                case 1: CargarEmpleado();
                    break;
                case 2: //EditarEmpleado();
                    break;
                case 3: EliminarEmpleado();
                    break;
                case 4: //RESET PIN();
                    break;
                case 5: Reportes();
                    break;
                case 0 : cout << endl << endl << "\t\t\t\t\t¿Confirma salir? (S/N) ";
                        cin >> confirmarSalida;
                        if (tolower(confirmarSalida) == 's'){
                            MenuPrincipal();
                        }
                    break;
            }
        }
    }
}

void mostrar(){
Empleados obj;
cout<<endl;
cout<<"-----------------------------"<<endl;
cout<<"Su nombre --> ";
cout<<obj.getnombre()<<endl;
cout<<"Su apellido --> ";
cout<<obj.getapellido()<<endl;
cout<<"Su DNI --> ";
cout<<obj.getdni()<<endl;
//cout<<"Horas de trabajo --> ";
//cout<<obj.getHoras_trabajo()<<endl;
//cout<<"Cantidad de dias ausentes --> ";
//cout<<obj.getAusencias()<<endl;
//cout<<"Cantidad de minutos tarde --> ";
//cout<<obj.getllegadas_tarde()<<endl;
cout<<"Su PIN --> ";
cout<<obj.getpin();
cout<<endl;
cout<<"-----------------------------"<<endl;
}

bool pedirContrasenia(){
    char usuario [30]     =  {};
    char contrasenia [30] =  {};
    char usuarioAdmin [30]     =  "admin";
    char contraseniaAdmin [30] =  "admin";
    Empleados obj;
    cout << "\t\t\t\t\tINGRESE USUARIO DE ADMINISTRADOR" << endl << endl;
    cin.ignore();
    cout << "\t\t\t\t\tUSUARIO    : ";
    rlutil::setColor(rlutil::WHITE);
    cin.getline(usuario, 30);
    cout << endl;
    cout << "\t\t\t\t\tCONTRASENIA: ";
    rlutil::setColor(rlutil::DARKGREY);
    cin.getline(contrasenia, 30);
    rlutil::setColor(rlutil::WHITE);

    if(strcmp(usuarioAdmin, usuario) == 0 && strcmp(contraseniaAdmin, contrasenia) == 0){
        cout << endl;
        cout << "\t\t\t\t\tBIENVENIDO!!! " << endl << endl;
        system("pause > nul");
        system("cls");
        return true;
    }
    else{
        cout << endl << "\t\t\t\t\tUSUARIO INVALIDO!!!" << endl << endl;
        system("pause > nul");
        system("cls");
        return false;
    }
}
/*
void MenuFichar(){
    Empleados reg;
    jornada obj;
    FechaHora hora;
    int  legajo,cuestion;
    char confirmarSalida;
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::cls();
        cout << "\t\t\t\t\t  *** MENU FICHAR ***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - COLOQUE ES SU PIN -> ";
        cin >> legajo;
        cout << "\t\t\t\t\t1 - ESTA INGRESANDO O SALIENDO? MARQUE 1 SI ESTA INGRESANDO O 2 SI ESTA SALIENDO -> ";
        cin >> cuestion;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        rlutil::locate(60,17);

        int nroRegistro;
        nroRegistro = reg.buscar_empleados(legajo);

        ///CARGA PARA CUANDO ESTE ENTRANDO
        if (nroRegistro >= 0 && cuestion == 1){
        reg.LeerDeDisco(nroRegistro);
            if(legajo==reg.leg){
            ///Se llena la info
            obj.setFecha(hora.Fecha());
            obj.setLegajo(legajo);
            obj.setApellido(reg.getapellido());
            obj.setNombre(reg.getnombre());
            obj.setHsTeorica(reg.getcargaHoraria);
            obj.setHoraEntrada(hora.Hora);
            ///Se guarda en disco
            obj.guardarEnDisco();
            }
        }
        else{
            cout << endl << "No existe el empleado";
        }

        ///CARGA PARA CUANDO ESTE SALIENDO
        if (nroRegistro >= 0 && cuestion == 2){
        reg.LeerDeDisco(nroRegistro);
            if(legajo==reg.leg){
            ///Se llena la info
            obj.setFecha(hora.Fecha());
            obj.setLegajo(legajo);
            obj.setApellido(reg.getapellido());
            obj.setNombre(reg.getnombre());
            obj.setHsTeorica(reg.getcargaHoraria);
            obj.setHoraSalida(hora.Hora);
            ///Se guarda en disco
            obj.guardarEnDisco();
            }
        }
        else{
            cout << endl << "No existe el empleado";
        }

        cin.ignore();
        rlutil::anykey();
}
*/
