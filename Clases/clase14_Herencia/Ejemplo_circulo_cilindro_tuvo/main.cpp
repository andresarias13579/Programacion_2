#include <iostream>

using namespace std;
#include "Bibliotecas/Circulo.h"
#include "Bibliotecas/Cilindro.h"

int main() {
    class Circulo circulo;
    circulo.set_nombre("Andres");
    circulo.set_radio(4);
    circulo.mostrarResultados();

    class Cilindro cilindro;
    cilindro.set_nombre("Carlos");
    cilindro.set_radio(3);
    cilindro.set_altura(4);
    cilindro.mostrarResultados();

    return 0;
}