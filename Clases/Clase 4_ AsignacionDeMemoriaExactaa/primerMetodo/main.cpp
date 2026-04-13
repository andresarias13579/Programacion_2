#include <iostream>
#include <iomanip>

using namespace std;
#include "Biblioteca/FuncionesAuxiliares.h"

int main() {
    int *datos,numDatos;
    //algo falla nose porque XD
    leeDatosExactos(datos,numDatos,"Datos.txt");
    imprimirDatos(datos,numDatos,"MuestraDatos.txt");

    return 0;
}