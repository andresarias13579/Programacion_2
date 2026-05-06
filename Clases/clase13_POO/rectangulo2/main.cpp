#include <iostream>
using namespace std;
#include "Bibliotecas/Rectangulo.h"

int main() {
    class Rectangulo rect;
    char nomb[100];
    rect.set_altura(7.03);
    rect.set_base(3.75);
    rect.set_nombre("Juan Perez");
    rect.get_nombre(nomb);
    rect.mostrar();

    return 0;
}