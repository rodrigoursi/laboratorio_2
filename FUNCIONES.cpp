#include <cstring>
#include <iostream>
using namespace std;
#include "FUNCIONES.h"
#include "rlutil.h"
#include "administrador.h"

void menu_principal(){
int  opcion;
    char confirmarSalida;
    while(true){
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::cls();
        cout << "Menu Principal" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - FICHAR" << endl;
        cout << "2 - Empleados" << endl;
        cout << "3 - Administrador" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;
        cout << "Opcion: ";
        cin >> opcion;
        rlutil::cls();
        cout << "\t\t\t\t\t  *** MENU PRINCIPAL ***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - FICHAR. " << endl << endl;
        cout << "\t\t\t\t\t2 - INCIAR SESION COMO ADMINISTRADOR. " << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        rlutil::locate(60,11);
        cin  >> opcion;
        if(opcion >= 0 && opcion < 3){
            system("cls");
        }
        switch(opcion){
            case 1:
                cout<<"fichar";//Empleados::menu_FICHAR();
            break;
            case 2:
                MenuAdministrador();
            break;
            case 0:
                cout << "¿Confirma salir? (S/N) ";
                cin >> confirmarSalida;
                if (tolower(confirmarSalida) == 's'){
                    return 0;
                }
            break;
        }
        cin.ignore();
        rlutil::anykey();
}
