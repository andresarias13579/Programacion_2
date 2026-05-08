#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

enum BLOQUE {BLOQ1,BLOQ2};
enum NODO{DATO,SIG};
using namespace std;
#include "BibliotecaListaGenerica.h"

void creaLista(void *&lista,void *(leeNum)(ifstream &arch),int (*clasificaEntero)(const void *a),const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout <<"ERROR NO SE PUDO ABRIR EL ARHCIVO"<<nombArch<<endl;
        exit(1);
    }
    generaLista(lista);
    void *dato;
    while (true) {
        dato = leeNum(arch);
        if (arch.eof()) break;
        insertaLista(lista,dato,clasificaEntero);
    }
}
void generaLista(void *&lista) {
    void **listaBloques = new void *[2]{};

    void **inicioBloque2 = new void *[2]{};
    inicioBloque2[DATO] = nullptr;
    inicioBloque2[SIG] = nullptr;

    void **inicioBloque1 = new void *[2]{};
    inicioBloque1[DATO] = nullptr;
    inicioBloque1[SIG] = inicioBloque2;

    listaBloques[BLOQ1] = inicioBloque1;
    listaBloques[BLOQ2] = inicioBloque2;
    lista = listaBloques;
}
void insertaLista(void *&list,void *dato,int (*clasificaEntero)(const void *a)) {
    void **lista = (void **)list;
    void *anterior = nullptr, *ptrAux = nullptr;
    int numero = clasificaEntero(dato);
    void **bloque = (void **) lista[numero-1]; //nos da el inicio del bloque al que pertenece
    if (bloque[DATO] == nullptr) bloque[DATO] = dato;
    else {
        void *stop;
        if (numero == 1) {
            stop = lista[BLOQ2];
        }
        else {
            stop = nullptr;
        }
        insertaBloque(stop,bloque,dato);
    }
}
void insertaBloque(void *stop,void *bloque, void *dato) {
    void **ptrAux = (void **)bloque;
    void **nuevoNodo = new void *[2]{};
    nuevoNodo[DATO] = dato;
    while (ptrAux[SIG] != stop) {
        ptrAux = (void **)ptrAux[SIG];
    }
    ptrAux[SIG] = nuevoNodo;
    nuevoNodo[SIG] = stop;
}
void imprimeLista(void *lista,void (*imprimeEntero)(ofstream &arch,const void *dato),const char *nombreArch) {
    ofstream arch(nombreArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR NO SE PUDO ABRIR EL ARHCIVO"<<nombreArch<<endl;
        exit(1);
    }
    void **ptrAux = (void **)lista;
    void **bloque = (void **) ptrAux[BLOQ1];
    while (bloque != nullptr) {
        imprimeEntero(arch,bloque[DATO]);
        bloque = (void **)bloque[SIG];
    }
    arch<<endl;
}

