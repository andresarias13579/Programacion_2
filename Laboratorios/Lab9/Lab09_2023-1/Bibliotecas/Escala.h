//
// Created by Andres on 11/06/2026.
//

#ifndef LAB09_2023_1_ESCALA_H
#define LAB09_2023_1_ESCALA_H

class Escala {
private:
    int codigo;
    double precio;
public:
    Escala();
    Escala(const Escala &esc);
    ~Escala();
    void operator=(const Escala &esc);
    void inicializar();
    void eliminar();

    int get_codigo() const;

    void set_codigo(const int codigo);

    double get_precio() const;

    void set_precio(const double precio);
    void leeEscala(ifstream &arch);
};

#endif //LAB09_2023_1_ESCALA_H
