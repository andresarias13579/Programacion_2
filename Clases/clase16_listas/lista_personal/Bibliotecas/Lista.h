//
// Created by Andres on 18/06/2026.
//

#ifndef LISTA_PERSONAL_LISTA_H
#define LISTA_PERSONAL_LISTA_H

class Lista {
private:
    class Nodo *lista;
    void imprimirR(ofstream &arch,Nodo *recorrido);
public:
    Lista();
    ~Lista();
    void inicializa();
    void elimina();
    void crear(const char* nombArch);
    void insertar(const Empleado &dato);
    void imprimir(const char*nombArch);
    void imprimirRecursivo(const char*nombArch);
};

#endif //LISTA_PERSONAL_LISTA_H
