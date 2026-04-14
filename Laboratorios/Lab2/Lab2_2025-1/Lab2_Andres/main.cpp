#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "Bibliotecas/Estructuras.h"
#include "Bibliotecas/OperadoresSobrecargados.h"
#include "Bibliotecas/FuncionesAuxiliares.h"

int main() {
    struct Faltas faltas;
    cargar_faltas_de_los_conductores(faltas);
    imprimir_faltas_de_los_conductores(faltas);

    return 0;
}