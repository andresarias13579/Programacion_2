//
// Created by Andres on 6/04/2026.
//

#ifndef CREABIBLIOTECA_PARTE1_OPERADORES_H
#define CREABIBLIOTECA_PARTE1_OPERADORES_H

void operator >> (ifstream &arch, struct Cursos &curso);
void operator >> (ifstream &arch, struct Alumnos &alumno);
bool operator > (struct Alumnos &alumno,const int codAlumno);
bool operator > (struct Cursos &curso,const char *codCurso);
void operator += (struct Cursos &curso,const struct Alumnos &alumno);
int operator <= (struct Alumnos *&arrAlumnos,const struct Alumnos &alumno);
int operator >= (struct Cursos *&arrCursos, const struct Cursos &curso);
void operator ++ (struct Cursos &curso);
void operator << (ofstream &arch,const struct Cursos &curso);

#endif //CREABIBLIOTECA_PARTE1_OPERADORES_H
