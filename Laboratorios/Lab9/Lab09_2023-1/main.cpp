#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;
#include "Bibliotecas/Alumno.h"
#include "Bibliotecas/Escala.h"
#include "Bibliotecas/Presencial.h"
#include "Bibliotecas/Semiprecensial.h"
#include "Bibliotecas/Virtuales.h"
#include "Bibliotecas/Boleta.h"
#include "Bibliotecas/Tesoreria.h"

int main() {
    Tesoreria OTeso;

    OTeso.cargaescalas("ArchivoDeDatos/escalas.csv");
    OTeso.cargaalumnos("ArchivoDeDatos/Alumnos.csv");
    OTeso.imprimeboleta("ArchivosDeReporte/reporteAlumnos.txt");

    return 0;
}