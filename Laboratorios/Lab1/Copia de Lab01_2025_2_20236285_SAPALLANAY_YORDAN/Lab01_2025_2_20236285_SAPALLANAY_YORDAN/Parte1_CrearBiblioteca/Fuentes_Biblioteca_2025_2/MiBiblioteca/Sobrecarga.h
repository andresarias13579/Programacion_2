//
// Created by alulab14 on 5/09/2025.
//

#ifndef FUENTES_BIBLIOTECA_2025_2_SOBRECARGA_H
#define FUENTES_BIBLIOTECA_2025_2_SOBRECARGA_H
void operator >>(ifstream &arch,struct Cursos &curso);
void operator >>(ifstream &arch,struct Alumnos &alumno);
bool operator >(struct Alumnos &alumno,int codAlumno);
bool operator >(struct Cursos &curso,char *codCurso);
void operator +=(struct Cursos &curso,struct Alumnos &alumno);
int operator <=(struct Alumnos *arrAlumnos,struct Alumnos &alumno);
int operator >=(struct Cursos *arrCursos,struct Cursos &curso);
void operator ++(struct Cursos &curso,int dami);
void operator <<(ofstream &arch,struct Cursos &curso);
char *lecturaExacta(ifstream &arch,int max,char delimitador);
void agregaAlumnoAcurso(struct Alumnos *modalidad,int &num,
    struct Alumnos &alumno);
bool validaModalidad(int numPres,int semi,int virt);
#endif //FUENTES_BIBLIOTECA_2025_2_SOBRECARGA_H