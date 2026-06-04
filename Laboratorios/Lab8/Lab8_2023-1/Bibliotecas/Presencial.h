//
// Created by aml on 4/06/2026.
//

#ifndef LAB8_2023_1_PRESENCIAL_H
#define LAB8_2023_1_PRESENCIAL_H
#include "Alumno.h"

class Presencial : public Alumno {
private:
    double recargo;
    double total;

public:
    Presencial();

    Presencial(double recar,double tota, int codigo, const char *nombre, int escala, double tot);

    Presencial(const Presencial &pre);

    ~Presencial();

    void eliminar();

    void operator = (const Presencial &pre);

    void inicializar();

    double get_recargo() const;

    void set_recargo(const double recargo);

    double get_total() const;

    void set_total(const double total);

    void leePresencial(ifstream &arch);

    void actualizar(double monto);
};

#endif //LAB8_2023_1_PRESENCIAL_H