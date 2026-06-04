#include <iostream>

using namespace std;
#include "Bibliotecas/Alumno.h"
#include "Bibliotecas/Presencial.h"
#include "Bibliotecas/Semipresencial.h"
#include "Bibliotecas/Virtual.h"
#include "Bibliotecas/Escala.h"
#include "Bibliotecas/Tesoreria.h"

int main() {
    Tesoreria caja;
    caja.cargaescalas("ArchivosDeDatos/escalas.csv");
    caja.cargaalumnos("ArchivosDeDatos/Alumnos.csv");
    caja.actualiza(20);
    caja.imprime("ArchivosDeReportes/reporteDePagos.txt");

    return 0;
}