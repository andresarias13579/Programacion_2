#include <cstring>
#include <iostream>

using namespace std;
#include "Alumno.h"
#include "Presencial.h"
#include "Semiprecensial.h"
#include "Virtuales.h"
#include "Boleta.h"

Boleta::Boleta() {
    inicializar();
}
Boleta::~Boleta() {
    eliminar();
}
void Boleta::inicializar() {
    pboleta = nullptr;
}
void Boleta::eliminar() {
    if (pboleta ) delete pboleta;
}

void Boleta::asignaMemoria(char tipo) {
    if (tipo == 'P') {
        pboleta = new Presencial;
    }else if (tipo == 'S') {
        pboleta = new Semiprecensial;
    }else if (tipo == 'V') {
        pboleta = new Virtuales;
    }
}

void Boleta::lee(ifstream &arch) {
    pboleta->leeDatos(arch);
}
void Boleta::imprime(ofstream &arch) {
    pboleta->imprimeAlumno(arch);
}

bool Boleta::hayDato() {
    return pboleta != nullptr;
}

