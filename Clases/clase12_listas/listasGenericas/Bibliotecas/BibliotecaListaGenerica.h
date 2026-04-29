//
// Created by Andres on 29/04/2026.
//

#ifndef LISTASGENERICAS_BIBLIOTECALISTAGENERICA_H
#define LISTASGENERICAS_BIBLIOTECALISTAGENERICA_H

void crearLista(const char*nombArch, void *&lista, void *(lee)(ifstream &arch),int (*comparar)(const void*,const void*));
void insertar(void *dato,void *&lista,int (*comparar)(const void*,const void*));
void imprimirLista(const char*nombArch, void *&lst, void (*imprimir)(ofstream &arch,void *dato));

#endif //LISTASGENERICAS_BIBLIOTECALISTAGENERICA_H
