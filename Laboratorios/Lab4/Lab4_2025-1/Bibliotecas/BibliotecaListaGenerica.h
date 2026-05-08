//
// Created by Andres on 7/05/2026.
//

#ifndef LAB4_2025_1_BIBLIOTECALISTAGENERICA_H
#define LAB4_2025_1_BIBLIOTECALISTAGENERICA_H

void creaLista(void *&lista,void *(leeNum)(ifstream &arch),int (*clasificaEntero)(const void *a),const char*nombArch);
void generaLista(void *&lista);
void insertaLista(void *&list,void *dato,int (*clasificaEntero)(const void *a));
void insertaBloque(void *stop,void *bloque, void *dato);
void imprimeLista(void *lista,void (*imprimeEntero)(ofstream &arch,const void *dato),const char *nombreArch);

#endif //LAB4_2025_1_BIBLIOTECALISTAGENERICA_H
