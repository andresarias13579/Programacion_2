#include <iostream>

using namespace std;
#include "Bibliotecas/FuncionesAuxiliares.h"

int main() {
    void *alumnos;
    cargarAlumnos(alumnos,"ArchivoDeDatos/Alumnos.csv");
    imprimirAlumnos(alumnos,"ArchivoDeReporte/ReporteDeAlumnos.csv");
    return 0;
}