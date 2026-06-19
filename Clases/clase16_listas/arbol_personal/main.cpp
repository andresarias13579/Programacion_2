#include <iostream>

using namespace std;
#include "Bibliotecas/Empleado.h"
#include "Bibliotecas/Nodo.h"
#include "Bibliotecas/Arbol.h"

int main() {
    Arbol arbol;
    arbol.crear("personal.csv");
    arbol.mostrarEnOrden("Reporte en orden.txt");

    Empleado empleado = arbol.buscar(640279);
    char nombre[50];
    cout<<empleado.get_nombre(nombre)<<endl;

    return 0;
}