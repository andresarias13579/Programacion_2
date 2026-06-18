#include <iostream>

using namespace std;
#include "Bibliotecas/Empleado.h"
#include "Bibliotecas/Nodo.h"
#include "Bibliotecas/Lista.h"

int main() {
    Lista lista;
    lista.crear("personal.csv");
    lista.imprimir("Reporte_de_personal_normal.txt");
    lista.imprimirRecursivo("Reporte_de_personal_recursivo.txt");

    return 0;
}