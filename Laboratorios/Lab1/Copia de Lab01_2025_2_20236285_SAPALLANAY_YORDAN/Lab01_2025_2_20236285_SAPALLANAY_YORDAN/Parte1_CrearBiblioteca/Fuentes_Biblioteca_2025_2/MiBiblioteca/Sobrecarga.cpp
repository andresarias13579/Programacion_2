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
// INF263,Algoritmia,3.75,35030611,INGA_FLORES_CESAR_ADOLFO
// MEC270,Procesos_De_Manufactura,4,83265244,PAIRAZAMAN_ALAMO_MOISES_MIGUEL
void operator >>(ifstream &arch,struct Cursos &curso) {
    char c;
    int a;
    curso.codigo = lecturaExacta(arch,10,',');
    if (arch.eof())return;
    curso.nombre = lecturaExacta(arch,100,',');
    arch>>curso.creditos>>c>>a>>c;
    curso.docente = lecturaExacta(arch,100,'\n');
    curso.numpresencial = 0;
    curso.numsemipresencial = 0;
    curso.numvirtual = 0;
}
void operator >>(ifstream &arch,struct Alumnos &alumno) {
    arch>>alumno.codigo;
    if (arch.eof())return;
    arch.get();
    alumno.nombre = lecturaExacta(arch,100,',');
    arch>>alumno.tipo;
}
bool operator >(struct Alumnos &alumno,int codAlumno) {
    if (alumno.codigo == codAlumno) return true;
    else return false;
}
bool operator >(struct Cursos &curso,char *codCurso) {
    if ( strcmp(curso.codigo,codCurso) == 0 ) return true;
    else return false;
}
void operator +=(struct Cursos &curso,struct Alumnos &alumno) {
    if (alumno.tipo == 'P') {
        agregaAlumnoAcurso(curso.presencial,curso.numpresencial,alumno);
    }
    else {
        if ( alumno.tipo == 'S') {
            agregaAlumnoAcurso(curso.semipresencial,curso.numsemipresencial,alumno);
        }
        else {
            agregaAlumnoAcurso(curso.vvirtual,curso.numvirtual,alumno);
        }
    }
}
int operator <=(struct Alumnos *arrAlumnos,struct Alumnos &alumno) {
    for ( int i= 0;arrAlumnos[i].codigo!= 0 ;i++)
        if (arrAlumnos[i]>alumno.codigo)return i;
    return NO_ENCONTRADO;
}
int operator >=(struct Cursos *arrCursos,struct Cursos &curso) {
    for ( int i=0; arrCursos[i].codigo !=nullptr ;i++)
        if ( arrCursos[i]>curso.codigo)return i;
    return NO_ENCONTRADO;
}
void operator ++(struct Cursos &curso,int dami) {
    bool seDictaraPresencial;
    curso.tipofinal = new char[140]{};
    seDictaraPresencial = validaModalidad(curso.numpresencial,
        curso.numsemipresencial,curso.numvirtual);
    if ( seDictaraPresencial)
        strcpy(curso.tipofinal,"La clase se dictara en aula");
    else strcpy(curso.tipofinal,"La classe se dictara 100% virtual");
}
void operator <<(ofstream &arch,struct Cursos &curso) {
    arch<<curso.codigo<<"   "<<curso.nombre<<endl;
    arch<<curso.docente<<endl;
    arch<<"Alumnos presenciales:     "<<curso.numpresencial<<endl;
    arch<<"Alumnos semipresenciales: "<<curso.numsemipresencial<<endl;
    arch<<"Alumnos virtual:          "<<curso.numvirtual<<endl;
    arch<<curso.tipofinal<<endl;
}
//aux
char *lecturaExacta(ifstream &arch,int max,char delimitador) {
    char buff[140],*p;
    arch.getline(buff,max,delimitador);
    if (arch.eof())return nullptr;
    p = new char[strlen(buff)+1];
    strcpy(p,buff);
    return p;
}
void agregaAlumnoAcurso(struct Alumnos *modalidad,int &num,
    struct Alumnos &alumno) {
    int n = num;
    modalidad[n] = alumno;
    num++;
}
bool validaModalidad(int numPres,int semi,int virt) {
    int total = numPres + virt;
    double por;
    por = (double)numPres*100/total;
    if ( por >= 50)return true;
    else return false;
}