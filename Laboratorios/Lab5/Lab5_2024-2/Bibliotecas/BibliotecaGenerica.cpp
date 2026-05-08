#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "BibliotecaGenerica.h"
#include "BibliotecaEnteros.h"

enum TAD {INI,FIN,NUM};
enum NODO {DUPLA,SIG};
enum p_DUPLA{DATO,ARR};

void creaLista(void *&lista,void *(leeNumeros)(ifstream &arch),const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    construir(lista);
    void *dato;
    while (true) {
        dato = leeNumeros(arch);
        if (arch.eof()) break;
        insertarOrdenado(lista,dato);
    }
}
void construir(void *&list) {
    void **lista = new void* [3]{};

    lista[INI] = nullptr;
    lista[FIN] = nullptr;
    int *contador = new int(0);
    lista[NUM] = contador;

    list = lista;
}
void insertarOrdenado(void *list, void *dato) {
    void **lista = (void **)list;
    void **nuevoNodo = new void* [2]{};
    insertarDato(nuevoNodo[DUPLA],dato);
    nuevoNodo[SIG] = nullptr;
    void **anterior = nullptr, **ptrAux = (void **)lista[INI];
    while (ptrAux != nullptr) {
        void **nodo = (void **)ptrAux[DUPLA];
       if (compararEnteros(dato,nodo[DATO])) break;
        anterior = ptrAux;
        ptrAux = (void **)ptrAux[SIG];
    }
    if (anterior == nullptr) { // Insertar al inicio (vacía o no vacía)
        nuevoNodo[SIG] = lista[INI];
        lista[INI] = nuevoNodo;
        if (lista[FIN] == nullptr) lista[FIN] = nuevoNodo; // Si estaba vacía, también es el final
    } else { // Insertar al medio o al final
        anterior[SIG] = nuevoNodo;
        nuevoNodo[SIG] = ptrAux;
        if (ptrAux == nullptr) lista[FIN] = nuevoNodo; // Si insertamos al final, actualizamos FIN
    }
    (*(int*)lista[NUM]) ++;
    list = lista;
}
void insertarDato(void *&dobles, void *dato) {
    void **dupla = new void* [2]{};
    dupla[DATO] = dato;
    dupla[ARR] = new void *[20];
    dobles = dupla;
}
bool esListaVacia(void *list) {
    void **lista = (void **)list;
    if (lista[INI] == nullptr) return true;
    else return false;
}
enum REG{CLAVE, REP};
void cargarLista(void *list,bool (*compruebaNumeros)(const void *a, const void *b),void *(leeregnumeros)(ifstream &arch),const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    void **lista = (void**)list;
    void *dato;
    while (true) {
        dato = leeregnumeros(arch);
        if (arch.eof()) break;
        void **ptrAux = (void **)lista[INI];
        while (ptrAux != nullptr) {
            void **nodo = (void **)ptrAux[DUPLA];
            void **datito = (void **)dato;
            if (compruebaNumeros(datito[CLAVE],nodo[DATO])) {
                metemosAlArreglo(datito[REP],nodo[ARR]);
            }
            ptrAux = (void **)ptrAux[SIG];
        }
    }
}