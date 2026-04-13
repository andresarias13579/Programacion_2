#include <iostream>
#include <iomanip>

using namespace std;
#include "Persona.h"
#include "sobreCargas.h"

void operator +=(struct Persona &persona, double porc) {
    persona.sueldo *= (1+porc/100);
}

//para casos fijos como para imprimir, es obligatorio el uso del const
// void operator <<(ostream &out,const struct Persona &persona){
//     //se usa el 'out' que definimos en el ostream
//     out<<"DNI = "<<persona.dni<<endl;
//     out<<"Nombre = "<<persona.nombre<<endl;
//     out<<"Sueldo = "<<persona.sueldo<<endl;
// }

//ejemplo para que funcione un cout<<persona<<persona2, all en cadena
ostream &operator <<(ostream &out,const struct Persona &persona){
    //se usa el 'out' que definimos en el ostream
    out<<"DNI = "<<persona.dni<<endl;
    out<<"Nombre = "<<persona.nombre<<endl;
    out<<"Sueldo = "<<persona.sueldo<<endl;
    return out;
}
