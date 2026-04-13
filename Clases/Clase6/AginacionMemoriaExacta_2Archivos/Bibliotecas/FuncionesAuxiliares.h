//
// Created by Andres on 7/04/2026.
//

#ifndef AGINACIONMEMORIAEXACTA_2ARCHIVOS_FUNCIONESAUXILIARES_H
#define AGINACIONMEMORIAEXACTA_2ARCHIVOS_FUNCIONESAUXILIARES_H

void cargarAlumnos(int *&codigos,char **&nombres,const char*nombArch);
void cargarCursos(int *codigos,char ***&cursos,const char*nombArch);
void imprimirDatos(int *codigos,char **nombres,char ***cursos,const char*nombArch);

#endif //AGINACIONMEMORIAEXACTA_2ARCHIVOS_FUNCIONESAUXILIARES_H
