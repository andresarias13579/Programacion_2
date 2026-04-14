//
// Created by Andres on 14/04/2026.
//

#ifndef LAB2_ANDRES_ESTRUCTURAS_H
#define LAB2_ANDRES_ESTRUCTURAS_H

struct Conductores {
    int *dnis;
    char **nombres;
    int cantidad;
};

struct Infracciones {
    int *codigos;
    char **descripciones;
    char **tipos;
    double *valores;
    int cantidad;
};

struct Faltas {
    Conductores conductores;
    Infracciones infracciones;
    char ***placas;
    int *capacidades;
};

#endif //LAB2_ANDRES_ESTRUCTURAS_H
