//
// Created by aml on 4/06/2026.
//

#ifndef EJEMPLO_CIRCULO_CILINDRO_TUVO_CILINDRO_H
#define EJEMPLO_CIRCULO_CILINDRO_TUVO_CILINDRO_H
#include "Circulo.h"

class Cilindro : public Circulo {
private:
    double altura;
public:
    Cilindro();

    Cilindro(double altura,double rad, const char* nomb);

    Cilindro(const Cilindro &cili);

    void operator = (const Cilindro &cili);

    void inicializar();

    double get_altura() const;

    void set_altura(const double altura);

    double volumen();

    double area();

    void mostrarResultados();
};

#endif //EJEMPLO_CIRCULO_CILINDRO_TUVO_CILINDRO_H