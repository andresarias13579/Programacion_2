#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "MetricaBasica.h"
#include "MetricaCalidad.h"
#include "MetricaEngagement.h"
#include "Lista.h"

Lista::Lista() {
    inicializa();
}
void Lista::inicializa() {
    listaDoblementeLigada = nullptr;
}
Lista::~Lista() {
    eliminar();
}
void Lista::eliminar() {
    Nodo *sale ;
    while (listaDoblementeLigada != nullptr) {
        sale = listaDoblementeLigada;
        listaDoblementeLigada = listaDoblementeLigada->siguiente;
        delete sale;
    }
    inicializa();
}

void Lista::crear(ifstream &arch) {
    Metrica *metrica;
    int idStream;
    char tipo[20],c;
    while (true) {
        arch.getline(tipo, 20,',');
        if (arch.eof()) break;
        arch>>idStream>>c;
        if (strcmp(tipo,"ENGAGEMENT") == 0) metrica = new MetricaEngagement;
        if (strcmp(tipo,"BASIC") == 0) metrica = new MetricaBasica;
        if (strcmp(tipo,"QUALITY") == 0) metrica = new MetricaCalidad;
        metrica->leer(arch);
        insertar(metrica);
    }
}

void Lista::insertar(Metrica *metrica) {
    Nodo *nuevo,*anterior = nullptr,*recorrido = listaDoblementeLigada;
    nuevo = new Nodo;
    nuevo->metrica = metrica;
    char desc[100],desc2[100];
    while (recorrido) {
        if (metrica->tipoMetrica() < recorrido->metrica->tipoMetrica()
            or (metrica->tipoMetrica() == recorrido->metrica->tipoMetrica()
            and strcmp(metrica->get_descripcion(desc),recorrido->metrica->get_descripcion(desc2)) <0)) break; //aca la condicion de parada
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    nuevo->siguiente = recorrido;
    nuevo->anterior = anterior;
    if (anterior) anterior->siguiente = nuevo;
    else listaDoblementeLigada = nuevo;
    if (recorrido) recorrido->anterior = nuevo;
}

void Lista::imprimeLinea(ofstream &arch, char line) {
    for (int i = 0; i < 250; ++i) arch << line ;
    arch << endl;
}

void Lista::imprimirReporte(ofstream &arch) {
    Nodo *recorrido = listaDoblementeLigada;
    imprimeLinea(arch,'=');
    arch<<setw(100)<<"REPORTE DE METRICAS"<<endl;
    imprimeLinea(arch,'=');
    bool banderaEngagem = true, banderaQuality = true;
    int cantActivas = 0,cantExpiradas = 0;
    arch<<"[METIRCAS BASIC]"<<endl;
    while (recorrido) {
        if (banderaEngagem and recorrido->metrica->tipoMetrica()=='E') {
            imprimeLinea(arch,'-');
            arch<<"[METIRCAS ENGAGE]"<<endl;
            banderaEngagem = false;
        }
        if (banderaQuality and recorrido->metrica->tipoMetrica()=='Q') {
            imprimeLinea(arch,'-');
            arch<<"[METIRCAS QUALITY]"<<endl;
            banderaQuality = false;
        }
        recorrido->metrica->imprimir(arch);
        if (recorrido->metrica->get_estado()) cantActivas++;
        else cantExpiradas++;
        recorrido = recorrido->siguiente;
    }
    imprimeLinea(arch,'-');
    arch<<"[TOTAL] METRICAS ACTIVAS: "<<cantActivas<<" | METRICAS EXPIRADAS: "<<cantExpiradas<<endl;
    imprimeLinea(arch,'=');
}

void Lista::eliminaMetricasExpiradas() {
    Nodo *recorrido = listaDoblementeLigada,*sig = nullptr;
    while (recorrido) {
        sig = recorrido->siguiente;
        if (recorrido->metrica->get_estado() == false) {
            Nodo *anterior = recorrido->anterior;
            Nodo *siguiente = recorrido->siguiente;
            recorrido->anterior = nullptr;
            recorrido->siguiente = nullptr;
            if (anterior) anterior->siguiente = siguiente;
            else listaDoblementeLigada = siguiente;
            if (siguiente) siguiente->anterior = anterior;
            delete recorrido;
        }
        recorrido = sig;
    }
}
