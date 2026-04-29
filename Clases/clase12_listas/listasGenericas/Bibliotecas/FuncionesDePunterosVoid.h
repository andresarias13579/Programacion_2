//
// Created by Andres on 29/04/2026.
//

#ifndef LISTASGENERICAS_FUNCIONESDEPUNTEROSVOID_H
#define LISTASGENERICAS_FUNCIONESDEPUNTEROSVOID_H

void* leeRegistro(ifstream &arch);
int compararDni(const void* a, const void* b);
int compararNom(const void* a, const void* b);
int compararSueldo(const void* a, const void* b);
void imprimirRegistro(ofstream &arch,void *dato);

#endif //LISTASGENERICAS_FUNCIONESDEPUNTEROSVOID_H
