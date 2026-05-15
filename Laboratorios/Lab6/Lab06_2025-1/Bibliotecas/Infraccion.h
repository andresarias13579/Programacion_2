//
// Created by aml on 14/05/2026.
//

#ifndef LAB06_2025_1_INFRACCION_H
#define LAB06_2025_1_INFRACCION_H

class Infraccion {
    private:
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;

    public:
    Infraccion();

    Infraccion(const Infraccion & infraccion);

    ~Infraccion();

    void operator =(const Infraccion & infraccion);

    void inicializar();

    void liberar();

    int get_codigo() const;

    void set_codigo(const int codigo);

    char * get_descripcion(char *desc) const;

    void set_descripcion(char * const desc);

    char * get_gravedad(char * grav) const;

    void set_gravedad(char * const grav);

    double get_multa() const;

    void set_multa(const double multa);

    void leeArch(ifstream &arch);

    void imprimir(ofstream &arch) const;
};

void operator >> (ifstream &arch, Infraccion & origen);
void operator << (ofstream &arch, const Infraccion & origen);

#endif //LAB06_2025_1_INFRACCION_H