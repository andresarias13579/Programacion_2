#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "Bibliotecas/Restaurante.h"

int main() {
    class Restaurante restaurante;
    restaurante<"ArchivoDeDatos/Clientes.csv";
    restaurante<="ArchivoDeDatos/PlatosOfrecidos.csv";
    restaurante<<="ArchivoDeDatos/Pedidos.csv";
    restaurante>>"ArchivoDeReportes/ReporteDeVentasDelDia.txt";

    return 0;
}