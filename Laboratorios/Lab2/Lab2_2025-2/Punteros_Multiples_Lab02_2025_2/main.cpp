#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Bibliotecas/FuncionesAuxiliares.h"

int main() {
    char ***categorias;
    cargarCategorias("ArchivoDeDatos/categorias.csv",categorias);

    char ***streamers;
    int **fechasPromedios;
    long long **tiempoRepSeguidores;
    cargarStreamers("ArchivoDeDatos/streamers.csv",streamers,fechasPromedios,tiempoRepSeguidores);

    char ***comentarios;
    char ***etiquetas;
    cargarComentarios("ArchivoDeDatos/comentarios.csv",comentarios,etiquetas);

    return 0;
}