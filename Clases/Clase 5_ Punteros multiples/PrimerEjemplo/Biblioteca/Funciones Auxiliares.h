//
// Created by Andres on 1/04/2026.
//

#ifndef FUNCIONES_AUXILIARES_H
#define FUNCIONES_AUXILIARES_H

void cargarDatos(int *&codigos,char **&nombre,char ***&cursos,const char*nombArch);
void imprimirDatos(int *codigos,char **nombre,char ***cursos,const char*nombArch);
void imprimeCurso(char **cursos,ofstream &arch);
char *leeNombre(ifstream &arch);
char **leeCursos(ifstream &arch);
char *leeCur(ifstream &arch);

#endif //FUNCIONES_AUXILIARES_H
