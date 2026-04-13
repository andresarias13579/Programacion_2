#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Bibliotecas/CadenaDeCaracteres.h"
#include "Bibliotecas/OperadoresSobreCargados.h"

int main() {
    //1 !
    struct CadenaDeCaracteres cadena,cadena2;
    !cadena;
    !cadena2;
    cout << cadena.longitud<<"  "<<cadena.capacidad << endl;
    //2 <=
    cadena <= "Edwin Carlos Andres Arias Villanueva";
    cout << cadena.longitud<<" "<<cadena.capacidad<<"    "<<cadena.cadena<< endl;
    cadena2 <= "Jakeline";
    cadena <= cadena2;
    cout << cadena.longitud<<" "<<cadena.capacidad<<"    "<<cadena.cadena<< endl;
    cadena <= "Edwin Carlos Andres Arias Villanueva";
    cout << cadena.longitud<<" "<<cadena.capacidad<<"    "<<cadena.cadena<< endl;
    //3 +=
    cadena += " tiene 20 anhos";
    cout << cadena.longitud<<" "<<cadena.capacidad<<"    "<<cadena.cadena<< endl;
    cadena <= cadena2;
    cout << cadena.longitud<<" "<<cadena.capacidad<<"    "<<cadena.cadena<< endl;
    cadena += "Jakeline";
    cout << cadena.longitud<<" "<<cadena.capacidad<<"    "<<cadena.cadena<< endl;
    if (cadena += cadena2) cout << cadena.cadena << endl;
    else cout << "cadena vacia";
    //4
    int valor;
    cadena <= "Andres";
    cadena2 <= "Jakeline";
    valor = compare(cadena2,cadena.cadena);
    cout << valor << endl;

    return 0;
}