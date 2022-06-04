#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "fecha.h"
#include "Empleados.h"
#include "administrador.h"

int main()
{
    int opcion;
    char confirmarSalida;
    while(true){
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::cls();
        cout << "Menú Principal" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - FICHAR" << endl;
        cout << "2 - Empleados" << endl;
        cout << "3 - Administrador" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;
        cout << "Opción: ";
        cin >> opcion;
        rlutil::cls();
        switch(opcion){
            case 1:
                Empleados::menu_FICHAR();
            break;
            case 2:
                Empleados::menuEmpleados();
            break;
            case 3:
                //Administrador::menuAdministrador();
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
}
