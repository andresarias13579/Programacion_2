#include <iostream>

using namespace std;
#include "plantilla.h"
#include "Persona.h"

int main() {
    // class Plantilla<int> objInt;
    // objInt.set_dato(153);
    // objInt.imprimirDato();
    //
    // class Plantilla<double> objDouble;
    // objDouble.leeDato();
    // objDouble.imprimirDato();
    //
    // string nombre;
    // class Plantilla<string> objString;
    // objString.leeDato();
    // objString.imprimirDato();
    // nombre = objString.get_dato();
    // nombre = nombre + " Arias";
    // cout << nombre << endl;
    // cout << nombre.length() << endl;

    class Plantilla <class Persona> objPersona;
    //73123456,Andres Mendoza,2500.50       <---- copiar eso en la terminal para que lea
    objPersona.leeDato();
    objPersona.imprimirDato();

    return 0;
}