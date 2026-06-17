//
// Created by Andres on 11/06/2026.
//

#ifndef LAB09_2023_1_VIRTUALES_H

#define LAB09_2023_1_VIRTUALES_H
#include "Alumno.h"

class Virtuales : public Alumno{
private:
    char *licencia;
    double total;
public:
    Virtuales();
    Virtuales(const Virtuales &vir);
    ~Virtuales();
    void operator=(const Virtuales &vir);
    void inicializar();
    void eliminar();

    char * get_licencia(char * lice) const;

    void set_licencia(const char * lice);

    double get_total() const;

    void set_total(const double total);
    void leeDatos(ifstream &arch);
    void imprimeAlumno(ofstream &arch) ;
};

#endif //LAB09_2023_1_VIRTUALES_H
