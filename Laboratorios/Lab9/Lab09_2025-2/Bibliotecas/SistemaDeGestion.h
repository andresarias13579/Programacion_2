//
// Created by Andres on 25/06/2026.
//

#ifndef LAB09_2025_2_SISTEMADEGESTION_H
#define LAB09_2025_2_SISTEMADEGESTION_H
#include "Categoria.h"
#include "Comentario.h"
#include "Etiqueta.h"
#include "Streamer.h"
#include <list>
#include <map>

class SistemaDeGestion {
private:
    list<Categoria> categorias;
    list<Comentario> comentarios;
    map<string, Etiqueta> etiquetas;
    list <Streamer> streamers;
public:
    void cargarCategorias(const char *nombArch);
    void cargarComentarios(const char *nombArch);
    void cargarEtiquetas(const char *nombArch);
    void cargarStreamers(const char *nombArch);
    void completarStreamers();
    void reporteStreamers(const char *nombArch);
    void eliminarStreamers(string idioma);
};

#endif //LAB09_2025_2_SISTEMADEGESTION_H
