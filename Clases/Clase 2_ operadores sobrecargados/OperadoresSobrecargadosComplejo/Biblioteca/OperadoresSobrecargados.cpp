#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Persona.h"
#include "Empleados.h"
#include "OperadoresSobrecargados.h"

void operator <<(struct Empleados &empleados, const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<nombArch<<endl;
        exit(1);
    }

    while (true) {

    }
}

void operator <<(const char *nombArchstruct,const struct Empleados &empleados);