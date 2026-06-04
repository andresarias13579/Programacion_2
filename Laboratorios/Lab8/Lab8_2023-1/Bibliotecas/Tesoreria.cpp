#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"
#include "Tesoreria.h"

void Tesoreria::cargaescalas(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    Escala escala;
    int numEscalas=0;
    while (true) {
        escala.leeEscala(arch);
        if (arch.eof()) break;
        lescala[numEscalas]=escala;
        // cout<<lescala[numEscalas].get_codigo()<<"  "<<
        //     lescala[numEscalas].get_precio()<<endl;
        numEscalas++;
    }
}

void Tesoreria::cargaalumnos(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    Presencial presencial;
    Semipresencial semipresencial;
    Virtual virtuaal;
    int numVirtuaal=0,numPresencial = 0, numSemi = 0;
    char tipoAlum;
    while (true) {
        arch>>tipoAlum;
        if (arch.eof()) break;
        arch.get();
        if (tipoAlum=='P') {
            presencial.leePresencial(arch);
            lpresencial[numPresencial]=presencial;
            numPresencial++;
        }else if (tipoAlum=='S') {
            semipresencial.leeSemipresencial(arch);
            lsemipresencial[numSemi]=semipresencial;
            numSemi++;
        }else if (tipoAlum=='V') {
            virtuaal.leeVirtual(arch);
            lvirtual[numVirtuaal]=virtuaal;
            numVirtuaal++;
        } else while (arch.get()!='\n');
    }
}

void Tesoreria::actualiza(int creditos) {
    for (int i = 0; lpresencial[i].get_codigo(); ++i) {
        double costoEscala = buscarMontoEscala(lescala,lpresencial[i].get_escala());
        double monto = costoEscala*creditos;
        lpresencial[i].set_total(monto);
        lpresencial[i].actualizar(monto);
    }
    for (int i = 0; lsemipresencial[i].get_codigo(); ++i) {
        double costoEscala = buscarMontoEscala(lescala,lsemipresencial[i].get_escala());
        double monto = costoEscala*creditos;
        lsemipresencial[i].set_total(monto);
        lsemipresencial[i].actualizar(monto);
    }
    for (int i = 0; lvirtual[i].get_codigo(); ++i) {
        double costoEscala = buscarMontoEscala(lescala,lvirtual[i].get_escala());
        double monto = costoEscala*creditos;
        lvirtual[i].set_total(monto);
        lvirtual[i].actualizar(monto);
    }
}

double Tesoreria::buscarMontoEscala(Escala *escalas,int codEscala) {
    for (int i = 0; lpresencial[i].get_codigo(); ++i) {
        if (lescala[i].get_codigo() == codEscala)
            return lescala[i].get_precio();
    }
    return 0;
}

void Tesoreria::imprime(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    arch<<"Codigo"<<setw(15);
    for (int i = 0; lpresencial[i].get_codigo(); ++i) {

    }
}
