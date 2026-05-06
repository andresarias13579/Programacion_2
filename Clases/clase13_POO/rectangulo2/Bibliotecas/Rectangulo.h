//
// Created by Andres on 5/05/2026.
//

#ifndef RECTANGULO2_RECTANGULO_H
#define RECTANGULO2_RECTANGULO_H

class Rectangulo {
private:
    double base;
    double altura;
    char *nombre;
public:
    Rectangulo();
    Rectangulo(double b, double h, char *nomb) {
        base = b;
        altura = h;
        set_nombre(nombre);
    }
    void inicializar();
    double get_base() const;

    void set_base(const double base);

    double get_altura() const;

    void set_altura(const double altura);

    void mostrar() const;

    void get_nombre(char *nomb) const;

    void set_nombre(char * nombre);
};

#endif //RECTANGULO2_RECTANGULO_H
