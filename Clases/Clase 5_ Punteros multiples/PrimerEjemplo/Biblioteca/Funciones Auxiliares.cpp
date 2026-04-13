#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "Funciones Auxiliares.h"

void cargarDatos(int *&codigos,char **&nombre,char ***&cursos,const char*nombArch) {
    int buffCod[50]{},cod,numDatos;
    char *buffNombre[50]{}, **buffCursos[50]{};
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    numDatos = 0;
    while (true) {
        arch>>cod;
        if (arch.eof()) break;
        arch.get();
        buffCod[numDatos] = cod;
        buffNombre[numDatos] = leeNombre(arch);
        buffCursos[numDatos] = leeCursos(arch);
        numDatos++;
    }
    //numDatos++;
    codigos = new int[numDatos+1]{};
    nombre = new char*[numDatos+1]{};
    cursos = new char**[numDatos+1]{};
    for (int i = 0; i < numDatos; ++i) {
        codigos[i] = buffCod[i];
        nombre[i] = buffNombre[i];
        cursos[i] = buffCursos[i];
    }
}
void imprimirDatos(int *&codigos,char **&nombre,char ***&cursos,const char*nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    for (int i = 0;codigos[i]; ++i) {
        arch<<setw(10)<<codigos[i]<<nombre[i]<<endl;
        imprimeCurso(cursos[i],arch);
    }
}
void imprimeCurso(char **cursos,ofstream &arch) {
    for (int i = 0; cursos[i]; ++i) {
        arch<<setw(10)<<cursos[i]<<endl;
    }
    arch<<endl;
}

char *leeNombre(ifstream &arch) {
    char auxNombre[60],*nombre;
    arch>>auxNombre;
    arch.getline(auxNombre,60,',');
    nombre = new char[strlen(auxNombre)+1];
    strcpy(nombre,auxNombre);
    return nombre;
}
char **leeCursos(ifstream &arch) {
    char *bufferCursos[20],**cursos,*cur;
    //buffer cursos son los cursos que lleva el alumno
    int numCursos = 0;
    while (true) {
        cur = leeCur(arch);
        bufferCursos[numCursos] = cur;
        numCursos++;
        if (arch.get()!=',') break;
    }
    cursos = new char*[numCursos+1]{};
    for (int i = 0; i < numCursos; ++i) {
        cursos[i] = bufferCursos[i];
    }
    return cursos;
}
char *leeCur(ifstream &arch) {
    char *cursos = new char[7];
    arch.get(cursos,7);
    return cursos;
}
