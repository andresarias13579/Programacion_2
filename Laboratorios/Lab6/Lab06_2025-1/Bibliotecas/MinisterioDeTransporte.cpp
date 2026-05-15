#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

#define NO_ENCONTRADO -1

using namespace std;
#include "MinisterioDeTransporte.h"

MinisterioDeTransporte::MinisterioDeTransporte() {
    inicializar();
}

MinisterioDeTransporte::~MinisterioDeTransporte() {
    liberar();
}

void MinisterioDeTransporte::liberar() {
    if (infracciones) delete [] infracciones;
}

void MinisterioDeTransporte::inicializar() {
    infracciones = nullptr;
    numEmp = 0;
    numInf = 0;
}

void MinisterioDeTransporte::operator < (const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    Infraccion buffer[200];
    while (true) {
        arch>>buffer[numInf];
        if (arch.eof()) break;
        numInf++;
    }
    infracciones = new Infraccion[numInf];
    for (int i = 0; i < numInf; i++) {
        infracciones[i] = buffer[i];
    }
}

void MinisterioDeTransporte::operator <= (const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    while (true) {
        arch>>empresas[numEmp];
        if (arch.eof()) break;
        numEmp++;
    }
}

void MinisterioDeTransporte::operator <<= (const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    class Multa infraccionCometida;
    while (true) {
        int IDempresa;
        double multaAsignada;
        char plaquita[10];
        arch>>infraccionCometida;
        if (arch.eof()) break;
        multaAsignada = buscarMulta(infraccionCometida.get_codigo_infraccion());
        infraccionCometida.set_multa(multaAsignada);
        infraccionCometida.get_placa(plaquita);
        IDempresa = buscarEmpresa(plaquita);
        if (IDempresa != NO_ENCONTRADO) empresas[IDempresa] += infraccionCometida;
    }
}

double MinisterioDeTransporte::buscarMulta(int codInfra) {
    for (int i = 0; i < numInf; i++) {
        if (codInfra==infracciones[i].get_codigo()) return infracciones[i].get_multa();
    }
    return NO_ENCONTRADO;
}

int MinisterioDeTransporte::buscarEmpresa(const char *placa) {
    for (int i = 0; i < numEmp; i++) {
        if (tieneLaPlaca(empresas[i],placa)) return i;
    }
    return NO_ENCONTRADO;
}

bool MinisterioDeTransporte::tieneLaPlaca(Empresa &empresa,const char *placa) {
    for (int i = 0; i < empresa.get_num_placas(); ++i) {
        char plaquita[10];
        empresa.getPlacaI(plaquita,i);
        if (strcmp(placa,plaquita) == 0) return true;
    }
    return false;
}

void MinisterioDeTransporte::operator >> (const char*nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    arch<<setw(90)<<"MINISTERIO DE TRANSPORTE"<<endl;
    imprimeLinea(arch,'=');
    arch<<setw(90)<<"TABLA DE INFRACCIONES"<<endl;
    imprimeLinea(arch,'-');
    arch<<"      CODIGO  MULTA     GRAVEDAD            DESCRIPCION"<<endl;
    imprimeLinea(arch,'-');
    for (int i = 0; i < numInf; i++) arch<<infracciones[i];
    imprimeLinea(arch,'=');
    arch<<setw(90)<<"RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO"<<endl;
    imprimeLinea(arch,'-');
    arch<<"    DNI              NOMBRE                            PLACAS DE SUS VEHICULOS"<<endl;
    imprimeLinea(arch,'-');
    for (int i = 0; i < numEmp; i++) arch<<empresas[i];
    imprimeLinea(arch,'=');
}

void MinisterioDeTransporte::imprimeLinea(ofstream &arch,char line) {
    for (int i = 0; i < 250; i++) arch<<line;
    arch<<endl;
}
