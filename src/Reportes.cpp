#include <iostream>
#include "Reportes.h"
#include "../administrador.h"
#include "rlutil.h"


using namespace std;

void Reportes(){

    int  opcion;
    char confirmarSalida;
    while(true){
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::cls();
        cout << "\t\t\t\t\t  *** REPORTES ADMINISTRADOR ***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - REPORTE POR EMPLEADO POR MES. " << endl << endl;
        cout << "\t\t\t\t\t2 - REPORTE POR DIA PARA TODOS LOS EMPLEADOS. " << endl << endl;
        cout << "\t\t\t\t\t3 - REPORTE POR DIA POR EMPLEADO. " << endl << endl;
        cout << "\t\t\t\t\t0 - VOLVER. " << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        rlutil::locate(60,11);
        cin  >> opcion;
        if(opcion >= 0 && opcion < 4){
            system("cls");
        }
        switch(opcion){
            case 1: ReportePorEmpleadoPorMes();
                break;
            case 2: ReportePorDiaParaTodosLosEmpleados();
                break;
            case 3: ReportePorDiaPorEmpleado();
                break;
            //case 0: MenuAdministrador();
                break;
        }
        cin.ignore();
        rlutil::anykey();
    }

}

void ReportePorEmpleadoPorMes(){
    cout << "1 - REPORTE POR EMPLEADO POR MES." << endl;
}

void ReportePorDiaParaTodosLosEmpleados(){
    cout << "2 - REPORTE POR DIA PARA TODOS LOS EMPLEADOS." << endl;
}

void ReportePorDiaPorEmpleado(){
    cout << "3 - REPORTE POR DIA POR EMPLEADO." << endl;
}
