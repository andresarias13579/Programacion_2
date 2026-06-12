#include <iostream>

using namespace std;
#include "Bibliotecas/Base.h"
#include "Bibliotecas/Derivada1.h"
#include "Bibliotecas/Derivada2.h"

int main() {
    class Base base, *ptB;
    class Derivada1 derivada1;
    class Derivada2 derivada2;
    derivada1.set_d(111);
    derivada1.set_b(222);
    // derivada1.mostrar();

    derivada2.set_d2(555);
    derivada2.set_b(666);
    // derivada2.mostrar();

    ptB = &derivada1;
    ptB->mostrar();

    ptB = &derivada2;
    ptB->mostrar();

    ptB = new Derivada2;
    ptB->set_b(334);
    ptB->mostrar();

    return 0;
}