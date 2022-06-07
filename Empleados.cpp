#include <cstring>
#include <iostream>
using namespace std;
#include "Empleados.h"

///GETS-------------------
std::string Empleados::getNombre(){
    std::string N(Nombre);
    return N;
}
std::string Empleados::getApellido(){
    std::string A(Apellido);
    return A;
}
std::string Empleados::getCargo(){
    std::string C(Cargo);
    return C;
}
int  Empleados::getDNI(){
    return DNI;
}
int  Empleados::getHoras_trabajo(){
    return Horas_trabajo;
}
int  Empleados::getHoras_extras(){
    return Horas_extras;
}
int  Empleados::getAusencias(){
    return Ausencias;
}
int  Empleados::getllegadas_tarde(){
    return llegadas_tarde;
}
int  Empleados::getPIN(){
    return PIN;
}
bool Empleados::getEliminado() const{
    return Eliminado;
}
///SETS-------------------
void Empleados::setNombre(std::string N){
    strcpy(Nombre, N.c_str());
}
void Empleados::setApellido(std::string A){
    strcpy(Apellido, A.c_str());
}
void Empleados::setCargo(std::string C){
    strcpy(Cargo, C.c_str());
}
void Empleados::setDNI(int D){
    DNI = D;
}
void Empleados::setHoras_trabajo(int H){
    Horas_trabajo = H;
}
void Empleados::setHoras_extras(int H){
    Horas_extras = H;
}
void Empleados::setAusencias(int A){
    Ausencias = A;
}
void Empleados::setllegadas_tarde(int L){
    llegadas_tarde = L;
}
void Empleados::setPIN(int P){
    PIN = P;
}
void Empleados::setEliminado(bool E){
    Eliminado = E;
}
///FUNCIONES DE CLASES
void Empleados::cargar(){
Empleados obj;
std::string apellido;
std::string nombre;
std::string cargo;
int DNI, Horas_trabajo, PIN;
cout<<"Cual es su nombre? --> ";
cin>>nombre;
obj.setNombre(nombre);
cout<<"Cual es su apellido? --> ";
cin>>apellido;
obj.setApellido(apellido);
cout<<"Cual es su DNI? --> ";
cin>>DNI;
obj.setDNI(DNI);
cout<<"Cual es su cargo? --> ";
cin>>cargo;
obj.setCargo(cargo);
cout<<"Cuantas son tus horas de trabajo? --> ";
cin>>Horas_trabajo;
obj.setHoras_trabajo(Horas_trabajo);
cout<<"Cual es su PIN? --> ";
cin>>PIN;
obj.setPIN(PIN);
}

void Empleados::mostrar(){
Empleados obj;
cout<<endl;
cout<<"-----------------------------"<<endl;
cout<<"Su nombre --> ";
cout<<obj.getNombre()<<endl;
cout<<"Su apellido --> ";
cout<<obj.getApellido()<<endl;
cout<<"Su DNI --> ";
cout<<obj.getDNI()<<endl;
cout<<"Su cargo --> ";
cout<<obj.getCargo()<<endl;
cout<<"Horas de trabajo --> ";
cout<<obj.getHoras_trabajo()<<endl;
cout<<"Horas extras trabajadas --> ";
cout<<obj.getHoras_extras()<<endl;
cout<<"Cantidad de dias ausentes --> ";
cout<<obj.getAusencias()<<endl;
cout<<"Cantidad de minutos tarde --> ";
cout<<obj.getllegadas_tarde()<<endl;
cout<<"Su PIN --> ";
cout<<obj.getPIN();
cout<<endl;
cout<<"-----------------------------"<<endl;
}

