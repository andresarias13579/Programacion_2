//
// Created by Andres on 5/04/2026.
//

#ifndef OPERADORES_H
#define OPERADORES_H

void operator <<(struct Empleados &empleados, const char*nombArch);
void operator >> (ifstream &arch, struct Persona &persona);
void operator <<(const char*nombArch, const struct Empleados &empleados);
void operator <<(ofstream &arch, const struct Persona &empleados);
void operator *=(struct Empleados &empleados, double aumento);
void operator *=(struct Persona &persona, double aumento);
void operator ++ (struct Empleados &empleados);
void qsort(struct Persona *personas,int izq,int der);
void cambiar(struct Persona &a, struct Persona &b);

#endif //OPERADORES_H
