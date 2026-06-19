#include <iostream>

using namespace std;
#include "Bibliotecas/Metrica.h"
#include "Bibliotecas/MetricaBasica.h"
#include "Bibliotecas/MetricaEngagement.h"
#include "Bibliotecas/MetricaCalidad.h"
#include "Bibliotecas/Nodo.h"
#include "Bibliotecas/Lista.h"
#include "Bibliotecas/AdministrarMetricas.h"

int main() {
    AdministrarMetricas adminitraMetricas;
    adminitraMetricas.cargarArchivo("ArchivosDeDatos/metricas.csv");
    adminitraMetricas.generarReporte("ArchivosDeReportes/reporteMetricasNormal.txt");
    adminitraMetricas.eliminarNodos();
    adminitraMetricas.generarReporte("ArchivosDeReportes/reporteMetricasActivas.txt");
    adminitraMetricas.eliminarLista();
    
    return 0;
}