#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Arbol.h"

Arbol::Arbol() {
    inicializar();
}
void Arbol::inicializar() {
    raiz = nullptr;
}
Arbol::~Arbol() {
    eliminar();
}
void Arbol::eliminar() {
    eliminarR(raiz);
}

void Arbol::eliminarR(Nodo *&arbol) {
    if (arbol) {
        eliminarR(arbol->izquierda);
        eliminarR(arbol->derecha);
        delete arbol;
    }
}

void Arbol::crear(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    Empleado dato;
    while (true) {
        arch >> dato;
        if (arch.eof()) break;
        insertar(dato);
    }
}

void Arbol::insertar(const Empleado &emp) {
    insertarR(raiz,emp);
}

void Arbol::insertarR(Nodo *&arbol,const Empleado &emp) {
    if (arbol == nullptr) {
        arbol = new Nodo;
        arbol->dato = emp;
        return;
    }
    if (emp.get_codigo() < arbol->dato.get_codigo()) insertarR(arbol->izquierda,emp);
    else insertarR(arbol->derecha,emp);
}

void Arbol::mostrarEnOrden(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    mostrarR(arch,raiz);
}

void Arbol::mostrarR(ofstream &arch, Nodo *&arbol) {
    if (arbol == nullptr) return;
    mostrarR(arch,arbol->izquierda);
    arch<<arbol->dato;
    mostrarR(arch,arbol->derecha);
}

Empleado Arbol::buscar(int cod) {
    return buscarR(raiz,cod);
}

Empleado Arbol::buscarR(Nodo *&arbol, int cod) {
    if (arbol == nullptr) { //en caso no encuentre
        Empleado emp;
        emp.set_codigo(-1);
        return emp;
    }
    if (arbol->dato.get_codigo() == cod) return arbol->dato;
    if (cod < arbol->dato.get_codigo()) return buscarR(arbol->izquierda,cod);
    else return buscarR(arbol->derecha,cod);
}
