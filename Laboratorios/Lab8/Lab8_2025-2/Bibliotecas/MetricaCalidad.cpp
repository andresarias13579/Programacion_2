#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "MetricaCalidad.h"

MetricaCalidad::MetricaCalidad() {
    inicializa();
}

MetricaCalidad::~MetricaCalidad() {
    elimina();
}

MetricaCalidad::MetricaCalidad(const MetricaCalidad &mca) {
    inicializa();
    *this = mca;
}

void MetricaCalidad::inicializa() {
    bitrate_promedio_kbps = 0;
    porcentaje_frames_perdidos = 0;
    fps_promedio = 0;
}

void MetricaCalidad::elimina() {
    bitrate_promedio_kbps = 0;
    porcentaje_frames_perdidos = 0;
    fps_promedio = 0;
}

void MetricaCalidad::operator=(const MetricaCalidad &mc) {
    bitrate_promedio_kbps = mc.bitrate_promedio_kbps;
    fps_promedio = mc.fps_promedio;
    porcentaje_frames_perdidos = mc.porcentaje_frames_perdidos;
    Metrica::operator=(mc);
}

int MetricaCalidad::get_bitrate_promedio_kbps() const {
    return bitrate_promedio_kbps;
}

void MetricaCalidad::set_bitrate_promedio_kbps(const int bitrate_promedio_kbps) {
    this->bitrate_promedio_kbps = bitrate_promedio_kbps;
}

double MetricaCalidad::get_porcentaje_frames_perdidos() const {
    return porcentaje_frames_perdidos;
}

void MetricaCalidad::set_porcentaje_frames_perdidos(const double porcentaje_frames_perdidos) {
    this->porcentaje_frames_perdidos = porcentaje_frames_perdidos;
}

int MetricaCalidad::get_fps_promedio() const {
    return fps_promedio;
}

void MetricaCalidad::set_fps_promedio(const int fps_promedio) {
    this->fps_promedio = fps_promedio;
}

void MetricaCalidad::leer(ifstream &arch) {
    Metrica::leer(arch);
    char c;
    arch>>bitrate_promedio_kbps>>c>>porcentaje_frames_perdidos>>c>>fps_promedio;
    arch.get();
}

void MetricaCalidad::imprimir(ofstream &arch) const {
    arch<<setw(7)<<"MQ-";
    Metrica::imprimir(arch);
    arch<<setw(10)<<bitrate_promedio_kbps<<setw(10)<<porcentaje_frames_perdidos<<setw(10)<<fps_promedio<<endl;
}

char MetricaCalidad::tipoMetrica() {
    return 'Q';
}
