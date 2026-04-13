#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MiBiblioteca/Estructuras.h"
#include "MiBiblioteca/Sobrecarga.h"
#include  "MiBiblioteca/Funciones.h"

int main () {
    struct Alumnos arrAlumnos[90];
    struct Cursos arrCursos[15];
    lecturaAlumnos(arrAlumnos,"Alumnos.csv");
    lecturaCursos(arrCursos,"Cursos.csv");
    lecturaMatri_ActualizaArr(arrCursos,arrAlumnos,"Matricula.csv");
    emiteReporte(arrCursos,arrAlumnos,"Reportes.txt");
}