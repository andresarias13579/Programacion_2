#include <iostream>

using namespace std;
#include "MisBibliotecas/Persona.h"
#include "MisBibliotecas/Empleados.h"
#include "MisBibliotecas/Operadores.h"

int main() {
   struct Empleados empleados{};
   empleados << "ArchivoDeDatos/personal.csv"; //leemos el archivo
   "ArchivoDeReporte/reportePersonal2.txt" << empleados; //imprimimos el archivo
   //aumentamos el sueldo a todos
   empleados *= 4.5;
   "ArchivoDeReporte/reportePersonalAumento2.txt" << empleados;
   //ordenamos el arreglo
   ++empleados;
   "ArchivoDeReporte/reportePersonalOrdenado2.txt" << empleados;

   return 0;
}