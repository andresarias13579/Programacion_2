#include <iostream>
#include <iomanip>

using namespace std;
#include "Bibliotecas/Persona.h"
#include "Bibliotecas/Empleados.h"
#include "Bibliotecas/Operadores.h"

int main() {
    struct Empleados empleados{};
    empleados << "ArchivoDeDatos/personal.csv"; //leemos el archivo
    "ArchivoDeReporte/reportePersonal.txt" << empleados; //imprimimos el archivo
    //aumentamos el sueldo a todos
    empleados *= 4.5;
    "ArchivoDeReporte/reportePersonalAumento.txt" << empleados;
    //ordenamos el arreglo
    ++empleados;
    "ArchivoDeReporte/reportePersonalOrdenado.txt" << empleados;

    return 0;
}