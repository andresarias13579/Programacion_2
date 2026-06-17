//
// Created by Andres on 11/06/2026.
//

#ifndef LAB09_2023_1_BOLETA_H
#define LAB09_2023_1_BOLETA_H
#include "Alumno.h"

class Boleta {
private:
    Alumno *pboleta;
public:
    Boleta();
    void inicializar();
    ~Boleta();
    void eliminar();
    void asignaMemoria(char tipo);
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    bool hayDato();
};

#endif //LAB09_2023_1_BOLETA_H
