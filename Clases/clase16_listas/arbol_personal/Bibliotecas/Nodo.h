//
// Created by Andres on 18/06/2026.
//

#ifndef ARBOL_PERSONAL_NODO_H
#define ARBOL_PERSONAL_NODO_H
#include "Empleado.h"

class Nodo {
private:
    Empleado dato;
    Nodo *izquierda;
    Nodo *derecha;
public:
    Nodo();
    void inicializar();
    friend class Arbol;
};

#endif //ARBOL_PERSONAL_NODO_H
