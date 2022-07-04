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
#include "calendario.h"

int mesCantDias(int mes){

    switch(mes){

        case 1: return 31;
        break;
        case 2: return 28;
        break;
        case 3: return 31;
        break;
        case 5: return 31;
        break;
        case 7: return 31;
        break;
        case 8: return 31;
        break;
        case 10: return 31;
        break;
        case 12: return 31;
        break;
        default: return 30;

    }

}

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
    bool password=false;
    int opcion;
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
        cout << "\t\t\t\t\t5 - CALENDARIO EMPLEADO. " << endl << endl;
        cout << "\t\t\t\t\t6 - REPORTES. " << endl << endl;
        cout << "\t\t\t\t\t7 - LISTADOS. " << endl << endl;
        cout << "\t\t\t\t\t0 - VOLVER. " << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        cin  >> opcion;
        rlutil::locate(60,23);
        if(opcion >= 1 && opcion < 7){
            system("cls");
        }
        switch(opcion){
            case 1: CargarEmpleado();
                break;
            case 2: editar_empleados();
                break;
            case 3: EliminarEmpleado();
                break;
            case 4: //RESET PIN();
                break;
            case 5: CalendarioDeHorarios();
                break;
            case 6: Reportes();
                break;
            case 7: Listados();
                break;
            case 0 : cout << endl << endl << "\t\t\t\t\t¿Confirma salir? (S/N) ";
                    cin >> confirmarSalida;
                    if (tolower(confirmarSalida) == 's'){
                        password=false;
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
            cout << "\t\t\t\t" << "EMPLEADO ACTIVO : ";
            if(obj.getEliminado() == true){
             cout << "Si." << endl;
            }
            else{
                cout << "No." << endl;
            }
            cout << "\t\t\t\t------------------------------------------" << endl;
    }
    cout<<obj.contarRegistros()<<endl;
    cout << endl << "\t\t\t\t" << system ("pause");
}

void mostrarActivos(){
Empleados obj;
int pos;
    cout<<"\t\t\t\tLISTADO --->"<<endl<<endl;
    for(pos=0;pos<obj.contarRegistros();pos++){
            obj.LeerDeDisco(pos);
            if(obj.getEliminado()){
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
                cout << "\t\t\t\t" << "EMPLEADO ACTIVO : ";
                if(obj.getEliminado() == true){
                 cout << "Si." << endl;
                }
                else{
                    cout << "No." << endl;
                }
                cout << "\t\t\t\t------------------------------------------" << endl;
           }
    }
    cout << endl << "\t\t\t\t" << system ("pause");
}

void mostrarEliminados(){
Empleados obj;
int pos;
    cout<<"\t\t\t\tLISTADO --->"<<endl<<endl;
    for(pos=0;pos<obj.contarRegistros();pos++){
            obj.LeerDeDisco(pos);
            if(obj.getEliminado()==false){
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
                cout << "\t\t\t\t" << "EMPLEADO ACTIVO : ";
                if(obj.getEliminado() == true){
                 cout << "Si." << endl;
                }
                else{
                    cout << "No." << endl;
                }
                cout << "\t\t\t\t------------------------------------------" << endl;
           }
    }
    cout << endl << "\t\t\t\t" << system ("pause");
}

bool pedirContrasenia(){
    int legajo,PIN;
    cout << "\t\t\t\t  *** INGRESE USUARIO DE ADMINISTRADOR ***" << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
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
    cout << "\t\t\t\t\t3 - LISTAR FICHA EMPLEADO. " << endl << endl;
    cout << "\t\t\t\t\t4 - LISTAR JORNADA EMPLEADO POR MES. " << endl << endl;
    cout << "\t\t\t\t\t5 - LISTAR JORNADA POR FECHA TODOS LOS EMPLEADOS. " << endl << endl;
    cout << "\t\t\t\t\t0 - VOLVER. " << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    cout << "\t\t\t\t\tSELECCIONE OPCION: ";
    cin  >> opcion;
    rlutil::locate(60,17);
    if(opcion >= 1 && opcion < 6){
        system("cls");
    }
    switch(opcion){
        case 1: mostrarActivos(); //LISTAR EMPLEADOS ACTIVOS
            break;
        case 2: mostrarEliminados(); //LISTAR EMPLEADOS DADOS DE BAJA
            break;
        case 3: mostrarEmpleado();
            break;
        case 4: mostrarJorEmpXMes();
            break;
        case 5: mostrarJorXFec();
            break;
        case 0 : cout << endl << endl << "\t\t\t\t\t¿Confirma salir? (S/N) ";
                cin >> confirmarSalida;
                if (tolower(confirmarSalida) == 's'){
                    system("cls");
                    //MenuAdministrador();
                }
            break;
        default : rlutil::locate(41,21);
                cout << "OPCION INVALIDA!!!" << endl << endl;
                system("pause > nul");
                system("cls");
            break;
    }
}

horas_A_minutos(int hora){

return hora*60;

}

