#include <iostream>

using namespace std;
#include "FuncionesDeEnteros.h"

int comparaEnteros(const void* a,const void* b) {
    long long aI = (long long) a, bI = (long long) b;
    return (aI - bI);
}
