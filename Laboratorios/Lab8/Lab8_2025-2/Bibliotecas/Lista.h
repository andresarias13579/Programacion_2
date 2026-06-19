//
// Created by alulab14 on 18/06/2026.
//

#ifndef LAB8_2025_2_LISTA_H
#define LAB8_2025_2_LISTA_H
#include "Nodo.h"

class Lista {
private:
    Nodo *listaDoblementeLigada;
public:
    Lista();
    ~Lista();
    void inicializa();
    void eliminar();
    void crear(ifstream &arch);
    void insertar(Metrica *metrica);
    void imprimeLinea(ofstream &arch, char line);
    void imprimirReporte(ofstream &arch);
    void eliminaMetricasExpiradas();
};

#endif //LAB8_2025_2_LISTA_H
