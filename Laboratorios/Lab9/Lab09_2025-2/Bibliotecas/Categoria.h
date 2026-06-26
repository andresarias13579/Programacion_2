//
// Created by Andres on 25/06/2026.
//

#ifndef LAB09_2025_2_CATEGORIA_H
#define LAB09_2025_2_CATEGORIA_H
#include "Etiqueta.h"

class Categoria {
private:
    string codigo;
    string nombrea;
    string descripcion;

public:

    Categoria();
    Categoria(const Categoria &cat);

    void operator=(const Categoria &cat);

    string get_codigo() const;

    void set_codigo(const string &codigo);

    string get_nombrea() const;

    void set_nombrea(const string &nombrea);

    string get_descripcion() const;

    void set_descripcion(const string &descripcion);

    void lee(ifstream &arch);
    void imprime(ofstream &arch) const;
    bool operator < (const Categoria &cat);
};

void operator >> (ifstream &arch, Categoria &eti);
void operator << (ofstream &arch,const Categoria &eti);

#endif //LAB09_2025_2_CATEGORIA_H
