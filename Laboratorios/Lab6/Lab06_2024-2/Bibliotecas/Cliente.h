//
// Created by Andres on 14/05/2026.
//

#ifndef LAB06_2024_2_CLIENTE_H
#define LAB06_2024_2_CLIENTE_H

class Cliente {
    private:
    int dni;
    char *nombre;
    char *distrito;
    double descuento;
    double totalPagado;

    public:
    Cliente();

    Cliente(const Cliente &cliente);

    ~Cliente();

    void eliminar();

    void operator=(const Cliente &cliente);

    void inicializar();

    int get_dni() const;

    void set_dni(const int dni);

    char * get_nombre(char *nomb) const;

    void set_nombre(char * const nomb);

    char * get_distrito(char *dist) const;

    void set_distrito(char * const dist);

    double get_descuento() const;

    void set_descuento(const double descuento);

    double get_total_pagado() const;

    void set_total_pagado(const double total_pagado);

    void imprimir(ofstream &arch) const;
};

void operator >> (ifstream &arch, Cliente &origen);
void operator << (ofstream &arch, const Cliente &origen);

#endif //LAB06_2024_2_CLIENTE_H
