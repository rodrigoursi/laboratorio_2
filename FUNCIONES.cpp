#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#include "rlutil.h"
#include "administrador.h"
#include "FUNCIONES.h"
#include "Reportes.h"
#include "Empleados.h"
#include "jornada.h"
#include "fecha.h"

bool password=false;

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

void MenuAdministrador(){
    int  opcion;
    Empleados obj;
    char confirmarSalida;
    if(password==false){password=pedirContrasenia();}
    while(password){
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
            case 5: Reportes();//Reportes();
                break;
            case 6: Listados();
                break;
            case 0 : cout << endl << endl << "\t\t\t\t\t¿Confirma salir? (S/N) ";
                    cin >> confirmarSalida;
                    if (tolower(confirmarSalida) == 's'){
                        password=false;
                        exit(-1);
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
    system ("pause");
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
        case 1: mostrar(); // LISTAR EMPLEADOS ACTIVOS
            break;
        case 2: //LISTAR EMPLEADOS DADOS DE BAJA
            break;
        case 0 : cout << endl << endl << "\t\t\t\t\t¿Confirma salir? (S/N) ";
                cin >> confirmarSalida;
                if (tolower(confirmarSalida) == 's'){
                    exit(-1);
                }
            break;
    }
}

void guardarFichada(int legajo){

    FechaHora hora;
    Empleados empleado;
    Jornada aux;
    int pos=0;
    while(aux.leerDeDisco(pos++)){
        if(hora.getAnio()==aux.getFecha().getAnio()&&
           hora.getMes()==aux.getFecha().getMes()&&
           hora.getDia()==aux.getFecha().getDia()&&
           legajo==aux.getLegajo().getleg()){
            aux.setHoraSalida(hora);
            cout<<"SALIDA GUARDADA"<<endl;
            system("pause");
            cout<<endl<<endl<<aux.getFecha().getDia()<<"/"<<aux.getFecha().getMes()<<"/"<<aux.getFecha().getAnio()<<endl
            <<"legajo: "<<aux.getLegajo().getleg()<<endl
            <<"Entrada: "<<aux.getHoraEntrada().getHora()<<":"<<aux.getHoraEntrada().getMinuto()<<endl
            <<"Salida: "<<aux.getHoraSalida().getHora()<<":"<<aux.getHoraSalida().getMinuto()<<endl
            <<"Total: "<<aux.getHoraTotal().getHora()<<":"<<aux.getHoraTotal().getMinuto()<<endl
            <<aux.getEstado()<<endl
            <<aux.getAusente()<<endl;
            system("pause");
            exit(-1);
           }
    }
    empleado.LeerDeDisco(buscarEmpleado(legajo));
    Jornada jornada(hora,empleado,hora,hora,hora);
    jornada.guardarEnDisco();
    cout<<"ENTRADA GUARDADA"<<endl;
    system("pause");
    cout<<endl<<endl<<jornada.getFecha().getDia()<<"/"<<jornada.getFecha().getMes()<<"/"<<jornada.getFecha().getAnio()<<endl
    <<"legajo: "<<jornada.getLegajo().getleg()<<endl
    <<jornada.getHoraEntrada().getHora()<<":"<<jornada.getHoraEntrada().getMinuto()<<endl
    <<jornada.getHoraSalida().getHora()<<":"<<jornada.getHoraSalida().getMinuto()<<endl
    <<jornada.getHoraTotal().getHora()<<":"<<jornada.getHoraTotal().getMinuto()<<endl
    <<jornada.getEstado()<<endl
    <<jornada.getAusente()<<endl;
    system ("pause");
}

void Leg_pin_incorrecto(){
    cout<<endl;
    cout<<"\t\t\t\t ========================="<<endl;
    cout<<"\t\t\t\t| Legajo o PIN incorrecto |"<<endl;
    cout<<"\t\t\t\t ========================="<<endl;
    cout<<endl;cout<<endl;cout<<endl;
    cout<<" ----------------------------------"<<endl;
    cout<<"| ";
    system ("pause");
    cout<<"-------------------------"<<endl;
    system ("cls");
}

void Cerrar_Programa(){
Empleados reg;
int leg, pin;
bool activo;
system ("cls");
cout << "\t\t\t\t\t  *** CERRAR PROGRAMA ***" << endl << endl;
cout << "\t\t\t\t*******************************************" << endl << endl;
cout<<"\t\t\t\t Legajo de admin -> ";
cin>>leg;
cout<<endl;
cout<<"\t\t\t\t PIN de admin -> ";
cin>>pin;
cout<<endl;
activo=validarLoginEmpleado(leg,pin);
    if(activo==true){
    int pos;
    pos=buscarEmpleado(leg);
    reg.LeerDeDisco(pos);
        if(reg.getleg()==leg && pin==reg.getpin()&&reg.getRol()){
        exit (0);
        }
        else{
        cout<<"\t\t\t\t ==============================="<<endl;
        cout<<"\t\t\t\t| No tiene rol de administrador |"<<endl;
        cout<<"\t\t\t\t ==============================="<<endl;
        system("pause");
        }
    }
    if(activo!=true){
    Leg_pin_incorrecto();
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
