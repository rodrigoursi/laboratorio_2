#include <iostream>
#include <cstring>
#include "Empleados.h"
using namespace std;
///SETS-------------------
///GETS-------------------

//void Empleados::cargar(){
//Empleados obj;
//cout<<"Cual es su nombre? --> ";
//cin>>obj.setNombre();
//cout<<"Cual es su apellido? --> ";
//cin>>obj.setApellido();
//cout<<"Cual es su DNI? --> ";
//cin>>obj.setDNI();
//cout<<"Cual es su cargo? --> ";
//cin>>obj.setCargo();
//cout<<"Cuantas son tus horas de trabajo? --> ";
//cin>>obj.setHoras_trabajo();
//cout<<"Cual es su PIN? --> ";
//cin>>obj.setPIN();
//}
//
//void Empleados::mostrar(){
//Empleados obj;
//cout<<endl;
//cout<<"Su nombre --> ";
//cout<<obj.getNombre<<endl;
//cout<<"Su apellido --> ";
//cout<<obj.getApellido<<endl;
//cout<<"Su DNI --> ";
//cout<<obj.getDNI<<endl;
//cout<<"Su cargo --> ";
//cout<<obj.getCargo<<endl;
//cout<<"Horas de trabajo --> ";
//cout<<obj.getHoras_trabajo<<endl;
//cout<<"Horas extras trabajadas --> ";
//cout<<obj.getHoras_extras<<endl;
//cout<<"Cantidad de dias ausentes --> ";
//cout<<obj.getAusencias<<endl;
//cout<<"Cantidad de minutos tarde --> ";
//cout<<obj.getllegadas_tarde<<endl;
//cout<<"Su PIN --> ";
//cout<<obj.getPIN<<endl;
//}
//
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
//    cout<<"Empleado cargado con exito"<<endl
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
//bool Empleados::LeerDeDisco(int nroRegistro){
//    FILE *p = fopen("Empleados.dat", "rb");
//    if (p == NULL){
//        return false;
//    }
//    fseek(p, nroRegistro * sizeof(Empleados), SEEK_SET);
//    bool ok = fread(this, sizeof(Empleados), 1, p);
//    fclose(p);
//    return ok;
//}
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
//void Empleados::menu_FICHAR(){
//Empleados obj;
//int opc;
//cout<<"----MENU FICHAR----"<<endl;
//cout<<"1) FICHAR "<<endl;
//cin>>opc;
//system("cls");
//    switch(opc)
//    {
//        case 1: cout<<"Falta hacer"<<endl;
//        break;
//        default: cout<<"OPCION INCORRECTA. VUELVA A INGRESAR"<<endl;
//        break;
//    }
//}
//
//int cantidad_registros_empleados(){
//    FILE *p = fopen("Empleados.dat", "rb");
//    if (p == NULL){
//        return 0;
//    }
//    size_t bytes;
//    int cant_reg;
//
//    fseek(p, 0, SEEK_END);
//    bytes = ftell(p);
//    fclose(p);
//    cant_reg = bytes / sizeof(Empleados);
//    return cant_reg;
//}
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
//        if (!aux.getEliminado()) {
//          cout << aux.toString() << endl;
//          cantidad++;
//        }
//
//    }
//    cout << "----------------------------------" << endl;
//    cout << "Total: " << cantidad<< " registros.";
//}
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
//        cout << endl << reg.toString();
//    }
//    else{
//        cout << endl << "No existe el estudiante";
//    }
//}
//
//int buscar_empleados(int pin){
//    Empleados aux;
//    int i = 0;
//    int cantEmpleados = cantidad_registros_empleados();
//    for(i=0; i<cantEmpleados; i++){
//        aux.LeerDeDisco(i);
//        if(aux.getPIN() == pin){
//            return i;
//        }
//    }
//    return -1;
//}
//
//bool editar_empleados(){
//    int pin, nroRegistro;
//    bool ok = false;
//    string Nuevo_cargo;
//    string Nuevo_horario;
//    cout << "Legajo: ";
//    cin >> pin;
//
//    nroRegistro = buscar_empleados(pin);
//    if (nroRegistro >= 0){
//        Empleados reg;
//        reg.LeerDeDisco(nroRegistro);
//        cout << endl << reg.toString();
//        cout << endl << endl;
//        cout << "Nuevo cargo: ";
//        cin >> Nuevo_cargo;
//        cout << "Nuevo horario: ";
//        cin >> Nuevo_horario;
//        reg.setCargo(Nuevo_cargo);
//        reg.setHoras_trabajo(Nuevo_horario);
//        ok = reg.GuardarEnDisco(nroRegistro);
//    }
//    return ok;
//}
//
//bool eliminar_empleado(){
//  int pin, nroRegistro;
//  bool ok = false;
//  char confirmacion;
//
//  cout << "PIN: ";
//  cin >> pin;
//
//  nroRegistro = buscar_empleados(pin);
//  if (nroRegistro >= 0) {
//    Empleados reg;
//    reg.LeerDeDisco(nroRegistro);
//    cout << endl << reg.toString();
//    cout << endl << endl;
//    if (reg.getEliminado()) {
//      cout << "El empleado esta eliminado, desea restaurarlo ? S/N" << endl;
//    }
//    else {
//      cout << "Esta seguro de que lo quiere eliminarlo? S/N" << endl;
//    }
//
//    cin >> confirmacion;
//
//    if (confirmacion == 'S' || confirmacion == 's') {
//      reg.setEliminado(!reg.getEliminado());
//      ok = reg.GuardarEnDisco(nroRegistro);
//    }
//    else {
//      ok = true;
//    }
//
//
//  }
//  else {
//    cout << "No existe un empleado con ese PIN..." << endl;
//  }
//
//  return ok;
//}
//
//void Empleados::menuEmpleados(){
//Empleados obj;
//int opc;
//cout<<"----MENU CARGA DE EMPLEADOS----"<<endl;
//cout << "1 - Cargar nuevo empleado" << endl;
//cout << "2 - Editar empleado" << endl;
//cout << "3 - Listar todos los empleados" << endl;
//cout << "4 - Listar empleado por PIN" << endl;
//cout << "5 - Eliminar empleado" << endl;
//cin>>opc;
//system("cls");
//    switch(opc)
//    {
//        case 1:
//            obj.cargararchivo();
//        break;
//        case 2:
//            editar_empleados();
//        break;
//        case 3:
//            listar_empleados();
//        break;
//        case 4:
//            listar_empleados_x_PIN();
//        break;
//        case 5:
//            eliminar_empleado();
//        break;
//        default: cout<<"OPCION INCORRECTA. VUELVA A INGRESAR"<<endl;
//        break;
//    }
//}
