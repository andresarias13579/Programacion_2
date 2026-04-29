#include <iostream>

using namespace std;
#include "FuncionesDeEnteris.h"

int intcmpA(const void *a, const void *b) {
    int *ai = (int *)a, *bi = (int *)b;
    return *ai - *bi;
}
int intcmpB(const void *a, const void *b) {
    int *ai = (int *)a, *bi = (int *)b;
    return  *bi - *ai;
}