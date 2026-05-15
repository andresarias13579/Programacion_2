//
// Created by aml on 14/05/2026.
//

#ifndef RECTANGULO_USANDOIDE_PROPIO_RECTANGULO_H
#define RECTANGULO_USANDOIDE_PROPIO_RECTANGULO_H

class Rectangulo {
    private:
    double base;
    double altura;

    public:
    double get_base() const;

    void set_base(const double base);

    double get_altura() const;

    void set_altura(const double altura);

    void mostrar() const;
};

#endif //RECTANGULO_USANDOIDE_PROPIO_RECTANGULO_H