//
// Created by alulab14 on 18/06/2026.
//

#ifndef LAB8_2025_2_NODO_H
#define LAB8_2025_2_NODO_H
#include "Metrica.h"

class Nodo {
private:
    Metrica *metrica;
    Nodo *anterior;
    Nodo *siguiente;
public:
    Nodo();
    void inicializar();
    friend class Lista;
};

#endif //LAB8_2025_2_NODO_H
