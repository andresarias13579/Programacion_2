//
// Created by Andres on 14/05/2026.
//

#ifndef LAB06_2024_2_PLATO_H
#define LAB06_2024_2_PLATO_H

class Plato {
    private:
    char *codigo;
    char *nombre;
    double precio;
    char* categoria;
    double descuento;
    int preparados;
    int atendidos;
    int noAtendidos;
    double totalEsperado;
    double totalBruto;
    double totalNeto;

    public:
    Plato();

    Plato(const Plato &plato);

    ~Plato();

    void eliminar();

    void operator=(const Plato &plato);

    void inicializar();

    char * get_codigo(char *cod) const;

    void set_codigo(char * const cod);

    char * get_nombre(char *nomb) const;

    void set_nombre(char * const nomb);

    double get_precio() const;

    void set_precio(const double precio);

    char * get_categoria(char *cat) const;

    void set_categoria(char * const cat);

    double get_descuento() const;

    void set_descuento(const double descuento);

    int get_preparados() const;

    void set_preparados(const int preparados);

    int get_atendidos() const;

    void set_atendidos(const int atendidos);

    int get_no_atendidos() const;

    void set_no_atendidos(const int no_atendidos);

    double get_total_esperado() const;

    void set_total_esperado(const double total_esperado);

    double get_total_bruto() const;

    void set_total_bruto(const double total_bruto);

    double get_total_neto() const;

    void set_total_neto(const double total_neto);

    void imprimir(ofstream &arch) const;
};

void operator >> (ifstream &arch, Plato &plato);
void operator << (ofstream &arch, const Plato &plato);

#endif //LAB06_2024_2_PLATO_H
