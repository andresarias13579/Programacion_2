//
// Created by Andres on 11/06/2026.
//

#ifndef LAB09_2023_1_PRESENCIAL_H
#define LAB09_2023_1_PRESENCIAL_H
#include "Alumno.h"

class Presencial : public Alumno{
private:
    double recargo;
    double total;
public:
    Presencial();
    Presencial(const Presencial &pre);
    void operator=(const Presencial &pre);
    ~Presencial();
    void eliminar();
    void inicializar();

    double get_recargo() const;

    void set_recargo(const double recargo);

    double get_total() const;

    void set_total(const double total);
    void leeDatos(ifstream &arch) ;
    void imprimeAlumno(ofstream &arch) ;
};

#endif //LAB09_2023_1_PRESENCIAL_H
