#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "MetricaEngagement.h"

MetricaEngagement::MetricaEngagement() {
    inicializa();
}
MetricaEngagement::~MetricaEngagement() {
    elimina();
}

MetricaEngagement::MetricaEngagement(const MetricaEngagement &metrica) {
    inicializa();
    *this = metrica;
}

void MetricaEngagement::inicializa() {
    mensajes_chat = 0;
    usuarios_unicos_chat = 0;
    clips_generados = 0;
}

void MetricaEngagement::elimina() {
    mensajes_chat = 0;
    usuarios_unicos_chat = 0;
    clips_generados = 0;
}

void MetricaEngagement::operator=(const MetricaEngagement &metrica) {
    mensajes_chat = metrica.mensajes_chat;
    usuarios_unicos_chat = metrica.usuarios_unicos_chat;
    clips_generados = metrica.clips_generados;
    Metrica::operator=(metrica);
}

int MetricaEngagement::get_mensajes_chat() const {
    return mensajes_chat;
}

void MetricaEngagement::set_mensajes_chat(const int mensajes_chat) {
    this->mensajes_chat = mensajes_chat;
}

int MetricaEngagement::get_usuarios_unicos_chat() const {
    return usuarios_unicos_chat;
}

void MetricaEngagement::set_usuarios_unicos_chat(const int usuarios_unicos_chat) {
    this->usuarios_unicos_chat = usuarios_unicos_chat;
}

int MetricaEngagement::get_clips_generados() const {
    return clips_generados;
}

void MetricaEngagement::set_clips_generados(const int clips_generados) {
    this->clips_generados = clips_generados;
}

void MetricaEngagement::leer(ifstream &arch) {
    char c;
    Metrica::leer(arch);
    arch>>mensajes_chat>>c>>usuarios_unicos_chat>>c>>clips_generados;
}

void MetricaEngagement::imprimir(ofstream &arch) const {
    arch<<setw(7)<<"ME-";
    Metrica::imprimir(arch);
    arch<<setw(10)<<mensajes_chat<<setw(10)<<usuarios_unicos_chat<<setw(10)<<clips_generados<<endl;
}
