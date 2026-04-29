#include <iostream>
#include <iomanip>

using namespace std;
#include "cstdlib"
#include "Bibliotecas/FuncionesDeEnteris.h"

int main() {
    // int arrInt[30]{10,4,25,73,14,7,21,12,33,10,5,15,28,30};
    // int nd = 14;
    // qsort(arrInt, nd, sizeof(int), intcmpB);
    // for (int i = 0; i < nd; ++i) cout <<setw(3)<< arrInt[i];
    // cout << endl;

    char **personas;
    int nd;
    leerNombres(personas, nd,"");

    return 0;
}