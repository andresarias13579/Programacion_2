#include <iostream>

using namespace std;
#include "Bilbiotecas/FuncionesDeEnteros.h"
#include "Bilbiotecas/FuncionesDeOrdenacionGenerica.h"


int main() {
    long long arrInt[50] {
        10,15,25,4,18,33,21,6,43,15,61,9,35,17,1,23,11,20
    };
    int numDatos = 18;
    ordenaG(arrInt, 0,17,comparaEnteros);
    for (int i = 0; i < numDatos; i++) cout << arrInt[i] << endl; //imprime mal xd, fallo algo en las funciones


    return 0;
}