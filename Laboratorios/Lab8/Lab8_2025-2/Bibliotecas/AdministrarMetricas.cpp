#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "AdministrarMetricas.h"

void AdministrarMetricas::cargarArchivo(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout <<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    listaDeMetricas.crear(arch);
}

void AdministrarMetricas::generarReporte(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout <<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    listaDeMetricas.imprimirReporte(arch);
}

void AdministrarMetricas::eliminarNodos() {
    listaDeMetricas.eliminaMetricasExpiradas();
}

void AdministrarMetricas::eliminarLista() {
    listaDeMetricas.eliminar();
}
