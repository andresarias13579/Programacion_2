//
// Created by Andres on 11/06/2026.
//

#ifndef LAB09_2023_1_ALUMNO_H
#define LAB09_2023_1_ALUMNO_H
#include <fstream>

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;

public:
    Alumno();
    Alumno(const Alumno &alum);
    ~Alumno();
    void operator=(const Alumno &alum);
    void inicializar();
    void eliminar();

    int get_codigo() const;

    void set_codigo(const int codigo);

    char * get_nombre(char *nomb) const;

    void set_nombre( const char *nombre);

    int get_escala() const;

    void set_escala(const int escala);

    double get_creditos() const;

    void set_creditos(const double creditos);

    double get_total() const;

    void set_total(const double total);

    virtual void leeDatos(ifstream &arch);
    virtual void imprimeAlumno(ofstream &arch);
};

#endif //LAB09_2023_1_ALUMNO_H
