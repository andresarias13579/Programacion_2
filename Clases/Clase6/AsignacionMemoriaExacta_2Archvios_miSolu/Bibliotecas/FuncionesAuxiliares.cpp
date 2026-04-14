#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#define MAX_ALUMNOS 50
#define NO_ENCONTRADO -1

using namespace std;
#include "FuncionesAuxiliares.h"

void leemosArchivoAlumnos(const char*nombArch,int *&codAlumnos,char **&nombAlumnos) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout <<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<nombArch<<endl;
        exit(1);
    }
    int numAlumnos=0,bufferAlumnosCod[MAX_ALUMNOS]{};
    char *bufferAlumnosNombres[MAX_ALUMNOS]{};
    while (true) {
        arch>>bufferAlumnosCod[numAlumnos];
        if (arch.eof()) break;
        arch.get();
        bufferAlumnosNombres[numAlumnos] = leeCadenaExacta(arch,'\n');
        numAlumnos++;
    }
    codAlumnos = new int[numAlumnos+1]{};
    nombAlumnos = new char *[numAlumnos+1]{};
    for (int i = 0; i < numAlumnos; ++i) {
        codAlumnos[i] = bufferAlumnosCod[i];
        nombAlumnos[i] = bufferAlumnosNombres[i];
    }
}
void leemosArchivoCursos(const char*nombArch,char ***&arrCursos,int *codAlumnos,char **nombAlumnos) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout <<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<nombArch<<endl;
        exit(1);
    }
    int numDatos = 0;
    while (codAlumnos[numDatos]) ++numDatos;
    int codAlum,idAlumno;
    int nd[numDatos+1] {};
    arrCursos = new char **[numDatos+1]{};
    for (int i = 0; i < numDatos; ++i) arrCursos[i] = new char *[70]{};
    while (true) {
        arch>>codAlum;
        if (arch.eof()) break;
        char *codCurso;// = new char[7]; //falta pensarla
        arch.get();
        codCurso = leeCadenaExacta(arch,'\n');
        idAlumno = buscarAlumno(codAlum,codAlumnos);
        if (idAlumno != NO_ENCONTRADO) {
            registrarCurso(arrCursos[idAlumno],codCurso,nd[idAlumno]);
        }
    }
    for (int i = 0; i < numDatos; ++i) {
        asignamosMemoriaExacta(arrCursos[i],nd[i]);
    }
}
void imprimimosAlumnos(const char*nombArch,char ***arrCursos,int *codAlumnos,char **nombAlumnos) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout <<"ERROR NO SE PUDO ABRIR EL ARCHIVO"<<nombArch<<endl;
        exit(1);
    }
    int numDatos = 0;
    while (codAlumnos[numDatos]) ++numDatos;
    for (int i = 0; i < numDatos; ++i) {
        arch<<left<<setw(50)<<nombAlumnos[i]<<right<<setw(30)<<codAlumnos[i]<<endl;
        if (arrCursos[i] != nullptr) imprimirCursos(arch,arrCursos[i]);
    }
}
void imprimirCursos(ofstream &arch,char **arrCursos) {
    int numCursos=0;
    while (arrCursos[numCursos]!=nullptr) ++numCursos;
    for (int i = 0; i < numCursos; ++i) {
        arch << setw(13)<<arrCursos[i]<<endl;
    }
}
char *leeCadenaExacta(ifstream &arch,char delimitador) {
    char *ptrAux, cadena[100];
    arch.getline(cadena,100,delimitador);
    if (arch.eof()) return nullptr;
    ptrAux = new char[strlen(cadena)+1];
    strcpy(ptrAux,cadena);
    return ptrAux;
}
int buscarAlumno(int codAlum,int *codAlumnos) {
    int numAlumnos=0;
    while (true) {
        if (codAlum == codAlumnos[numAlumnos]) return numAlumnos;
        if (codAlumnos[numAlumnos] == 0) break;
        numAlumnos++;
    }
    return NO_ENCONTRADO;
}
void registrarCurso(char **arrCursos,char *codCurso,int &nd) {
    arrCursos[nd] = codCurso;
    nd++;
}
void asignamosMemoriaExacta(char **&arrCursos,int nd) {
    char **ptrAux;
    if (nd != 0) {
        ptrAux = new char*[nd+1]{};
        for (int i = 0; i < nd; ++i) ptrAux[i] = arrCursos[i];
        delete [] arrCursos;
        arrCursos = ptrAux;

    }else {
        delete [] arrCursos;
        arrCursos = nullptr;
    }
}
