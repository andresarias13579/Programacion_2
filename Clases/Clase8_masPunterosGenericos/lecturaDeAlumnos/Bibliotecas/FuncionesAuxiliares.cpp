#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#define INCREMENTO 5
enum Indice {COD,NOM,CUR,PRO};

using namespace std;
#include "FuncionesAuxiliares.h"

void cargarAlumnos(void *&al,const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    void **alumnos = nullptr, *reg;
    int nd = 0,cap = 0;
    while (true) {
        reg = leerRegistro(arch);
        if (arch.eof()) break;
        if (nd == cap) incrementarEspacios(alumnos,nd,cap);
        alumnos[nd - 1] = reg;
        nd++;
    }
    al = alumnos;
}
void incrementarEspacios(void **&alumnos,int &nd,int &cap) {
    void **aux;
    cap += INCREMENTO;
    if (alumnos == nullptr) {
        alumnos = new void *[cap]{};
        nd = 1;
    }else {
        aux = new void *[cap]{};
        for (int i = 0; i < nd; ++i) aux[i] = alumnos[i];
        delete [] alumnos;
        alumnos = aux;
    }
}
void *leerRegistro(ifstream &arch) {
    void **registro;
    int cod, *codigo;
    char *nombre;
    arch >> cod;
    if (arch.eof()) return nullptr;
    arch.get();
    codigo = new int;
    *codigo = cod;
    nombre = leeCadenaExacta(arch,'\n');
    registro = new void *[4];
    registro[COD] = codigo;
    registro[NOM] = nombre;
    return registro; //pese a que registro es un void** la funcion es capaz de retonar cualquier puntero ya que es un void*
}
char *leeCadenaExacta(ifstream &arch,char delimitador) {
    char cadena[60],*ptr;
    arch.getline(cadena,60,delimitador);
    if (arch.eof()) return nullptr;
    ptr = new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}

void imprimirAlumnos(void *al,const char*nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    void **alumnos = (void **)al;
    for (int i = 0; alumnos[i]; ++i) {
        mostrarAlumno(alumnos[i],arch);
    }
}
void mostrarAlumno(void *al,ofstream &arch) {
    void **alumnos = (void **)al;
    int *codigo = (int*)alumnos[COD];
    char *nombre = (char*)alumnos[NOM];
    arch<<left<<setw(10)<<*codigo<<nombre<<endl;
}
