//
// Created by Andres on 18/06/2026.
//

#ifndef LISTA_PERSONAL_NODO_H
#define LISTA_PERSONAL_NODO_H
#include "Empleado.h"

class Nodo {
private:
    Empleado empleado;
    Nodo *siguiente;
public:
    Nodo();
    void inicializa();
    friend class Lista;
};

#endif //LISTA_PERSONAL_NODO_H
