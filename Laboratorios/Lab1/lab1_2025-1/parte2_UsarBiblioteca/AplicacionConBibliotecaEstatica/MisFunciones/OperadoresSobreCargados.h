//
// Created by aml on 9/04/2026.
//

#ifndef BIBLIOTECA_2025_1_FUENTES_OPERADORESSOBRECARGADOS_H
#define BIBLIOTECA_2025_1_FUENTES_OPERADORESSOBRECARGADOS_H

void operator ! (struct CadenaDeCaracteres &cadena);
void operator <= (struct CadenaDeCaracteres &cadena, char* cadenaACopiar);
void operator <= (struct CadenaDeCaracteres &cadena, int cap);
void operator <= (struct CadenaDeCaracteres &cadena1, const struct CadenaDeCaracteres cadena2);
bool operator += (struct CadenaDeCaracteres &cad,const char* cadena);
bool operator += (struct CadenaDeCaracteres &cad,const struct  CadenaDeCaracteres cad2);
int compare (const struct CadenaDeCaracteres &cad, const char*cadena);
bool operator == (const struct CadenaDeCaracteres &cad, const char*cadena);
bool operator < (const struct CadenaDeCaracteres &cad, const char*cadena);
bool operator > (const struct CadenaDeCaracteres &cad, const char*cadena);
int compare (const struct CadenaDeCaracteres &cad1, const struct CadenaDeCaracteres &cad2);
bool operator == (const struct CadenaDeCaracteres cad1, const struct CadenaDeCaracteres cad2);
bool operator < (const struct CadenaDeCaracteres cad1, const struct CadenaDeCaracteres cad2);
bool operator > (const struct CadenaDeCaracteres cad1, const struct CadenaDeCaracteres cad2);
int operator >> (ifstream &arch, struct CadenaDeCaracteres &cad);
void operator && (struct CadenaDeCaracteres &cad1, struct CadenaDeCaracteres &cad2);
ofstream& operator << (ofstream &arch, const struct CadenaDeCaracteres &cad);

#endif //BIBLIOTECA_2025_1_FUENTES_OPERADORESSOBRECARGADOS_H