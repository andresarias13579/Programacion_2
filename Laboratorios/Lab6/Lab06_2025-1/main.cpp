#include <iostream>

using namespace std;
#include "Bibliotecas/Infraccion.h"
#include "Bibliotecas/Multa.h"
#include "Bibliotecas/Empresa.h"
#include "Bibliotecas/MinisterioDeTransporte.h"

int main() {
    class MinisterioDeTransporte ministerio;
    ministerio < "ArchivoDeDatos/TablaDeInfracciones.csv";
    ministerio <= "ArchivoDeDatos/EmpresasRegistradas.csv";
    ministerio <<= "ArchivoDeDatos/InfraccionesCometidas.csv";
    ministerio >> "ArchivoDeReportes/ReporteParaElMinisterio.txt";
    return 0;
}