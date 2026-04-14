//
// Created by Andres on 14/04/2026.
//

#ifndef LECTURADEALUMNOS_FUNCIONESAUXILIARES_H
#define LECTURADEALUMNOS_FUNCIONESAUXILIARES_H

void cargarAlumnos(void *&al,const char*nombArch);
void incrementarEspacios(void **&alumnos,int &nd,int &cap);
void *leerRegistro(ifstream &arch);
char *leeCadenaExacta(ifstream &arch,char delimitador);

void imprimirAlumnos(void *alumnos,const char*nombArch);
void mostrarAlumno(void *al,ofstream &arch);

#endif //LECTURADEALUMNOS_FUNCIONESAUXILIARES_H
