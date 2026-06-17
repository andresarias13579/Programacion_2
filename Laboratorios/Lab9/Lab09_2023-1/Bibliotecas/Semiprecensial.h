//
// Created by Andres on 11/06/2026.
//

#ifndef LAB09_2023_1_SEMIPRECENSIAL_H
#define LAB09_2023_1_SEMIPRECENSIAL_H
#include "Alumno.h"

class Semiprecensial : public Alumno {
private:
    double descuento;
    double total;
public:
    Semiprecensial();
    Semiprecensial(const Semiprecensial &semi);
    void operator=(const Semiprecensial &semi);
    void inicializar();
    ~Semiprecensial();
    void eliminar();

    double get_descuento() const;

    void set_descuento(const double descuento);

    double get_total() const;

    void set_total(const double total);
    void leeDatos(ifstream &arch) ;
    void imprimeAlumno(ofstream &arch) ;
};

#endif //LAB09_2023_1_SEMIPRECENSIAL_H
