#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "MetricaBasica.h"

MetricaBasica::MetricaBasica() {
    inicializa();
}

MetricaBasica::MetricaBasica(const MetricaBasica &metrica) {
    inicializa();
    *this = metrica;
}
MetricaBasica::~MetricaBasica() {
    elimina();
}
void MetricaBasica::inicializa() {
    espectadores_promedio = 0;
    horas_transmitidas = 0;
}
void MetricaBasica::elimina() {
    espectadores_promedio = 0;
    horas_transmitidas = 0;
}

void MetricaBasica::operator=(const MetricaBasica &metrica) {
    horas_transmitidas = metrica.horas_transmitidas;
    espectadores_promedio = metrica.espectadores_promedio;
    Metrica::operator=(metrica);
}

double MetricaBasica::get_horas_transmitidas() const {
    return horas_transmitidas;
}

void MetricaBasica::set_horas_transmitidas(const double horas_transmitidas) {
    this->horas_transmitidas = horas_transmitidas;
}

int MetricaBasica::get_espectadores_promedio() const {
    return espectadores_promedio;
}

void MetricaBasica::set_espectadores_promedio(const int espectadores_promedio) {
    this->espectadores_promedio = espectadores_promedio;
}

void MetricaBasica::leer(ifstream &arch) {
    Metrica::leer(arch);
    arch>>horas_transmitidas;
    arch.get();
    arch>>espectadores_promedio;
}

void MetricaBasica::imprimir(ofstream &arch) const {
    arch<<setw(7)<<"MB-";
    Metrica::imprimir(arch);
    arch<<setw(10)<<horas_transmitidas<<setw(10)<<espectadores_promedio<<"m"<<endl;
}
