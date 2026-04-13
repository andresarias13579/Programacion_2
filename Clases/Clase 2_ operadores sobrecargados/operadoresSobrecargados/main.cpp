#include <iostream>
#include <iomanip>

using namespace std;
#include "Bibliotecas/Persona.h"
#include "Bibliotecas/sobreCargas.h"

int main() {
    struct Persona persona {11223344,"Juan Perez", 2345.67},
        persona2 {77331155,"Ana Rojas", 9876.5};

    persona += 25; //se busca aumentar el sueldo en porcentaje

    //ya sobrecargado el operador +=
    // cout<<"DNI = "<<persona.dni<<endl;
    // cout<<"Nombre = "<<persona.nombre<<endl;
    // cout<<"Sueldo = "<<persona.sueldo<<endl;
    //
    // cout<<"DNI = "<<persona2.dni<<endl;
    // cout<<"Nombre = "<<persona2.nombre<<endl;
    // cout<<"Sueldo = "<<persona2.sueldo<<endl;

    //aqui sobrecargamos el <<
    // cout << persona ;
    // cout << persona2;

    //practicamos all en cadena
    cout <<persona << persona2;

    return 0;
}