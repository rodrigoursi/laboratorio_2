#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "fecha.h"
#include "Empleados.h"
#include "administrador.h"
#include "FUNCIONES.h"
///
int main(){

    //MenuPrincipal();
    Empleados obj;

    int pos = 0;
    while(obj.LeerDeDisco(pos++)){
        obj.mostrar();
    }
    return 0;
}
