#include <iostream>
using namespace std;
#include "Bibliotecas/Rectangulo.h"

void f (const class Rectangulo &rect) {
    rect.mostrar();
    rect.get_base();
}

int main() {
    class Rectangulo rectangulo(4,5,"Cuadrangular");
    rectangulo.mostrar();
    f (rectangulo);

    class Rectangulo *rect;
    rect = new Rectangulo [5];
    delete [] rect;

    return 0;
}