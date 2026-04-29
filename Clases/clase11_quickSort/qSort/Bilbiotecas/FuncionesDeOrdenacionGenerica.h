//
// Created by Andres on 28/04/2026.
//

#ifndef QSORT_FUNCIONESDEORDENACIONGENERICA_H
#define QSORT_FUNCIONESDEORDENACIONGENERICA_H

void ordenaG(void *arr,int izq,int der, int (*cmp)(const void *,const void*));
void cambiar(void *&a,void *&b);

#endif //QSORT_FUNCIONESDEORDENACIONGENERICA_H
