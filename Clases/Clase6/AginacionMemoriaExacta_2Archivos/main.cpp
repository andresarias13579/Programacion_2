#include <iostream>
#include <iomanip>

using namespace std;
#include "Bibliotecas/FuncionesAuxiliares.h"

int main() {
    int *codigos;
    char **nombres,***cursos;
    cargarAlumnos(codigos,nombres,"ArchivoDeDatos/Alumnos.txt");
    cargarCursos(codigos,cursos,"ArchivoDeDatos/Cursos.txt");
    imprimirDatos(codigos,nombres,cursos,"ArchivoDeReporte/Reporte.txt");
    return 0;
}