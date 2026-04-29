#include <iostream>

using namespace std;
#include "FuncionesDeOrdenacionGenerica.h"

void ordenaG(void *arr,int izq,int der, int (*cmp)(const void *,const void*)) {
    void **arreglo = (void**)arr;
    int limite = izq;
    if (izq>=der) return;
    cambiar(arreglo[izq],arreglo[((izq+der)/2)]);
    for (int i=izq+1; i<=der; i++) {
        if (cmp(arreglo[izq],arreglo[der]) > 0) cambiar(arreglo[i],arreglo[++limite]);
    }
    cambiar(arreglo[izq],arreglo[limite]);
    ordenaG(arreglo,izq,limite-1,cmp);
    ordenaG(arreglo,limite+1,der,cmp);
}
void cambiar(void *&a,void *&b) {
    void *aux = a;
    a = b;
    b = aux;
}