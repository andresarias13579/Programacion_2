#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;
#include "BibliotecaEnteros.h"

void *leeNum(ifstream &arch) {
    int dato;
    arch>>dato;
    if (arch.eof()) return nullptr;
    int *numero = new int;
    *numero = dato;
    return (void *)numero;
}
int clasificaEntero(const void *a) {
    int *numero = (int *)a;
    if (*numero < 10) return 1;
    else return 2;
}
void imprimeEntero(ofstream &arch,const void *ptrAux) {
    int *numero = (int *)ptrAux;
    arch<<*numero<<endl;
}
