#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Bibliotecas/MetodoExactoDeMemoria.h"

int main() {
    char ***libros,***pedidoLibros;
    int **stock,**pedidosClientes;
    bool **pedidosAtendidos;

    lecturaDeLibros("ArchivoDeDatos/Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ArchivoDeReporte/ReporteDeLibrosInicial.txt",libros,stock);

    atencionsDePedidos("ArchivoDeDatos/Pedidos.txt",libros,stock,pedidosClientes,pedidoLibros,
        pedidosAtendidos);
    pruebaDeLecturaDeLibros("ArchivoDeReporte/ReporteDeLibrosFinal.txt",libros,stock);

    return 0;
}