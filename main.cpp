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
int main(){
    int  opcion;
    char confirmarSalida;
    while(true){
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::cls();
        cout << "Men� Principal" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - FICHAR" << endl;
        cout << "2 - Empleados" << endl;
        cout << "3 - Administrador" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;
        cout << "Opci�n: ";
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
                Empleados::menu_FICHAR();
            break;
            case 2:
                MenuAdministrador();
            break;
            case 0:
                cout << "�Confirma salir? (S/N) ";
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
