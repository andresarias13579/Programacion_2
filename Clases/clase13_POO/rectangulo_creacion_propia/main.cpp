#include <iostream>

using namespace std;
#include "Bibliotecas/Rectangulo.h"

int main() {
    class Rectangulo rectangulo;
    int base;
    rectangulo.asignarAtributos(4,5);
    rectangulo.mostrarResultados();
    base = rectangulo.entregarBase();
    cout <<"BASE: "<< base << endl;

    return 0;
}