void guardarFichada(int legajo){

    FechaHora hora;
    Empleados empleado;
    Jornada aux;
    float fin=0;
    bool salir=0;
    for(int pos=0;pos<aux.contarRegistros();pos++){
        aux.leerDeDisco(pos);
        //cout<<pos<<endl;
        //system("pause");
        if(hora.getAnio()==aux.getFecha().getAnio()&&
           hora.getMes()==aux.getFecha().getMes()&&
           hora.getDia()==aux.getFecha().getDia()&&
           legajo==aux.getLegajo().getleg()){
            aux.setHoraSalida(hora);
            int mnSalida=aux.getHoraSalida().getMinuto()+horas_A_minutos(aux.getHoraSalida().getHora());
            int mnEntrada=aux.getHoraEntrada().getMinuto()+horas_A_minutos(aux.getHoraEntrada().getHora());
            fin=(mnSalida-mnEntrada)/60;
            if((mnSalida-mnEntrada)%60>29){
                fin+=0.5;
            }
            aux.setHoraTotal(fin);
            aux.guardarEnDisco(pos);
            cout<<"SALIDA GUARDADA"<<endl;
            system("pause");
            cout<<endl<<endl<<aux.getFecha().getDia()<<"/"<<aux.getFecha().getMes()<<"/"<<aux.getFecha().getAnio()<<endl
            <<"legajo: "<<aux.getLegajo().getleg()<<endl
            <<"Entrada: "<<aux.getHoraEntrada().getHora()<<":"<<aux.getHoraEntrada().getMinuto()<<endl
            <<"Salida: "<<aux.getHoraSalida().getHora()<<":"<<aux.getHoraSalida().getMinuto()<<endl
            <<"Total: "<<aux.getHoraTotal()<<endl
            <<"Estado: "<<aux.getEstado()<<endl;
            system("pause");
            salir=1;
           }
    }
    if(salir==0){
        empleado.LeerDeDisco(buscarEmpleado(legajo));
        Jornada jornada(hora,empleado,hora,hora,fin);
        jornada.guardarEnDisco();
        cout<<"ENTRADA GUARDADA"<<endl;
        system("pause");
        cout<<endl<<endl<<jornada.getFecha().getDia()<<"/"<<jornada.getFecha().getMes()<<"/"<<jornada.getFecha().getAnio()<<endl
        <<"legajo: "<<jornada.getLegajo().getleg()<<endl
        <<"Entrada: "<<jornada.getHoraEntrada().getHora()<<":"<<jornada.getHoraEntrada().getMinuto()<<endl
        <<"Salida: "<<jornada.getHoraSalida().getHora()<<":"<<jornada.getHoraSalida().getMinuto()<<endl
        <<"Total: "<<jornada.getHoraTotal()<<endl
        <<"Ausente: "<<jornada.getAusente()<<endl
        <<"Estado: "<<jornada.getEstado()<<endl;
        system ("pause");
    }

}

void Leg_pin_incorrecto(){
    cout<<endl;
    cout<<"\t\t\t\t ========================="<<endl;
    cout<<"\t\t\t\t| Legajo o PIN incorrecto |"<<endl;
    cout<<"\t\t\t\t ========================="<<endl;
    cout<<endl;cout<<endl;cout<<endl;
    cout<<"\t\t\t\t----------------------------------"<<endl;
    cout<<"\t\t\t\t|";
    cout << system ("pause");
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
rlutil::setColor(rlutil::WHITE);
cin>>leg;
cout<<endl;
cout<<"\t\t\t\t PIN de admin -> ";
rlutil::setColor(rlutil::DARKGREY);
cin>>pin;
rlutil::setColor(rlutil::WHITE);
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
        cout << endl << "\t\t\t\t" << system("pause");
        }
    }
    if(activo!=true){
    Leg_pin_incorrecto();
    }
}

bool ValidarLegajoExistente(int legajo){

    Empleados obj;
    int pos = 0;
    while (obj.LeerDeDisco(pos++)){
        if ( obj.getleg() == legajo){
            cout << "\t\t\t\t\tEL LEGAJO YA ESTA UTILIZADO." << endl << endl;
            return false;
        }
    }
    return true;
}

bool ValidarDiaMes(int dia, int mes){

    if ( mes <= 0 || mes > 12){
        cout << endl << "\t\t\t\t\tNUMERO DE MES INVALIDO." << endl << endl;
        cout << endl << "\t\t\t\t" << system ("pause");
        return false;
    }
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        if ( dia <= 0 || dia > 30){
            cout << endl << "\t\t\t\t\tNUMERO DE MES INVALIDO." << endl << endl;
            cout << endl << "\t\t\t\t" << system ("pause");
            return false;
        }
    }
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        if ( dia <= 0 || dia > 31){
            cout << endl << "NUMERO DE MES INVALIDO." << endl << endl;
            cout << endl << "\t\t\t\t" << system ("pause");
            return false;
        }
    }
    if(mes == 2){
        if ( dia <= 0 || dia > 28){
            cout << endl << "NUMERO DE MES INVALIDO." << endl << endl;
            cout << endl << "\t\t\t\t" << system ("pause");
            return false;
        }
    }
    return true;
}

bool ValidarHoraMinutos(int hora, int minutos){

    if ( minutos <= 0 || minutos > 59){
        cout << endl << "\t\t\t\t\tMINUTOS INVALIDOS." << endl << endl;
        cout << endl << "\t\t\t\t" << system ("pause");
        return false;
    }
    if ( hora < 0 || hora > 59){
        cout << endl << "\t\t\t\t\HORA INVALIDA." << endl << endl;
        cout << endl << "\t\t\t\t" << system ("pause");
        return false;
    }
    return true;
}

bool ValidarActivo(int legajo){

    Empleados obj;
    int pos = 0;
    while (obj.LeerDeDisco(pos++)){
        if ( obj.getleg() == legajo){
            if(obj.getEliminado()){
                return true;
            }
        }
    }
    return false;
}




