#include <cstring>
#include <iostream>
using namespace std;
#include "rlutil.h"
#include "administrador.h"
#include "FUNCIONES.h"
#include "Reportes.h"


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
            case 1: cout << "fichar";//Empleados::menu_FICHAR();
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
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        rlutil::locate(60,17);
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
            case 0 : cout << "¿Confirma salir? (S/N) ";
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
