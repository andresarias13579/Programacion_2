//
// Created by aml on 4/06/2026.
//

#ifndef LAB8_2023_1_ESCALA_H
#define LAB8_2023_1_ESCALA_H

class Escala {
private:
    int codigo;
    double precio;

public:
    Escala();

    Escala(int cod,double prec);

    Escala(const Escala &esc);

    ~Escala();

    void eliminar();

    void operator = (const Escala &esc);

    void inicializar();

    int get_codigo() const;

    void set_codigo(const int codigo);

    double get_precio() const;

    void set_precio(const double precio);

    void leeEscala(ifstream &arch);
};

#endif //LAB8_2023_1_ESCALA_H