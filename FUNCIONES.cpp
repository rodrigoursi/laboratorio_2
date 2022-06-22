#include <cstring>
#include <iostream>
using namespace std;
#include "rlutil.h"
#include "administrador.h"
#include "FUNCIONES.h"
#include "Reportes.h"
#include "Empleados.h"
#include "jornada.h"


bool validarLoginEmpleado(int legajo, int PIN) {

    Empleados empleado;
    for(int pos=0;pos<empleado.contarRegistros();pos++){
        empleado.LeerDeDisco(pos);
        if(legajo==empleado.getleg()&&PIN==empleado.getpin()){
            return true;
        }
    }
    return false;
}



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
            case 1: fichar();
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
    }
}

void MenuAdministrador(){
    int  opcion;
    Empleados obj;
    char confirmarSalida;
    while(pedirContrasenia()){
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
        cout << "\t\t\t\t\t6 - LISTADOS. " << endl << endl;
        cout << "\t\t\t\t\t0 - VOLVER. " << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        rlutil::locate(60,21);
        cin  >> opcion;
        if(opcion >= 1 && opcion < 6){
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
            case 5: mostrar();//Reportes();
                break;
            case 6: Listados();
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

void mostrar(){
Empleados obj;
cout<<endl<<obj.contarRegistros();
int pos;

    for(pos=0;pos<obj.contarRegistros();pos++){
            obj.LeerDeDisco(pos);
            cout<<"\t\t\t\tLISTADO --->"<<endl<<endl;
            cout << "\t\t\t\t" << "LEGAJO          : " << obj.getleg() << endl ;
            cout << "\t\t\t\t" << "NOMBRE          : " << obj.getnombre() << endl;
            cout << "\t\t\t\t" << "APELLIDO        : " << obj.getapellido() << endl;
            cout << "\t\t\t\t" << "DNI             : " << obj.getdni() << endl;
            cout << "\t\t\t\t" << "DOMICILIO       : " << obj.getdomicilio() << endl;
            cout << "\t\t\t\t" << "LOCALIDAD       : " << obj.getlocalidad() << endl;
            cout << "\t\t\t\t" << "PROVINCIA       : " << obj.getprovincia() << endl;
            cout << "\t\t\t\t" << "PAIS            : " << obj.getpais() << endl;
            cout << "\t\t\t\t" << "FECHA NACIMIENTO: " << obj.getFnacimiento().getDia() << "/" << obj.getFnacimiento().getMes() << "/" << obj.getFnacimiento().getAnio() <<endl;
            cout << "\t\t\t\t" << "GENERO          : " << obj.getgenero() << endl;
            cout << "\t\t\t\t" << "CARGA HORARIA   : " << obj.getcargaHoraria() << endl;
            cout << "\t\t\t\t" << "ROL             : ";
            if(obj.getRol() == true){
                cout << "Administrador." << endl;
            }
            else{
                cout << "Empleado." << endl;
            }
            cout << "\t\t\t\t------------------------------------------" << endl;
    }
}

bool pedirContrasenia(){
    int legajo,PIN;
    cout << "\t\t\t\t\tINGRESE LEGAJO DE ADMINISTRADOR" << endl << endl;
    cin.ignore();
    cout << "\t\t\t\t\tLEGAJO    : ";
    rlutil::setColor(rlutil::WHITE);
    cin>>legajo;
    cout << endl;
    cout << "\t\t\t\t\tPIN: ";
    rlutil::setColor(rlutil::DARKGREY);
    cin>>PIN;
    rlutil::setColor(rlutil::WHITE);

    Empleados empleado;
    for(int pos=0;pos<empleado.contarRegistros();pos++){
        empleado.LeerDeDisco(pos);
        if(legajo==empleado.getleg()&&PIN==empleado.getpin()&&empleado.getRol()){
            cout << endl;
            cout << "\t\t\t\t\tBIENVENIDO!!! " << endl << endl;
            cout << "\t\t\t\t\tPresione una TECLA para continuar " << endl << endl;
            system("pause > nul");
            system("cls");
            return true;
        } /*else {
            cout << endl << "\t\t\t\t\tUSUARIO INVALIDO!!!" << endl << endl<<"\t\t\t\t\tPresione una tecla";
            system("pause > nul");
            system("cls");
            return false;
        }*/
    }
        cout << endl << "\t\t\t\t\tUSUARIO INVALIDO!!!" << endl << endl<<"\t\t\t\t\tPresione una tecla";
        system("pause > nul");
        system("cls");
        return false;

    /*

    int leg=-100, pin=1234, legajo, PIN;
    cout << "\t\t\t\t\tINGRESE LEGAJO DE ADMINISTRADOR" << endl << endl;
    cin.ignore();
    cout << "\t\t\t\t\tLEGAJO    : ";
    rlutil::setColor(rlutil::WHITE);
    cin>>legajo;
    cout << endl;
    cout << "\t\t\t\t\tPIN: ";
    rlutil::setColor(rlutil::DARKGREY);
    cin>>PIN;
    rlutil::setColor(rlutil::WHITE);

    if(leg == legajo && pin == PIN){
        cout << endl;
        cout << "\t\t\t\t\tBIENVENIDO!!! " << endl << endl;
        cout << "\t\t\t\t\tPresione una TECLA para continuar " << endl << endl;
        system("pause > nul");
        system("cls");
        return true;
    }

    cout << endl << "\t\t\t\t\tUSUARIO INVALIDO!!!" << endl << endl<<"\t\t\t\t\tPresione una tecla";
    system("pause > nul");
    system("cls");
    return false;*/
}
void Listados(){
    int opcion;
    char confirmarSalida;
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::DARKGREY);
    rlutil::cls();
    cout << "\t\t\t\t\t  *** LISTADOS ***" << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    cout << "\t\t\t\t\t1 - LISTAR EMPLEADOS ACTIVOS. " << endl << endl;
    cout << "\t\t\t\t\t2 - LISTAR EMPLEADOS DADOS DE BAJA. " << endl << endl;
    cout << "\t\t\t\t\t0 - VOLVER. " << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    cout << "\t\t\t\t\tSELECCIONE OPCION: ";
    rlutil::locate(60,13);
    cin  >> opcion;
    if(opcion >= 1 && opcion < 3){
        system("cls");
    }
    switch(opcion){
        case 1: // LISTAR EMPLEADOS ACTIVOS
            break;
        case 2: //LISTAR EMPLEADOS DADOS DE BAJA
            break;
        case 0 : cout << endl << endl << "\t\t\t\t\t¿Confirma salir? (S/N) ";
                cin >> confirmarSalida;
                if (tolower(confirmarSalida) == 's'){
                    MenuPrincipal();
                }
            break;
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
