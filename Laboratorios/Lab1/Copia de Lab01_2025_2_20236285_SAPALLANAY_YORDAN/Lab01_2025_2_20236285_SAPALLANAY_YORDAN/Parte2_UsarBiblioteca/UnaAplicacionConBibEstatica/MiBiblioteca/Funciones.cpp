//
// Created by alulab14 on 5/09/2025.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Sobrecarga.h"
#include "Estructuras.h"
#define NO_ENCONTRADO -1
void lecturaAlumnos(struct Alumnos *arrAlumnos,const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if ( not arch) {
        cout<<"ERROR : no se pudo abrir el archivo"<<endl;
        exit(1);
    }
    int i = 0;
    while (true) {
        arch>>arrAlumnos[i];
        if (arch.eof())break;
        i++;
    }
    arrAlumnos[i].codigo = 0;
    // for ( int i = 0; arrAlumnos[i].codigo != 0 ;i++)
    //     cout<<arrAlumnos[i].codigo<<"  "<<arrAlumnos[i].tipo<<endl;
}
void lecturaCursos(struct Cursos *arrCursos,const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if ( not arch) {
        cout<<"ERROR : no se pudo abrir el archivo"<<endl;
        exit(1);
    }
    int i = 0;
    while (true) {
        arch>>arrCursos[i];
        if (arch.eof())break;
        i++;
    }
    arrCursos[i].codigo = nullptr;
    // for ( int i = 0; arrCursos[i].codigo != nullptr ;i++)
    //     cout<<arrCursos[i].codigo<<"   "<<arrCursos[i].docente<<endl;
}
void lecturaMatri_ActualizaArr(struct Cursos *arrCursos,
    struct Alumnos *arrAlumnos,const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if ( not arch) {
        cout<<"ERROR : no se pudo abrir el archivo"<<endl;
        exit(1);
    }
    struct Alumnos alumno;
    struct Cursos curso;
    int posAlumno,posCurso;
    while (true) {
        curso.codigo = lecturaExacta(arch,10,',');
        if (arch.eof())break;
        arch>>alumno.codigo;
        arch.get();
        posAlumno = arrAlumnos <= alumno;
        if ( posAlumno != NO_ENCONTRADO) alumno = arrAlumnos[posAlumno];
        posCurso = arrCursos >= curso;
        if ( posCurso != NO_ENCONTRADO) {
            curso = arrCursos[posCurso] ;
            arrCursos[posCurso] += alumno;
        }
    }
    for ( int i = 0; arrCursos[i].codigo != nullptr ;i++)
        arrCursos[i]++;
}
void emiteReporte(struct Cursos *arrCursos,struct Alumnos *arrAlumnos,
    const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if ( not arch) {
        cout<<"ERROR : no se pudo abrir el archivo"<<endl;
        exit(1);
    }
    for ( int i = 0; arrCursos[i].codigo != nullptr ;i++)
        arch<<arrCursos[i];
}