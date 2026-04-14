#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#define NO_ENCONTRADO -1

using namespace std;
#include "Estructuras.h"
#include "OperadoresSobrecargados.h"
#include "FuncionesAuxiliares.h"

void cargar_faltas_de_los_conductores(struct Faltas &faltas) {
    faltas.conductores += "ArchivoDeDatos/conductores.csv";
    faltas.infracciones += "ArchivoDeDatos/infracciones.csv";
    faltas.placas = new char**[faltas.conductores.cantidad+1]{};
    faltas.capacidades = new int[faltas.conductores.cantidad+1]{};
    ifstream arch("ArchivoDeDatos/faltas.csv",ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO FALTAS"<<endl;
        exit(1);
    }
    leemosArchivoFaltas(arch,faltas.conductores.dnis,faltas.infracciones.codigos,faltas.placas,
        faltas.capacidades,faltas.conductores.cantidad,faltas.infracciones.cantidad);
}
void leemosArchivoFaltas(ifstream &arch,int *arrDnis,int *arrCodInfra,char ***&arrPlacas,int *&arrCapacidades,int numConductores,
    int numInfracciones) {
    int dni,codInfra,idConductor,idInfraccion;
    char *placa,fecha[15];
    while (true) {
        arch>>dni;
        if (arch.eof()) break;
        arch.get();
        placa = leeCadenaExacta(arch,';');
        arch.getline(fecha,15,';');
        arch>>codInfra;
        idConductor = buscamosID(dni,arrDnis,numConductores);
        idInfraccion = buscamosID(codInfra,arrCodInfra,numInfracciones);
        if (idConductor != NO_ENCONTRADO and idInfraccion != NO_ENCONTRADO) {
            insertarPlacas(idConductor,arrPlacas[idConductor],arrCapacidades[idConductor],placa);
        }
    }
}
void insertarPlacas(int idConductor,char **&arrPlacas,int &capacidad,char *placa) {
    int numDatos = 0;
    // arrPlacas = nullptr;
    // capacidad = 0;
    numDatos = numPlacas(arrPlacas);
    if (validarPlaca(placa,arrPlacas,numDatos)) {
        if (numDatos == capacidad) incrementamosMemoria(arrPlacas,capacidad,numDatos);
        arrPlacas[numDatos] = placa;
        numDatos++;
    }
}
bool validarPlaca(char *placa,char **arrPlacas,int numPlacas) {
    for (int i = 0; i < numPlacas; ++i) {
        if (strcmp(placa,arrPlacas[i]) == 0) return false;
    }
    return true;
}
void incrementamosMemoria(char **&arrPlacas,int &capacidad,int &numDatos) {
    if (capacidad == 0) {
        arrPlacas = new char*[2]{};
        capacidad = 2;
        // numDatos = 1;
    }else {
        char **ptrAux;
        ptrAux = new char*[capacidad + 2]{};
        capacidad += 2;
        for (int i = 0; i < numDatos; ++i) ptrAux[i] = arrPlacas[i];
        delete [] arrPlacas;
        arrPlacas = ptrAux;
    }
}
void imprimir_faltas_de_los_conductores(struct Faltas faltas) {
    ofstream arch("ArchivoDeReporte/ReporteDeFaltas.txt",ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO REPORTE"<<endl;
        exit(1);
    }
    imprimirLinea(arch,'=');
    arch<<setw(3)<<"DNI"<<setw(10)<<"CLIENTE"<<setw(40)<<" "<<"CANT. VEHICULOS"<<endl;
    imprimirLinea(arch,'-');
    mostramosConductores(arch,faltas.conductores.dnis,faltas.conductores.nombres,faltas.conductores.cantidad,
        faltas.placas);
    imprimirLinea(arch,'=');
}
void mostramosConductores(ofstream &arch,int *arrDnis,char **arrNombres,int numConductores, char ***arrPlacas) {
    for (int i = 0; i < numConductores; ++i) {
        int numeroPlacas = numPlacas(arrPlacas[i]);
        arch<<arrDnis[i]<<"     "<<left<<setw(50)<<arrNombres[i]<<right<<setw(10)<<numeroPlacas<<endl;
    }
}

int buscamosID(int dni,int *arrDnis,int numConductores) {
    for (int i = 0; i < numConductores; ++i) {
        if (dni == arrDnis[i]) return i;
    }
    return NO_ENCONTRADO;
}
int numPlacas(char **arrPlacas) {
    if (arrPlacas == nullptr) return 0;
    else {
        int i = 0;
        while (arrPlacas[i] != nullptr) i++;
        return i;
    }
}
void imprimirLinea(ofstream &arch,char caracter) {
    for (int i = 0; i < 150; ++i) {
        arch<<caracter;
    }
    arch<<endl;
}