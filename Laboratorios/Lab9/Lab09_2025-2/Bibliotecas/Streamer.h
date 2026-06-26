//
// Created by Andres on 25/06/2026.
//

#ifndef LAB09_2025_2_STREAMER_H
#define LAB09_2025_2_STREAMER_H
#include <vector>

#include "Categoria.h"
#include "Etiqueta.h"
#include "Comentario.h"

class Streamer {
private:
    string canal;
    int fecha;
    Categoria categoria;
    string etiquetasStr;
    vector<Etiqueta> etiquetasVector;
    string idioma;
    vector<string> comentarios;
public:
    Streamer();
    Streamer(const Streamer &st);
    void operator=(const Streamer &st);

    string get_canal() const;

    void set_canal(const string &canal);

    int get_fecha() const;

    void set_fecha(const int fecha);

    Categoria get_categoria() const;

    void set_categoria(const Categoria &categoria);

    string get_etiquetas_str() const;

    void set_etiquetas_str(const string &etiquetas_str);

    vector<Etiqueta> get_etiquetas_vector() const;

    void set_etiquetas_vector(const vector<Etiqueta> &etiquetas_vector);

    string get_idioma() const;

    void set_idioma(const string &idioma);

    vector<string> get_comentarios() const;

    void set_comentarios(const vector<string> &comentarios);

    void lee(ifstream &arch);
    void imprimir(ofstream &arch) const;

    bool operator < (const Streamer &st);
};
void operator >> (ifstream &arch, Streamer &st);
void operator<<(ofstream &arch, const Streamer &st);

#endif //LAB09_2025_2_STREAMER_H