void Empleados::cargararchivo(){
    FILE *p;
    Empleados obj;
    obj.cargar();
    p=fopen("Empleados.dat","ab");
    if(p==NULL){
        cout<<"error de archivo"<<endl;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    cout<<"Empleado cargado con exito"<<endl;
}

void Empleados::mostrararchivo(){
    FILE *p;
    Empleados obj;
    p=fopen("Empleados.dat","rb");
    if(p==NULL){
        cout<<"error de archivo"<<endl;
    }
    while(fread(&obj, sizeof obj, 1, p)==1){
    obj.mostrar();
    }
    fclose(p);
}

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

bool Empleados::GuardarEnDisco(){
    FILE *p = fopen("Empleados.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool guardo = fwrite(this, sizeof(Empleados), 1, p);
    fclose(p);
    return guardo;
}

bool Empleados::GuardarEnDisco(int nroRegistro){
    FILE *p = fopen("Empleados.dat", "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(Empleados), SEEK_SET);
    bool guardo = fwrite(this, sizeof(Empleados), 1, p);
    fclose(p);
    return guardo;
}

///FUNCIONES GLOBALES
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

void listar_empleados(){
    Empleados aux;
    int i = 0;
    int cantEmpleados = cantidad_registros_empleados();
    int cantidad = 0;
    cout << "LISTADO DE EMPLEADOS" << endl;
    cout << "----------------------------------" << endl;

    for(i=0; i<cantEmpleados; i++){
        aux.LeerDeDisco(i);
        if (!aux.getEliminado()){
        aux.mostrar();
        cantidad++;
        }
    }
    cout << "----------------------------------" << endl;
    cout << "Total: " << cantidad<< " registros.";
}

int buscar_empleados(int pin){
    Empleados aux;
    int i = 0;
    int cantEmpleados = cantidad_registros_empleados();
    for(i=0; i<cantEmpleados; i++){
        aux.LeerDeDisco(i);
        if(aux.getPIN() == pin){
            return i;
        }
    }
    return -1;
}

void listar_empleados_x_PIN(){
    int pin, nroRegistro;
    cout << "PIN: ";
    cin >> pin;

    nroRegistro = buscar_empleados(pin);
    if (nroRegistro >= 0){
        Empleados reg;
        reg.LeerDeDisco(nroRegistro);
        cout << endl;
    }
    else{
        cout << endl << "No existe el estudiante";
    }
}

bool editar_empleados(){
    int pin, nroRegistro;
    bool ok = false;
    string Nuevo_cargo;
    string Nuevo_horario;
    cout << "Legajo: ";
    cin >> pin;

    nroRegistro = buscar_empleados(pin);
    if (nroRegistro >= 0){
        Empleados reg;
        reg.LeerDeDisco(nroRegistro);
        int Nuevo_horario;
        char Nuevo_cargo[20];
        cout << endl;
        cout << endl << endl;
        cout << "Nuevo cargo: ";
        cin >> Nuevo_cargo;
        cout << "Nuevo horario: ";
        cin >> Nuevo_horario;
        reg.setCargo(Nuevo_cargo);
        reg.setHoras_trabajo(Nuevo_horario);
        ok = reg.GuardarEnDisco(nroRegistro);
}
    return ok;
}

bool eliminar_empleado(){
  int pin, nroRegistro;
  bool ok = false;
  char confirmacion;

  cout << "PIN: ";
  cin >> pin;

  nroRegistro = buscar_empleados(pin);
  if (nroRegistro >= 0) {
    Empleados reg;
    reg.LeerDeDisco(nroRegistro);
    cout << endl;
    cout << endl << endl;
    if (reg.getEliminado()) {
      cout << "El empleado esta eliminado, desea restaurarlo ? S/N" << endl;
    }
    else {
      cout << "Esta seguro de que lo quiere eliminarlo? S/N" << endl;
    }

    cin >> confirmacion;

    if (confirmacion == 'S' || confirmacion == 's') {
      reg.setEliminado(!reg.getEliminado());
      ok = reg.GuardarEnDisco(nroRegistro);
    }
    else {
      ok = true;
    }


  }
  else {
    cout << "No existe un empleado con ese PIN..." << endl;
  }

  return ok;
}

///FUNCION MENU FICHAR (FALTA MEJORAR)
void Empleados::menu_FICHAR(){
Empleados obj;
int DNI;
int PIN;
cout<<"---- MENU FICHAR ----"<<endl;
cout<<"INGRESE SU NUMERO DE PIN -> ";
cin>>PIN;
int i = 0;
int cantEmpleados = cantidad_registros_empleados();
int buscar_empleados(PIN);
        for(i=0; i<cantEmpleados; i++){
        obj.LeerDeDisco(i);
            if(obj.getPIN() == pin){
            return i;
            }
        }
    return -1;
}

