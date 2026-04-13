//
// Created by alulab14 on 5/09/2025.
//

#ifndef FUENTES_BIBLIOTECA_2025_2_FUNCIONES_H
#define FUENTES_BIBLIOTECA_2025_2_FUNCIONES_H
void lecturaAlumnos(struct Alumnos *arrAlumnos,const char *nombArch);
void lecturaCursos(struct Cursos *arrCursos,const char *nombArch);
void lecturaMatri_ActualizaArr(struct Cursos *arrCursos,
    struct Alumnos *arrAlumnos,const char *nombArch);
void emiteReporte(struct Cursos *arrCursos,struct Alumnos *arrAlumnos,
    const char *nombArch);
#endif //FUENTES_BIBLIOTECA_2025_2_FUNCIONES_H