#include "calendario.h"
#include "Empleados.h"
#include <cstring>
#include <string>
#include "FUNCIONES.h"
#include "rlutil.h"
#include "fecha.h"

#include <iostream>

Calendario::Calendario(FechaHora fecha, Empleados legajo, FechaHora horaEnt, FechaHora horaSalida){
    _fecha=fecha;
    _legajo=legajo;
    _horaEntrada=horaEnt;
    _horaSalida=horaSalida;
}

/// ///GET///

    FechaHora Calendario::getFecha(){return _fecha;}
    Empleados Calendario::getLegajo(){return _legajo;}
    FechaHora Calendario::getHoraEntrada(){return _horaEntrada;}
    FechaHora Calendario::getHoraSalida(){return _horaSalida;}

/// ///SET///

void Calendario::setFecha(FechaHora fecha){_fecha=fecha;}
void Calendario::setLegajo(Empleados legajo){_legajo=legajo;}
void Calendario::setHoraEntrada(FechaHora entrada){_horaEntrada=entrada;}
void Calendario::setHoraSalida(FechaHora salida){_horaSalida=salida;}

/// ///DISCO///

bool Calendario::guardarEnDisco(){
    FILE *p = fopen("datos/calendario.dat","ab");
        if(p==NULL){
            return false;
        }
        bool guardo= fwrite(this,sizeof (Calendario),1,p);
        fclose(p);
        return guardo;
}

bool Calendario::guardarEnDisco(int pos){
    FILE *p = fopen("datos/calendario.dat","rb+");
        if(p==NULL){
            return false;
        }
        fseek(p,pos*sizeof(Calendario),SEEK_SET);
        bool guardo= fwrite(this,sizeof (Calendario),1,p);
        fclose(p);
        return guardo;
}

bool Calendario::leerDeDisco(int pos){
    FILE *p=fopen("datos/calendario.dat","rb");
    if(p==NULL){
        false;
    }
    fseek(p,pos*sizeof(Calendario),SEEK_SET);
    bool ok= fread(this,sizeof(Calendario),1,p);
    fclose(p);
    return ok;
}

int  Calendario::contarRegistros(){
    FILE *p = fopen("datos/calendario.dat", "rb");
    if (p == NULL){
        return 0;
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Calendario);
    return cant_reg;
}

void cargarCalendario(){

    FechaHora fechaMes;
    Empleados empleado;
    int legajo, hora=0, minuto=0, dia,mes,anio;
    cout<<"COLOQUE EL LEGAJO DEL EMPLEADO Q DESEA CARGAR EL CALENDARIO DE TRABAJO...!"<<endl;
    cout<<"Legajo: ";cin>>legajo;
    if(ValidarLegajoExistente(legajo)==false){
        MenuAdministrador();
    }
    cout<<endl<<"COLOQUE LA FECHA DE INICIO DE LA CARGA DE HORARIO DEL EMPLEADO...!"<<endl;
    cout<<"DIA: ";cin>>dia;cout<<endl<<"MES: ";cin>>mes;
    cout<<endl<<"YEAR: ";cin>>anio;
    if(anio<fechaMes.getAnio()){
        cout<<"FECHA INVALIDA!";system ("pause");MenuAdministrador();
    }
    if(anio==fechaMes.getAnio()&&mes<fechaMes.getMes()){
        cout<<"FECHA INVALIDA!";system ("pause");MenuAdministrador();
    }
    if(anio==fechaMes.getAnio()&&mes==fechaMes.getMes()&&dia<=fechaMes.getDia()){
       cout<<"FECHA INVALIDA!";system ("pause");MenuAdministrador();
    }
    cout<<"COLOQUE EL HORARIO DEL EMPLEADO"<<endl;
    cout<<"HORA: ";cin>>hora; cout<<endl<<"MINUTO: ";cin>>minuto;
    cout<<endl<<"COLOQUE EL DIA DE LA SEMANA DEL DIA FRANCO/LIBRE DEL EMPLEADO ELIGIENDO UN NUMERO"<<endl;
    cout<<"0-(Domingo), 1-(Lunes), 2-(Martes), 3-(Miercoles), 4-(Jueves), 5-(Viernes), 6-(Sabado)"<<endl;
    int franco=0;
    int fechaFranco;
    cout<<"ESCRIBA EL NUMERO SELECCIONADO: ";cin>>franco;
    Calendario check;
    int pos=0;
    while(check.leerDeDisco(pos++)){
        if(!mes==1){
            if(check.getFecha().getAnio()==anio
               &&check.getFecha().getMes()==mes-1
               &&check.getLegajo().getleg()==legajo){
                cout<<"ESTE EMPLEADO YA FUE CARGADO PREVIAMENTE...!";
                system("pause");
                return;
            }
            if(check.getFecha().getAnio()==anio-1
                &&check.getFecha().getMes()==1
                &&check.getLegajo().getleg()==legajo){
                cout<<"ESTE EMPLEADO YA FUE CARGADO PREVIAMENTE...!";
                system("pause");
                return;
            }
        }
    }
    int tam=mesCantDias(mes);
    for(dia;dia<=tam;dia++){
        FechaHora fSalida, fec;
        empleado.LeerDeDisco(legajo);
        if(diaSemana(dia,mes,anio)!=franco){
            fSalida.setHora(hora+empleado.getcargaHoraria()); fSalida.setMinuto(minuto);
            fec.setDia(dia); fec.setMes(mes); fec.setAnio(anio); fec.setHora(hora);fec.setMinuto(minuto);
        }
        else{
            fSalida.setHora(-1);
            fec.setDia(dia); fec.setMes(mes); fec.setAnio(anio); fec.setHora(-1);
        }
         Calendario calendario(fec,empleado,fec,fSalida);
         calendario.guardarEnDisco();
    }
    cout<<"HORARIO DE EMPLEADO CARGADO CON EXITO...!"<<endl;
    cout<<"SE GUARDO EL HORARIO DEL RESTO DEL MES.!"<<endl<<system("pause");
}

