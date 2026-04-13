#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "CadenaDeCaracteres.h"
#include "OperadoresSobreCargados.h"

void operator ! (struct CadenaDeCaracteres &cadena) {
    cadena.cadena = nullptr;
    cadena.capacidad = 0;
    cadena.longitud = 0;
}
void operator <= (struct CadenaDeCaracteres &cadena, char* cadenaACopiar) {
    if (cadenaACopiar == nullptr or strlen(cadenaACopiar) == 0) return;
    if ( cadena.cadena != nullptr) {
        if (strcmp(cadena.cadena, cadenaACopiar) != 0 and cadena.capacidad < strlen(cadenaACopiar)) {
            delete [] cadena.cadena;
        }
    }
    if (cadena.cadena == nullptr or cadena.capacidad < strlen(cadenaACopiar)) cadena <= strlen(cadenaACopiar)+1;
    strcpy(cadena.cadena, cadenaACopiar);
    cadena.longitud = strlen(cadenaACopiar);
}
void operator <= (struct CadenaDeCaracteres &cadena, int cap) {
    cadena.cadena = new char[cadena.capacidad = cap];
    cadena.longitud = 0;
}
void operator <= (struct CadenaDeCaracteres &cadena1, const struct CadenaDeCaracteres cadena2) {
    cadena1 <= cadena2.cadena;
}
bool operator += (struct CadenaDeCaracteres &cad,const char* cadena) {
    if (cad.cadena == nullptr) return false;
    if (strlen(cad.cadena) + strlen(cadena) > cad.capacidad) {
        char auxiliar[strlen(cad.cadena) + strlen(cad.cadena) + 1];
        strcpy(auxiliar, cad.cadena);
        strcat(auxiliar, cadena);
        delete [] cad.cadena;
        cad <= strlen(auxiliar) +1 ;
        strcpy(cad.cadena, auxiliar);
    } else {
        strcat(cad.cadena, cadena);
    }
    cad.longitud = strlen(cad.cadena);
    return true;
}
bool operator += (struct CadenaDeCaracteres &cad,const struct  CadenaDeCaracteres cad2) {
    return cad += cad2.cadena;
}
int compare (const struct CadenaDeCaracteres &cad, const char*cadena) {
    char *aux1 = new char[strlen(cad.cadena)+1], *aux2 = new char[strlen(cadena)+1];
    strcpy(aux1, cad.cadena);
    strcpy(aux2, cadena);
    for (int i = 0; aux1[i]; ++i) if (aux1[i]>= 'a' and aux1[i] <= 'z') aux1[i] = aux1[i] - 32;
    for (int i = 0; aux2[i]; ++i) if (aux2[i]>= 'a' and aux2[i] <= 'z') aux2[i] = aux2[i] - 32;
    if (strcmp(aux1, aux2) == 0) return 0;
    else if (strcmp(aux1, aux2) > 0) return 1;
    else return -1;
    delete []aux1;
    delete []aux2;
}
bool operator == (const struct CadenaDeCaracteres &cad, const char*cadena) {
    int valor;
    valor = compare(cad,cadena);
    if (valor == 0) return true;
    else return false;
}
bool operator < (const struct CadenaDeCaracteres &cad, const char*cadena) {
    int valor;
    valor = compare(cad,cadena);
    if (valor < 0) return true;
    else return false;
}
bool operator > (const struct CadenaDeCaracteres &cad, const char*cadena) {
    int valor;
    valor = compare(cad,cadena);
    if (valor == 0) return true;
    else return false;
}
int compare (const struct CadenaDeCaracteres &cad1, const struct CadenaDeCaracteres &cad2) {
    return compare(cad1,cad2.cadena);
}
bool operator == (const struct CadenaDeCaracteres cad1, const struct CadenaDeCaracteres cad2) {
    int valor;
    valor = compare(cad1,cad2);
    if (valor == 0) return true;
    else return false;
}
bool operator < (const struct CadenaDeCaracteres cad1, const struct CadenaDeCaracteres cad2) {
    int valor;
    valor = compare(cad1,cad2);
    if (valor < 0) return true;
    else return false;
}
bool operator > (const struct CadenaDeCaracteres cad1, const struct CadenaDeCaracteres cad2) {
    int valor;
    valor = compare(cad1,cad2);
    if (valor > 0) return true;
    else return false;
}
int operator >> (ifstream &arch, struct CadenaDeCaracteres &cad) {
    char buffer[100];
    arch >> buffer;
    if (arch.eof()) return 1;
    if (buffer[0]>='A' and buffer[0]<='z') return -1;
    cad <= buffer;
    return 0;
}
void operator && (struct CadenaDeCaracteres &cad1, struct CadenaDeCaracteres &cad2) {
    struct CadenaDeCaracteres aux;
    aux = cad1;
    cad1 = cad2;
    cad2 = aux;
}
ofstream& operator << (ofstream &arch, const struct CadenaDeCaracteres &cad) {
    arch << cad.cadena;
    return arch;
}