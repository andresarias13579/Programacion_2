//
// Created by aml on 4/06/2026.
//

#ifndef LAB8_2023_1_SEMIPRESENCIAL_H
#define LAB8_2023_1_SEMIPRESENCIAL_H
#include "Alumno.h"

class Semipresencial : public Alumno {
private:
    double descuento;
    double total;

public:
    Semipresencial();

    Semipresencial(double descuento, double total, int codigo, const char*nombre, int escala,
        double tot);

    Semipresencial(const Semipresencial &semi);

    ~Semipresencial();

    void eliminar();

    void operator = (const Semipresencial &semi);

    void inicializa();

    double get_descuento() const;

    void set_descuento(const double descuento);

    double get_total() const;

    void set_total(const double total);

    void leeSemipresencial(ifstream &arch);

    void actualizar(double monto);

    void mostrar(ofstream &arch);
};

#endif //LAB8_2023_1_SEMIPRESENCIAL_H