/*void actualizarCalendario(){

    FechaHora fecha;
    int anio=fecha.getAnio();
    int mes;
    if(fecha.getMes()==12){
        mes=1;
        anio++;
    } else mes=fecha.getMes()+1;
    int diasS=mesCantDias(mes);
    Empleados empleado;
    int pos=0;
    while(empleado.LeerDeDisco(pos++)){
        if(ValidarActivo(empleado.getleg())){
            Calendario calendario;
            int dias=mesCantDias(fecha.getMes());
            int hora=0,minuto=0;
            for(dias;dias>=1;dias--){
                int posicion=0;
                while(calendario.leerDeDisco(posicion++)){
                    if(calendario.getFecha().getAnio()==fecha.getAnio()
                       &&calendario.getFecha().getMes()==fecha.getMes()
                       &&calendario.getFecha().getDia()==dias
                       &&calendario.getLegajo().getleg()==empleado.getleg()){
                        hora=calendario.getHoraEntrada().getHora();
                        minuto=calendario.getHoraEntrada().getMinuto();
                        dias=-1;
                    }
                }
            }
            if(dias==-1){
              for(int dia=1;dia<=diasS;dia++){
                if(diaSemana(dia,mes,anio)=!franco){
                    FechaHora fSalida(dia,mes,anio,hora+empleado.getcargaHoraria(),minuto);
                    FechaHora fec(dia,mes,anio,hora,minuto);
                }
                else{
                    FechaHora fSalida(dia,mes,anio,-1,minuto);
                    FechaHora fec(dia,mes,anio,-1,minuto);
                }
                Calendario calen(fec,empleado,fec,fSalida);
                calen.guardarEnDisco();
                }
            }
        }
    }
    cout<<"PROCESO TERMINADO CORRECTAMENTE...!"<<endl<<system("pause");
}*/

void CalendarioDeHorarios(){
    char opcion;
    Empleados obj;
    char confirmarSalida;
    while(true){
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::cls();
        cout << "\t\t\t\t\t  *** MENU ADMINISTRADOR ***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - CARGAR NUEVO HORARIO. " << endl << endl;
        cout << "\t\t\t\t\t2 - EDITAR HORARIO. " << endl << endl;
        cout << "\t\t\t\t\t3 - ACTUALIZAR HORARIO. " << endl << endl;
        cout << "\t\t\t\t\t0 - VOLVER. " << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        cin  >> opcion;
        rlutil::locate(60,15);
        if(opcion >= 0 && opcion < 4){
            system("cls");
        }
        switch(opcion){
            case '1': // CARGAR NUEVO HORARIO
                break;
            case '2': // EDITAR HORA    RIO
                break;
            case '3': // ACTUALIZAR HORARIO
                break;
            case '0' : cout << endl << endl << "\t\t\t\t\t¿Confirma salir? (S/N) ";
                    cin >> confirmarSalida;
                    if (tolower(confirmarSalida) == 's'){
                        system("pause > nul");
                        system("cls");
                        MenuAdministrador();
                    }
                break;
        }
    }
}
