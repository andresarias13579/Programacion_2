//
// Created by aml on 14/05/2026.
//

#ifndef LAB06_2025_1_EMPRESA_H
#define LAB06_2025_1_EMPRESA_H

#include "Multa.h"

class Empresa {
    private:
    int dni;
    char * nombre;
    char *placas[10];
    int numPlacas;
    class Multa multas[100];
    int numMultas;

    public:
    Empresa();

    ~Empresa();

    void liberar();

    void inicializar();

    int get_dni() const;

    void set_dni(const int dni);

    char * get_nombre(char * nomb) const;

    void set_nombre(char * const nomb);

    int get_num_placas() const;

    void set_num_placas(const int num_placas);

    int get_num_multas() const;

    void set_num_multas(const int num_multas);

    void setPlacaI(const char* plac, int i);

    void getPlacaI(char * plac, int i);

    void leeArch(ifstream &arch);

    void operator += (Multa &multa);

    void imprimir(ofstream &arch) const;
};

void operator>>(ifstream &arch, Empresa &origen);
void operator <<(ofstream &arch, const Empresa &origen);

#endif //LAB06_2025_1_EMPRESA_H