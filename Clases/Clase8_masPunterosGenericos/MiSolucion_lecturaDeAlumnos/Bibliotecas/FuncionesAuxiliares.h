//
// Created by aml on 20/04/2026.
//

#ifndef MISOLUCION_LECTURADEALUMNOS_FUNCIONESAUXILIARES_H
#define MISOLUCION_LECTURADEALUMNOS_FUNCIONESAUXILIARES_H

void cargarAlumnos(void *&al,const char*nombArch);
void asignamosDatos(void *&al,int codAlumnos,char *nombreAlumno);
void imprimirAlumnos(void *al,const char *nombArch);
void mostrarAlumno(ofstream &arch,void *al);
void mostrarCursosPorAlumno(ofstream &arch,void **cursos,void **notas);

void cargarCursos(void *&al,const char*nombArch);
void leeLoDemas(ifstream &arch,char *&codCurso,int &nota);
void asignamosCursos(void *&al,char *codCurso,int nota,int &numCursos,int &capacidad);

char *leeCadenaExacta(ifstream &arch,char delimitador);
void incrementarMemoria(void **&alumnos,int &capacidad,int numDatos);
int buscamosAlumno(void **alumnos,int codAlumno,int numDatos);

#endif //MISOLUCION_LECTURADEALUMNOS_FUNCIONESAUXILIARES_H