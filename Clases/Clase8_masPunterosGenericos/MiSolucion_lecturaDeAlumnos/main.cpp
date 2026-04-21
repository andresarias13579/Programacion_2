#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "Bibliotecas/FuncionesAuxiliares.h"

int main() {

    void *alumnos;
    cargarAlumnos(alumnos,"Alumnos.csv");
    imprimirAlumnos(alumnos,"ReporteAlumnosBasico.txt");

    cargarCursos(alumnos,"CursosNotas.csv");
    imprimirAlumnos(alumnos,"ReporteAlumnosFinal.txt");

    return 0;
}