#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "Bibliotecas/BibliotecaListaGenerica.h"
#include "Bibliotecas/BibliotecaEnteros.h"

int main() {
    void *lista;
    creaLista(lista,leeNum,clasificaEntero,"ArchivoDeDatos/numeros2.txt");
    imprimeLista(lista,imprimeEntero,"ArchivoDeReporte/Repnum.txt");

    return 0;
}