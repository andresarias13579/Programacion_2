//
// Created by alulab14 on 18/06/2026.
//

#ifndef LAB8_2025_2_ADMINISTRARMETRICAS_H
#define LAB8_2025_2_ADMINISTRARMETRICAS_H
#include "Lista.h"

class AdministrarMetricas {
private:
    Lista listaDeMetricas;
public:
    void cargarArchivo(const char *nombArch);
    void generarReporte(const char* nombArch);
    void eliminarNodos();
    void eliminarLista();
};

#endif //LAB8_2025_2_ADMINISTRARMETRICAS_H
