//
// Created by Andres on 11/06/2026.
//

#ifndef LAB09_2023_1_TESORERIA_H
#define LAB09_2023_1_TESORERIA_H
#include "Boleta.h"
#include "Escala.h"

class Tesoreria {
private:
    Boleta lboleta[100];
    Escala lescala[100];
public:
    void cargaescalas(const char *nombArch);
    void cargaalumnos(const char *nombArch);
    void imprimeboleta(const char *nombArch);
};

#endif //LAB09_2023_1_TESORERIA_H
