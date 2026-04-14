//
// Created by Andres on 13/04/2026.
//

#ifndef ASIGNACIONMEMORIAEXACTA_2ARCHVIOS_MISOLU_FUNCIONESAUXILIARES_H
#define ASIGNACIONMEMORIAEXACTA_2ARCHVIOS_MISOLU_FUNCIONESAUXILIARES_H

void leemosArchivoAlumnos(const char*nombArch,int *&codAlumnos,char **&nombAlumnos);
void leemosArchivoCursos(const char*nombArch,char ***&arrCursos,int *codAlumnos,char **nombAlumnos);
void imprimimosAlumnos(const char*nombArch,char ***arrCursos,int *codAlumnos,char **nombAlumnos);
void imprimirCursos(ofstream &arch,char **arrCursos);

char *leeCadenaExacta(ifstream &arch,char delimitador);
int buscarAlumno(int codAlum,int *codAlumnos);
void registrarCurso(char **arrCursos,char *codCurso,int &nd);
void asignamosMemoriaExacta(char **&arrCursos,int nd);

#endif //ASIGNACIONMEMORIAEXACTA_2ARCHVIOS_MISOLU_FUNCIONESAUXILIARES_H
