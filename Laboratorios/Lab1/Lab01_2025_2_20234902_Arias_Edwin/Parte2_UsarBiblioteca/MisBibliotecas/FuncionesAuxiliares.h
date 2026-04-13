//
// Created by Andres on 7/04/2026.
//

#ifndef PARTE2_USARBIBLIOTECA_FUNCIONESAUXILIARES_H
#define PARTE2_USARBIBLIOTECA_FUNCIONESAUXILIARES_H

void leerArchivoAlumnos(const char*nombArch,struct Alumnos *arrAlumnos);
void leerArchivoCursos(const char*Cursos,struct Cursos *arrCursos);
void leerArchivoMatriculaYActualizar(const char*nombArch,struct Alumnos *arrAlumnos,struct Cursos *arrCursos);
void imprimirReporteCursos(const char*nombArch,struct Cursos *arrCursos);

#endif //PARTE2_USARBIBLIOTECA_FUNCIONESAUXILIARES_H
