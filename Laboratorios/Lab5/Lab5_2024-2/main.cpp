#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Bibliotecas/BibliotecaGenerica.h"
#include "Bibliotecas/BibliotecaEnteros.h"

int main() {
    void *lista;
    creaLista(lista,leeNumeros,"ArchivoDeDatos/numeros1.txt");
    cargarLista(lista,compruebaNumeros,leeregnumeros,"ArchivoDeDatos/numeros2.txt");

    return 0;
}
