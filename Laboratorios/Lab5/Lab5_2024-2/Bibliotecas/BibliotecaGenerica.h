//
// Created by Andres on 7/05/2026.
//

#ifndef LAB5_2024_2_BIBLIOTECAGENERICA_H
#define LAB5_2024_2_BIBLIOTECAGENERICA_H

void creaLista(void *&lista,void *(leeNumeros)(ifstream &arch),const char*nombArch);
void construir(void *&list);
void insertarOrdenado(void *list, void *dato);
void insertarDato(void *&dobles, void *dato);
bool esListaVacia(void *list);

#endif //LAB5_2024_2_BIBLIOTECAGENERICA_H
