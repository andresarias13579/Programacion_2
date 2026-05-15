//
// Created by aml on 14/05/2026.
//

#ifndef LAB06_2025_1_MULTA_H
#define LAB06_2025_1_MULTA_H

class Multa {
    private:
    char *placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoInfraccion;
    double multa;

    public:
    Multa();

    Multa(const Multa &mul);

    ~Multa();

    void liberar();

    void operator = (const Multa &mul);

    void inicializar();

    char * get_placa(char *plac) const;

    void set_placa(char * const placa);

    int get_fecha_de_infraccion() const;

    void set_fecha_de_infraccion(const int fecha_de_infraccion);

    int get_fecha_de_pago() const;

    void set_fecha_de_pago(const int fecha_de_pago);

    int get_codigo_infraccion() const;

    void set_codigo_infraccion(const int codigo_infraccion);

    double get_multa() const;

    void set_multa(const double multa);

    void leeArch(ifstream &arch);

    void imprimirArch(ofstream &arch) const;
};

void operator >> (ifstream &arch, Multa &origen);
void operator << (ofstream &arch, const Multa &origen);

#endif //LAB06_2025_1_MULTA_H