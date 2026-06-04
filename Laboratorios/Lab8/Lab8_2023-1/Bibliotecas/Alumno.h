//
// Created by aml on 4/06/2026.
//

#ifndef LAB8_2023_1_ALUMNO_H
#define LAB8_2023_1_ALUMNO_H

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double total;

public:
    Alumno();

    Alumno(const int codigo,const char *nombre, const int escala,double total);

    Alumno(const Alumno &alum);

    ~Alumno();

    void eliminar();

    void operator = (const Alumno &alum);

    void inicializar();

    int get_codigo() const;

    void set_codigo(const int codigo);

    char * get_nombre(char *nomb) const;

    void set_nombre(const char* nomb);

    int get_escala() const;

    void set_escala(const int escala);

    double get_total() const;

    void set_total(const double total);
};

#endif //LAB8_2023_1_ALUMNO_H