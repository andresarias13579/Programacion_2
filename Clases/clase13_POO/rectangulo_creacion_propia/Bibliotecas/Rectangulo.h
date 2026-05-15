//
// Created by aml on 14/05/2026.
//

#ifndef RECTANGULO_CREACION_PROPIA_RECTANGULO_H
#define RECTANGULO_CREACION_PROPIA_RECTANGULO_H

class Rectangulo {
    private:
    double base;
    double altura;

    public:
    void asignarBase(double b);
    void asignarAltura(double h);
    double entregarBase();
    double entregarAltura();
    void asignarAtributos(double b, double h);
    void leeDatos();
    double area();
    double perimetro();
    void mostrarResultados();
};

#endif //RECTANGULO_CREACION_PROPIA_RECTANGULO_H