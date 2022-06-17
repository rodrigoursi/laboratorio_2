#include <cstring>
#include <iostream>
using namespace std;
#include "Empleados.h"
#include "fecha.h"

///CONSTRUCTOR

Empleados::Empleados(int legajo,int _pin,string _nombre,string _apellido,int _dni,string _domicilio,string _localidad,string _provincia,string _pais,FechaHora fnac,string _genero,FechaHora ingreso,int carga_horaria,bool admin, bool act){

leg=legajo; pin=1234; strcpy(nombre, _nombre.c_str());strcpy(apellido, _apellido.c_str()); dni=_dni; strcpy(domicilio, _domicilio.c_str()); strcpy(localidad, _localidad.c_str()); strcpy(provincia, _provincia.c_str()); strcpy(pais, _pais.c_str());
fNacimiento=fnac; strcpy(genero, _genero.c_str()); fechaIngreso=ingreso; cargaHoraria=carga_horaria; adm=admin;}

Empleados::Empleados(){}
///GET


string Empleados::getnombre(){
    string nom;
    nom=nombre;
    return nom;}

string Empleados::getapellido(){
    string apell(apellido);
    return  apell;}

int Empleados::getleg(){return leg;}
int Empleados::getpin(){return pin;}
int Empleados::getdni(){return dni;}
string Empleados::getdomicilio(){string dom(domicilio); return dom;}
string Empleados::getlocalidad(){string loc(localidad); return loc;}
string Empleados::getprovincia(){string prov(provincia); return prov;}
string Empleados::getpais(){string p(pais); return p;}
FechaHora Empleados::getFnacimiento(){return fNacimiento;}
string Empleados::getgenero(){string gen(genero); return gen;}
FechaHora Empleados::getFechaIngreso(){return fechaIngreso;}
int Empleados::getcargaHoraria(){return cargaHoraria;}
bool Empleados::getRol(){return adm;}
bool Empleados::getEliminado(){return activo;}


///SETS
    void Empleados::setnombre(string nom){strcpy(nombre, nom.c_str());}
    void Empleados::setapellido(string ape){strcpy(apellido, ape.c_str());}
    void Empleados::setleg(int legajo){leg=legajo;}
    void Empleados::setpin(int p){pin=p;}
    void Empleados::setdni(int doc){dni=doc;}
    void Empleados::setdomicilio(string dom){strcpy(domicilio, dom.c_str());}
    void Empleados::setlocalidad(string loc){strcpy(localidad, loc.c_str());}
    void Empleados::setprovincia(string prov){strcpy(provincia, prov.c_str());}
    void Empleados::setpais(string p){strcpy(pais, p.c_str());}
    void Empleados::setFnacimiento(FechaHora nac){fNacimiento=nac;}
    void Empleados::setgenero(string g){strcpy(genero, g.c_str());}
    void Empleados::setcargaHoraria(int carga){cargaHoraria=carga;}
    void Empleados::setRol(bool admin){adm=admin;}
    void Empleados::setEliminado(bool on){activo=on;}


///METODO DE LA CLASE

int Empleados::contarRegistros(){
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

bool Empleados::LeerDeDisco(int nroRegistro){
    FILE *p = fopen("archivos/Empleados.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(Empleados), SEEK_SET);
    bool ok = fread(this, sizeof(Empleados), 1, p);
    fclose(p);
    return ok;
}

bool Empleados::GuardarEnDisco(){
    FILE *p = fopen("archivos/Empleados.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool guardo = fwrite(this, sizeof(Empleados), 1, p);
    fclose(p);
    return guardo;
}

bool Empleados::GuardarEnDisco(int nroRegistro){
    FILE *p = fopen("archivos/Empleados.dat", "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(Empleados), SEEK_SET);
    bool guardo = fwrite(this, sizeof(Empleados), 1, p);
    fclose(p);
    return guardo;
}

/// FUNCIONES DE LA CLASE

int buscar_empleados(int legajo){

/// REALIZAR LA FUNCION

}

bool EliminarEmpleado(){

/// REALIZAR LA FUNCION

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

//
/////FUNCIONES GLOBALES


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
/*int buscar_empleados(int pin){
    Empleados aux;
    int i = 0;
    int cantEmpleados = aux.contarRegistros();
    for(i=0; i<cantEmpleados; i++){
        aux.LeerDeDisco(i);
        if(aux.getpin() == pin){
            return i;
        }
    }
    return -1;
}*/
