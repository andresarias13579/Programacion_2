#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "Estructuras.h"
#include "OperadoresSobrecargados.h"

void operator += (struct Conductores &conductores, const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    leemosArchivoConductores(arch, conductores.dnis, conductores.nombres,conductores.cantidad);
}
void leemosArchivoConductores(ifstream &arch, int *&arrDni, char **&arrNombres,int &numConductores) {
    int bufferDni[150]{};
    char *bufferNombres[150]{};
    numConductores = 0;
    while (true) {
        arch>>bufferDni[numConductores];
        if (arch.eof()) break;
        arch.get();
        bufferNombres[numConductores] = leeCadenaExacta(arch,'\n');
        // cout<<bufferDni[numConductores]<<setw(10)<<" "<<bufferNombres[numConductores]<<endl;
        numConductores++;
    }
    arrDni = new int[numConductores+1];
    arrNombres = new char*[numConductores+1];
    for (int i = 0; i < numConductores; ++i) {
        arrDni[i] = bufferDni[i];
        arrNombres[i] = bufferNombres[i];
    }
}

void operator += (struct Infracciones &infracciones, const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    leemosArchivoInfracciones(arch,infracciones.codigos,infracciones.descripciones,infracciones.tipos,
        infracciones.valores,infracciones.cantidad);
}
void leemosArchivoInfracciones(ifstream &arch,int *&arrCodigos,char **&arrDescripciones,char **&arrTipos,
        double *&arrValores,int &numInfracciones) {
    int bufferCodigos[150]{};
    char *bufferDescripciones[150]{}, *bufferTipos[150]{};
    double bufferValores[150]{};
    numInfracciones = 0;
    while (true) {
        arch>>bufferCodigos[numInfracciones];
        if (arch.eof()) break;
        arch.get();
        bufferDescripciones[numInfracciones] = leeCadenaExacta(arch,';');
        bufferTipos[numInfracciones] = leeCadenaExacta(arch,';');
        arch>>bufferValores[numInfracciones];
        // cout<<setw(10)<<bufferCodigos[numInfracciones]<<setw(150)<<bufferDescripciones[numInfracciones]<<setw(15)
        //     <<bufferTipos[numInfracciones]<<setw(10)<<bufferValores[numInfracciones]<<endl;
        numInfracciones++;
    }
    arrCodigos = new int[numInfracciones+1];
    arrDescripciones = new char*[numInfracciones+1];
    arrTipos = new char*[numInfracciones+1];
    arrValores = new double[numInfracciones+1];
    for (int i = 0; i < numInfracciones; ++i) {
        arrCodigos[i] = bufferCodigos[i];
        arrDescripciones[i] = bufferDescripciones[i];
        arrTipos[i] = bufferTipos[i];
        arrValores[i] = bufferValores[i];
    }
}

char *leeCadenaExacta(ifstream &arch,char delimitador) {
    char *ptrAux, cadena[500];
    arch.getline(cadena,500,delimitador);
    if (arch.eof()) return nullptr;
    ptrAux = new char[strlen(cadena)+1];
    strcpy(ptrAux,cadena);
    return ptrAux;
}
