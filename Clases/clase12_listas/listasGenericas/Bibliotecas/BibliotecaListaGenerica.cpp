#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
#include "BibliotecaListaGenerica.h"

enum REG{DATO,SIGUIENTE};

void crearLista(const char*nombArch, void *&lista, void *(lee)(ifstream &arch),int (*comparar)(const void*,const void*)) {
    ifstream arch(nombArch,ios::in);
    if(!arch.is_open()) {
        cout <<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<nombArch<<endl;
        exit(1);
    }
    void *dato;
    while (true) {
        dato = lee(arch);
        if (arch.eof()) break;
        insertar(dato,lista,comparar);
    }
}
void insertar(void *dato,void *&lista,int (*comparar)(const void*,const void*)) {
    void **p = (void **)lista, **ant = nullptr, **nuevo;
    nuevo = new void*[2]{};
    nuevo[DATO]  = dato;
    while (p) {
        if (comparar(dato,p[DATO]) < 0) break;
        ant = p;
        p = (void **)p[SIGUIENTE];
    }
    nuevo[SIGUIENTE] = p;
    if (ant) ant[SIGUIENTE] = nuevo;
    else lista = nuevo;
}
void imprimirLista(const char*nombArch, void *&lst, void (*imprimir)(ofstream &arch,void *dato)) {
    ofstream arch(nombArch,ios::out);
    if(!arch.is_open()) {
        cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" <<nombArch<< endl;
        exit(1);
    }
    void **lista = (void**)lst;
    while (lista) {
        imprimir(arch,lista[DATO]);
        lista = (void **)lista[SIGUIENTE];
    }
    arch<<endl;
}