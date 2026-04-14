#include <iostream>
#include <iomanip>
#include <fstream>

#define MAX_ALUMNOS 50

using namespace std;
#include "Bibliotecas/FuncionesAuxiliares.h"

int main() {
    int *codAlumnos;
    char **nombAlumnos,***arrCursos;
    leemosArchivoAlumnos("ArchivoDeDatos/Alumnos.csv",codAlumnos, nombAlumnos);
    leemosArchivoCursos("ArchivoDeDatos/Cursos.csv",arrCursos,codAlumnos,nombAlumnos);
    imprimimosAlumnos("ArchivoDeReporte/reporteAlumnos.txt",arrCursos,codAlumnos,nombAlumnos);
    return 0;
}