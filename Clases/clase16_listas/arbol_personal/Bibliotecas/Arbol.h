//
// Created by Andres on 18/06/2026.
//

#ifndef ARBOL_PERSONAL_ARBOL_H
#define ARBOL_PERSONAL_ARBOL_H
#include "Nodo.h"

class Arbol {
private:
    Nodo *raiz;
    void insertarR(Nodo *&arbol,const Empleado &emp);
    void mostrarR(ofstream &arch,Nodo *&arbol);
    Empleado buscarR(Nodo *&arbol, int cod);
    void eliminarR(Nodo *&arbol);
public:
    Arbol();
    ~Arbol();
    void inicializar();
    void eliminar();
    void crear(const char*nombArch);
    void insertar(const Empleado &emp);
    void mostrarEnOrden(const char *nombArch);
    Empleado buscar(int cod);
};

#endif //ARBOL_PERSONAL_ARBOL_H
