#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "Persona.h"
#include "Empleados.h"
#include "Operadores.h"

void operator <<(struct Empleados &empleados, const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR. NO SE PUDO ENCONTRAR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    struct Persona persona{};
    int &numPersonas = empleados.numEmpleados; //OJO, aca no es que se cree una variable. Gracias al & es como si se le diera un nombre corto al empleados.numEmpleados
    while (true) {
        arch >> persona;
        empleados.empleados[numPersonas] = persona;
        numPersonas++;
        if (arch.eof()) break;
    }
}
void operator >> (ifstream &arch, struct Persona &persona) {
    arch>>persona.dni;
    if (arch.eof()) return;
    arch.get();
    arch.getline(persona.nombre,100,',');
    arch>>persona.sueldo;
}
void operator <<(const char*nombArch, const struct Empleados &empleados) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR. NO SE PUDO ENCONTRAR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    for (int i = 0; i < empleados.numEmpleados ; i++) {
        arch << empleados.empleados[i];
    }
}
void operator <<(ofstream &arch, const struct Persona &persona) {
    arch<<setw(10)<<persona.dni<<"  "<<left<<setw(40)<<persona.nombre<<right<<setw(10)<<persona.sueldo<<endl;
}
void operator *=(struct Empleados &empleados, double aumento) {
    for (int i = 0; i < empleados.numEmpleados; ++i) {
        empleados.empleados[i] *= aumento;
    }
}
void operator *=(struct Persona &persona, double aumento) {
    persona.sueldo *= (1 + aumento/100);
}
void operator ++ (struct Empleados &empleados) {
    qsort(empleados.empleados,0,empleados.numEmpleados-1);
}
void qsort(struct Persona *personas,int izq,int der) {
    int limite, pMedio;
    if (izq >= der) return;
    pMedio = (izq + der) / 2;
    cambiar(personas[izq],personas[pMedio]);
    limite = izq;
    for (int i = izq+1; i <= der; ++i) {
        if (strcmp(personas[i].nombre,personas[izq].nombre) < 0)
            cambiar(personas[i],personas[++limite]);
    }
    cambiar(personas[izq],personas[limite]);
    qsort(personas,izq,limite-1);
    qsort(personas,limite+1,der);
}
void cambiar(struct Persona &a, struct Persona &b) {
    struct Persona aux;
    aux = a;
    a = b;
    b = aux;
}
