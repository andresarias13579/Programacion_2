#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesAuxiliares.h"

void leeDatosExactos(int *&datos,int &numDatos,const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        exit(1);
    }
    int buffer[100],dato;
    numDatos = 0;
    while (true) {
        arch>>dato;
        if (arch.eof()) break;
        buffer[numDatos] = dato;
        numDatos++;
    }
    datos = new int[numDatos];
    for (int i=0;i<numDatos;i++) {
        datos[i] = buffer[i];
    }
}

void imprimirDatos(int *datos,int numDatos,const char*nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        exit(1);
    }
    for (int i = 0; i < numDatos; ++i) {
        cout<<setw(5)<<datos[i];
    }
}
