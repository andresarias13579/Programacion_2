#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>



using namespace std;
#include "Bibliotecas/SistemaDeGestion.h"

int main() {
    SistemaDeGestion sistema;

    sistema.cargarCategorias("ArchivosDeDatos/Categorias.csv");
    sistema.cargarComentarios("ArchivosDeDatos/Comentarios.csv");
    sistema.cargarEtiquetas("ArchivosDeDatos/Etiquetas.csv");
    sistema.cargarStreamers("ArchivosDeDatos/Streamers.csv");

    sistema.completarStreamers();

    sistema.reporteStreamers("ArchivosDeReportes/ReporteInicial.txt");

    sistema.eliminarStreamers("English");

    sistema.reporteStreamers("ArchivosDeReportes/ReporteFinal.txt");


    return 0;
}