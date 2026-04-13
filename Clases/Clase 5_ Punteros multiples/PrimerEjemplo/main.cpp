#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Biblioteca/Funciones Auxiliares.h"

int main() {
    int *codigos;
    char **nombre, ***cursos;
    cargarDatos(codigos,nombre,cursos,"Alumnos-Cursos.csv");
    imprimirDatos(codigos,nombre,cursos,"Reporte.txt");

    return 0;
}