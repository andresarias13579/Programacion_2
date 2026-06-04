//
// Created by aml on 4/06/2026.
//

#ifndef EJEMPLO_CIRCULO_CILINDRO_TUVO_CIRCULO_H
#define EJEMPLO_CIRCULO_CILINDRO_TUVO_CIRCULO_H

class Circulo {
private:
    double radio;
    char *nombre;
public:
    Circulo();

    Circulo(double rad, const char *nomb);

    Circulo(const Circulo &cir);

    ~Circulo();

    void eliminar();

    void operator = (const Circulo &cir);

    void inicializar();

    double get_radio() const;

    void set_radio(const double radio);

    char * get_nombre(char *nomb) const;

    void set_nombre(const char* nomb);

    double area() const;

    double circunferencia() const;

    void mostrarResultados();
};

#endif //EJEMPLO_CIRCULO_CILINDRO_TUVO_CIRCULO_H