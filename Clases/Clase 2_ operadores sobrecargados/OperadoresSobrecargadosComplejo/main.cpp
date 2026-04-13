#include <iostream>
#include <iomanip>

using namespace std;
#include "Biblioteca/Persona.h"
#include "Biblioteca/Empleados.h"
#include "Biblioteca/OperadoresSobrecargados.h"

int main() {
    struct Empleados empleados {};

    empleados << "ArchivoDeDatos/personal.csv";
    "ArchivoDeReporte/ReporteDePersonal.csv" << empleados;
    return 0;
}