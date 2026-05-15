#include <iostream>
using namespace std;
#include "Bibliotecas/Rectangulo.h"

void f (const class Rectangulo &rect) {
    rect.mostrar();
    rect.get_base();
}

int main() {
    class Rectangulo rectangulo;
    rectangulo.set_altura(5);
    rectangulo.set_base(8);
    rectangulo.mostrar();
    f (rectangulo);

    return 0;
}