#include <cstring>
#include <iostream>
using namespace std;
#include "Empleados.h"
#include "fecha.h"

///FUNCIONES DE CLASES

void Empleados::mostrar(){
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

//void Empleados::cargararchivo(){
//    FILE *p;
//    Empleados obj;
//    obj.cargar();
//    p=fopen("Empleados.dat","ab");
//    if(p==NULL){
//        cout<<"error de archivo"<<endl;
//    }
//    fwrite(&obj, sizeof obj, 1, p);
//    fclose(p);
//    cout<<"Empleado cargado con exito"<<endl;
//}
//
//void Empleados::mostrararchivo(){
//    FILE *p;
//    Empleados obj;
//    p=fopen("Empleados.dat","rb");
//    if(p==NULL){
//        cout<<"error de archivo"<<endl;
//    }
//    while(fread(&obj, sizeof obj, 1, p)==1){
//    obj.mostrar();
//    }
//    fclose(p);
//}
//
//
//
//bool Empleados::GuardarEnDisco(int nroRegistro){
//    FILE *p = fopen("Empleados.dat", "rb+");
//    if (p == NULL){
//        return false;
//    }
//    fseek(p, nroRegistro * sizeof(Empleados), SEEK_SET);
//    bool guardo = fwrite(this, sizeof(Empleados), 1, p);
//    fclose(p);
//    return guardo;
//}
//
/////FUNCIONES GLOBALES

int cantidad_registros_empleados(){
    FILE *p = fopen("Empleados.dat", "rb");
    if (p == NULL){
        return 0;
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Empleados);
    return cant_reg;
}
//
//void listar_empleados(){
//    Empleados aux;
//    int i = 0;
//    int cantEmpleados = cantidad_registros_empleados();
//    int cantidad = 0;
//    cout << "LISTADO DE EMPLEADOS" << endl;
//    cout << "----------------------------------" << endl;
//
//    for(i=0; i<cantEmpleados; i++){
//        aux.LeerDeDisco(i);
//        if (!aux.getEliminado()){
//        aux.mostrar();
//        cantidad++;
//        }
//    }
//    cout << "----------------------------------" << endl;
//    cout << "Total: " << cantidad<< " registros.";
//}
//
//
//
//void listar_empleados_x_PIN(){
//    int pin, nroRegistro;
//    cout << "PIN: ";
//    cin >> pin;
//
//    nroRegistro = buscar_empleados(pin);
//    if (nroRegistro >= 0){
//        Empleados reg;
//        reg.LeerDeDisco(nroRegistro);
//        cout << endl;
//    }
//    else{
//        cout << endl << "No existe el empleado";
//    }
//}
//
//
//
bool Empleados::LeerDeDisco(int nroRegistro){
    FILE *p = fopen("Empleados.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(Empleados), SEEK_SET);
    bool ok = fread(this, sizeof(Empleados), 1, p);
    fclose(p);
    return ok;
}
//
//bool Empleados::GuardarEnDisco(){
//    FILE *p = fopen("Empleados.dat", "ab");
//    if (p == NULL){
//        return false;
//    }
//    bool guardo = fwrite(this, sizeof(Empleados), 1, p);
//    fclose(p);
//    return guardo;
//}
//
int buscar_empleados(int pin){
    Empleados aux;
    int i = 0;
    int cantEmpleados = cantidad_registros_empleados();
    for(i=0; i<cantEmpleados; i++){
        aux.LeerDeDisco(i);
        if(aux.getpin() == pin){
            return i;
        }
    }
    return -1;
}
