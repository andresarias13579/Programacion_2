#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "FuncionesAuxiliares.h"

void cargarAlumnos(int *&codigos,char **&nombres,const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout <<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<nombArch<<endl;
        exit(1);
    }
    int bufferCod[50]{},numDatos=0,cod;
    char *bufferNombre[50]{};
    while (true) {
        arch>>cod;
        if (arch.eof()) break;
        arch.get();
        fori
    }
}