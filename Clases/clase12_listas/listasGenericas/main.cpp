#include <iostream>

using namespace std;
#include "Bibliotecas/BibliotecaListaGenerica.h"
#include "Bibliotecas/FuncionesDeEnteros.h"
#include "Bibliotecas/FuncionesDeCadenas.h"
#include "Bibliotecas/FuncionesDePunterosVoid.h"

//FUNCIONA POR COMPLETO

int main() {
    //con ENTEROS
    void *lista = nullptr;
    crearLista("ArchivoDeDatos/Datos.txt",lista,leeEntero,compararEnteros);
    imprimirLista("ArchivoDeReporte/reporteDeEnteros.txt",lista,imprimirEntero);
    //con CARACTERES
    void *listaNombres = nullptr;
    crearLista("ArchivoDeDatos/Personas.txt",listaNombres,leeCadena,compararCadenas);
    imprimirLista("ArchivoDeReporte/reporteDeCadenas.txt",listaNombres,imprimirCadena);
    //con REGISTROS
    void *listaRegistros = nullptr;
    crearLista("ArchivoDeDatos/personal.csv",listaRegistros,leeRegistro,compararDni);
    imprimirLista("ArchivoDeReporte/reporteDeRegistrosDNI.txt",listaRegistros,imprimirRegistro);
    //con REGISTROS pero comparado con NOMBRES
    void *listaRegistrosNombres = nullptr;
    crearLista("ArchivoDeDatos/personal.csv",listaRegistrosNombres,leeRegistro,compararNom);
    imprimirLista("ArchivoDeReporte/reporteDeRegistrosNombres.txt",listaRegistrosNombres,imprimirRegistro);

    return 0;
}