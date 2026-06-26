#include <iostream>
// #include "Bibliotecas/Persona.h"



using namespace std;
#include "Bibliotecas/Persona.h"
#include "Bibliotecas/PlLista.h"

int main() {
    // PRUEBA 1: Lista de Enteros
    PlLista<int> listaEnteros;
    listaEnteros.insertar(10);
    listaEnteros.insertar(25);
    listaEnteros.insertar(7);

    cout << "=== LISTA DE ENTEROS ===" << endl;
    listaEnteros.imprimir("ArchivoDeReportes/prueba_de_numeros_01.txt");
    listaEnteros.crear("ArchivoDeDatos/Enteros.txt");
    listaEnteros.imprimir("ArchivoDeReportes/Enteros_ordenados.txt");

    //ahora probemos con strings
    class PlLista<string> listaString;
    listaString.crear("ArchivoDeDatos/Nombres.txt");
    listaString.imprimir("ArchivoDeReportes/ReporteCadenas.txt");

    //ahora con clases de personal
     class PlLista<Persona> listaPersona;
     listaPersona.crear("ArchivoDeDatos/personal.csv");
     listaPersona.imprimir("ArchivoDeReportes/ReportePersonas.txt");

    return 0;
}