#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Estructuras.h"
#include "Operadores.h"

void operator >> (ifstream &arch, struct Cursos &curso) {
    char codCurso[10],nombreCurso[100],nombreDocente[100],c;
    int codDocente;
    double creditos;
    arch>>ws;
    arch.getline(codCurso,10,',');
    if (arch.eof()) return;
    arch.getline(nombreCurso,100,',');
    arch>>creditos>>c>>codDocente>>c;
    arch.getline(nombreDocente,100,'\n');
    curso.codigo = new char[strlen(codCurso)+1];
    strcpy(curso.codigo,codCurso);
    curso.nombre = new char[strlen(nombreCurso)+1];
    strcpy(curso.nombre,nombreCurso);
    curso.creditos = creditos;
    curso.docente = new char[strlen(nombreDocente)+1];
    strcpy(curso.docente,nombreDocente);
}
void operator >> (ifstream &arch, struct Alumnos &alumno) {
    int codAlumno;
    char nombreAlumno[50],modalidad,c;
    arch>>codAlumno;
    if (arch.eof()) return;
    arch>>c;
    arch.getline(nombreAlumno,50,',');
    arch>>modalidad;
    alumno.codigo = codAlumno;
    alumno.tipo = modalidad;
    alumno.nombre = new char[strlen(nombreAlumno)+1];
    strcpy(alumno.nombre,nombreAlumno);
}
bool operator > (struct Alumnos &alumno,const int codAlumno) {
    if (alumno.codigo == codAlumno) return true;
    else return false;
}
bool operator > (struct Cursos &curso,const char *codCurso) {
    if (strcmp(curso.codigo,codCurso) == 0) return true;
    else return false;
}
void operator += (struct Cursos &curso,const struct Alumnos &alumno) {
    if (alumno.tipo == 'P') {
        curso.presencial[curso.numpresencial] = alumno;
        curso.numpresencial++;
    } else if (alumno.tipo == 'S') {
        curso.semipresencial[curso.numsemipresencial] = alumno;
        curso.numsemipresencial++;
    } else if (alumno.tipo == 'V') {
        curso.vvirtual[curso.numvirtual] = alumno;
        curso.numvirtual++;
    }
}
int operator <= (struct Alumnos *&arrAlumnos,const struct Alumnos &alumno) {
    int centinela = 1,i=0;
    while (centinela) {
        if (arrAlumnos[i] > alumno.codigo) return i;
        if (arrAlumnos[i].codigo == 0) centinela = 0;
        i++;
    }
    return -1;
}
int operator >= (struct Cursos *&arrCursos, const struct Cursos &curso) {
    int centinela = 1,i=0;
    while (centinela) {
        if (arrCursos[i] > curso.codigo) return i;
        if (arrCursos[i].codigo == nullptr) centinela = 0;
        i++;
    }
    return -1;
}
void operator ++ (struct Cursos &curso) {
    int totalMatriculados = curso.numpresencial + curso.numsemipresencial + curso.numvirtual;
    double promPresencial = (double)curso.numpresencial / (double)totalMatriculados;
    char presencial[40] = "La clase se dictara en el aula";
    char virtuall[40] = "La clase se dictara 100% virtual";
    if (promPresencial >= 0.5) {
        curso.tipofinal = new char[strlen(presencial)+1];
        strcpy(curso.tipofinal,presencial);
    }
    else {
        curso.tipofinal = new char[strlen(virtuall)+1];
        strcpy(curso.tipofinal,virtuall);
    }
}
void operator << (ofstream &arch,const struct Cursos &curso) {
    arch <<setw(20)<<" "<<left<< setw(20)<<curso.codigo<<setw(20)<<curso.nombre<<right<<endl;
    arch<<setw(20)<<" "<<left<<curso.docente<<right<<endl;
    arch<<setw(20)<<" "<<left<<setw(30)<<"Alumnos presenciales: "<<setw(10)<<right<<curso.numpresencial<<endl;
    arch<<setw(20)<<" "<<left<<setw(30)<<"Alumnos semipresenciales: "<<setw(10)<<right<<curso.numsemipresencial<<endl;
    arch<<setw(20)<<" "<<left<<setw(30)<<"Alumnos virtuales: "<<setw(10)<<right<<curso.numvirtual<<endl;
    arch<<setw(20)<<" "<<left<<curso.tipofinal<<right<<endl;
}