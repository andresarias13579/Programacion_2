#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Nodo.h"
#include "Lista.h"

Lista::Lista() {
    inicializa();
}
Lista::~Lista() {
    elimina();
}
void Lista::inicializa() {
    lista = nullptr;
}
void Lista::elimina() {
    Nodo *sale;
    while (lista) {
        sale = lista;
        lista = lista->siguiente;
        delete sale;
    }
    inicializa();
}

void Lista::crear(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    Empleado dato;
    while (true) {
        arch>>dato;
        if (arch.eof()) break;
        insertar(dato);
    }
}

void Lista::insertar(const Empleado &dato) {
    Nodo *nuevo,*ant = nullptr,*recorrido = lista;
    nuevo = new Nodo;
    nuevo->empleado = dato;
    while (recorrido) {
        if (recorrido->empleado > dato) break;
        ant = recorrido;
        recorrido = recorrido->siguiente;
    }
    nuevo->siguiente = recorrido;
    if (ant) ant->siguiente = nuevo;
    else lista = nuevo;
    // char nom[100];
    // cout << nuevo->empleado.get_codigo()<<" "<<nuevo->empleado.get_nombre(nom)<<endl;
}

void Lista::imprimir(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    Nodo *recorrido = lista;
    while (recorrido) {
        arch << recorrido->empleado;
        recorrido = recorrido->siguiente;
    }
}

void Lista::imprimirRecursivo(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    imprimirR(arch,lista);
}

void Lista::imprimirR(ofstream &arch, Nodo *recorrido) {
    if (recorrido == nullptr) return;
    //si cambiamos el orden de las siguientes dos lineas puede imprimir al reves, osea desde el ultimo hacia el primero
    arch << recorrido->empleado;
    imprimirR(arch,recorrido->siguiente);
}
