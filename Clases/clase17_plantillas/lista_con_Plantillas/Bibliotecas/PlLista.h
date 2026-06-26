//
// Created by Andres on 25/06/2026.
//

#ifndef LISTA_CON_PLANTILLAS_PLLISTA_H
#define LISTA_CON_PLANTILLAS_PLLISTA_H
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "PlNodo.h"

template <typename T>
class PlLista {
private:
    PlNodo<T> *lista;
    void imprimirR(ofstream &arch,PlNodo<T> *nodo);
public:
    PlLista();
    ~PlLista();
    void inicializa();
    void eliminar();
    void crear(const char *nombArch);
    void insertar(const T &dato);
    void imprimir(const char *nombArch);
};

template <typename T>
PlLista<T>::PlLista() {
    inicializa();
}
template <typename T>
void PlLista<T>::inicializa() {
    lista = nullptr;
}
template <typename T>
PlLista<T>::~PlLista() {
    eliminar();
}
template <typename T>
void PlLista<T>::eliminar() {
    PlNodo<T> *sale;
    while (lista) {
        sale = lista;
        lista = lista->siguiente;
        delete sale;
    }
    inicializa();
}

template<typename T>
void PlLista<T>::crear(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    T datito;
    while (true) {
        arch >> datito;
        if (arch.eof()) break;
        insertar(datito);
    }
}

template <typename T>
void PlLista<T>::insertar(const T &dato) {
    PlNodo<T> *recorrido = lista, *anterior = nullptr,*nuevo;
    nuevo = new PlNodo<T>;

    nuevo->dato = dato;

    while (recorrido) {
        if (dato < recorrido->dato) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    nuevo->siguiente = recorrido;
    if (anterior) anterior->siguiente = nuevo;
    else lista = nuevo;
}
template <typename T>
void PlLista<T>::imprimir(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    PlNodo<T> *recorrido = lista;
    imprimirR(arch,recorrido);
}

template<typename T>
void PlLista<T>::imprimirR(ofstream &arch, PlNodo<T> *nodo) {
    if (nodo == nullptr) return;
    arch << nodo->dato ;
    arch << endl;
    imprimirR(arch,nodo->siguiente);
}

#endif //LISTA_CON_PLANTILLAS_PLLISTA_H
