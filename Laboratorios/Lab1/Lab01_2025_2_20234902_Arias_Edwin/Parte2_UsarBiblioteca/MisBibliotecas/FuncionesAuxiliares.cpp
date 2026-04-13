#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#define NO_ENCONTRADO -1

using namespace std;
#include "Estructuras.h"
#include "Operadores.h"
#include "FuncionesAuxiliares.h"

void leerArchivoAlumnos(const char*nombArch,struct Alumnos *arrAlumnos) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERRRO NO SE ECONTRO EL ARCHIVO"<<nombArch<<endl;
        exit(1);
    }
    int numAlumnos=0;
    while (true) {
        arch >> arrAlumnos[numAlumnos];
        if (arch.eof()) break;
        numAlumnos++;
    }
}
void leerArchivoCursos(const char*Cursos,struct Cursos *arrCursos) {
    ifstream arch(Cursos,ios::in);
    if (not arch.is_open()) {
        cout<<"ERRRO NO SE ECONTRO EL ARCHIVO"<<Cursos<<endl;
        exit(1);
    }
    int numCursos=0;
    while (true) {
        arch >> arrCursos[numCursos];
        if (arch.eof()) break;
        numCursos++;
    }
}
void leerArchivoMatriculaYActualizar(const char*nombArch,struct Alumnos *arrAlumnos,struct Cursos *arrCursos) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERRRO NO SE ECONTRO EL ARCHIVO"<<nombArch<<endl;
        exit(1);
    }
    struct Cursos curso;
    char codCurso[10];
    struct Alumnos alumno;
    int idAlumno,idCurso;
    while (true) {
        arch.getline(codCurso,10,',');
        if (arch.eof()) break;
        curso.codigo = new char [strlen(codCurso)+1];
        strcpy(curso.codigo,codCurso);
        arch >> alumno.codigo;
        arch.get();
        idAlumno = (arrAlumnos <= alumno);
        idCurso = (arrCursos >= curso);
        if (idAlumno != NO_ENCONTRADO and idCurso != NO_ENCONTRADO) arrCursos[idCurso] += arrAlumnos[idAlumno];
        for (int i = 0; arrCursos[i].codigo != nullptr; ++i) ++arrCursos[i];
    }
}
void imprimirReporteCursos(const char*nombArch,struct Cursos *arrCursos) {

    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERRRO NO SE ECONTRO EL ARCHIVO"<<nombArch<<endl;
        exit(1);
    }
    for (int i = 0; arrCursos[i].codigo != nullptr; ++i) {
        arch << arrCursos[i];
        arch<<setfill('-')<<setw(50)<<"-"<<setfill(' ')<<endl;
    }
}