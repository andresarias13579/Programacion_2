#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "FuncionesDePunterosVoid.h"
enum REG {DNI,NOM,SUE};

void* leeRegistro(ifstream &arch) {
    int *dni,d;
    char *nombre,nomb[60],c;
    double *sueldo;
    void **registro;
    arch>>d;
    if (arch.eof()) return nullptr;
    dni = new int;
    *dni = d;
    arch>>c;
    arch.getline(nomb,60,',');
    nombre = new char[strlen(nomb)];
    strcpy(nombre,nomb);
    sueldo = new double;
    arch>>*sueldo;
    registro = new void*[3]{};
    registro[DNI] = dni;
    registro[NOM] = nombre;
    registro[SUE] = sueldo;
    return registro;
}
int compararDni(const void* a, const void* b) {
    void **regA = (void**) a, **regB = (void **) b ;
    int *dniA = (int *)regA[DNI], *dniB = (int *)regB[DNI];
    return *dniA - *dniB;
}
int compararNom(const void* a, const void* b) {
    void **regA = (void**) a, **regB = (void **) b ;
    char *nombA = (char *)regA[NOM], *nombB = (char *)regB[NOM];
    return strcmp(nombA,nombB);
}
int compararSueldo(const void* a, const void* b) {
    void **regA = (void**) a, **regB = (void **) b ;
    double *suelA = (double *)regA[SUE], *suelB = (double *)regB[SUE];
    return *suelA - *suelB;
}
void imprimirRegistro(ofstream &arch,void *dato) {
    void  **reg = (void **) dato;
    int *dni = (int *)reg[DNI];
    double *sueldo = (double *)reg[SUE];
    char *nombre = (char *)reg[NOM];
    arch<<setw(10)<<*dni<<setw(40)<<nombre<<setw(10)<<*sueldo<<endl;
}
