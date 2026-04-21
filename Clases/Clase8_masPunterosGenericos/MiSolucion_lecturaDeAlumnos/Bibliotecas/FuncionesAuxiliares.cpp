#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

enum DATOS {COD,NOM,CUR,NOT};

using namespace std;
#include "FuncionesAuxiliares.h"

void cargarAlumnos(void *&al,const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    void **alumnos;
    char *nombreAlumno;
    int codAlumnos,numDatos=0,capacidad = 0;
    alumnos = nullptr;
    while (true) {
        arch>>codAlumnos;
        if (arch.eof()) break;
        arch.get();
        nombreAlumno = leeCadenaExacta(arch,'\n');
        if (numDatos == capacidad) incrementarMemoria(alumnos,capacidad,numDatos);
        asignamosDatos(alumnos[numDatos],codAlumnos,nombreAlumno);
        numDatos++;
    }
    al = alumnos;
}
void asignamosDatos(void *&al,int codAlumnos,char *nombreAlumno) {
    void **datosAlumno = new void *[4]{};
    int *codAlum = new int;
    *codAlum = codAlumnos;
    datosAlumno[COD] = codAlum;
    datosAlumno[NOM] = nombreAlumno;
    al = datosAlumno;
}
void imprimirAlumnos(void *al,const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    int numDatos = 0;
    void **alumnos;
    alumnos = (void **)al;
    while (alumnos[numDatos]) numDatos++;
    for (int i = 0; i < numDatos; ++i) {
        mostrarAlumno(arch,alumnos[i]);
    }
}
void mostrarAlumno(ofstream &arch,void *al) {
    void **alumno = (void**)al;
    int *codAlum = (int *)alumno[COD];
    char *nombre = (char*)alumno[NOM];
    void **cursos = (void**)alumno[CUR],**notas  = (void**)alumno[NOT];
    arch<<*codAlum<<"    "<<left<<setw(50)<<nombre<<right<<endl;
    if (cursos) mostrarCursosPorAlumno(arch,cursos,notas);
}
void mostrarCursosPorAlumno(ofstream &arch,void **cursos,void **notas) {
    int numCursos = 0;
    while (cursos[numCursos]) numCursos++;
    char *cur;
    int *nota = new int;
    for (int i = 0; i < numCursos; ++i) {
        nota = (int *)notas[i];
        cur = (char *)cursos[i];
        arch<<setw(15)<<cur<<setw(10)<<*nota<<endl;
        cout<<setw(15)<<cur<<setw(10)<<*nota<<endl;
    }

}

void cargarCursos(void *&al,const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    void **alumnos = (void **)al;
    int numDatos = 0,codAlumno,nota,idAlumno,*numCursos,*numCapacidades;
    char *codCurso;
    while (alumnos[numDatos]) numDatos++;
    numCursos = new int[numDatos]{};
    numCapacidades = new int[numDatos]{};
    while (true) {
        arch>>codAlumno;
        if (arch.eof()) break;
        leeLoDemas(arch,codCurso,nota);
        idAlumno = buscamosAlumno(alumnos,codAlumno,numDatos);
        if (idAlumno != -1) {
            asignamosCursos(alumnos[idAlumno],codCurso,nota,numCursos[idAlumno],numCapacidades[idAlumno]);
        }
    }

    al = alumnos;
}
void leeLoDemas(ifstream &arch,char *&codCurso,int &nota) {
    arch.get();
    codCurso = leeCadenaExacta(arch,',');
    arch>>nota;
    arch.get();
}
void asignamosCursos(void *&al,char *codCurso,int nota,int &numCursos,int &capacidad) {
    void **alumno = (void**)al;
    void **curso = (void**)alumno[CUR],**notas = (void**)alumno[NOT];
    int capacidadCurso = capacidad,capacidadNota = capacidad;
    if (capacidad == numCursos) {
        incrementarMemoria(curso,capacidadCurso,numCursos);
        incrementarMemoria(notas,capacidadNota,numCursos);
        capacidad = capacidadCurso;
    }
    int *notita = new int;
    *notita = nota;
    notas[numCursos] = notita;
    curso[numCursos] = codCurso;
    alumno[CUR] = curso;
    alumno[NOT] = notas;
    al = alumno;
    numCursos++;
}

char *leeCadenaExacta(ifstream &arch,char delimitador) {
    char *ptr,cadena[200];
    arch.getline(cadena,200,delimitador);
    if (arch.eof()) return nullptr;
    ptr = new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}
void incrementarMemoria(void **&alumnos,int &capacidad,int numDatos) {
    if (capacidad == 0) {
        alumnos = new void*[5+1]{};
        capacidad = 5;
    }
    else {
        void **auxiliar;
        auxiliar = new void*[capacidad+5+1]{};
        for (int i = 0; i < numDatos; ++i) auxiliar[i] = alumnos[i];
        delete [] alumnos;
        alumnos = auxiliar;
        capacidad += 5;
    }
}
int buscamosAlumno(void **alumnos,int codAlumno,int numDatos) {
    // int *cod = new int;
    // *cod = codAlumno;
    for (int i = 0; i < numDatos; ++i) {
        void **datosAlumno;
        int *codigo;
        datosAlumno = (void **)alumnos[i];
        codigo = (int *)datosAlumno[COD];
        if ( *codigo == codAlumno) return i;
    }
    return -1;
}