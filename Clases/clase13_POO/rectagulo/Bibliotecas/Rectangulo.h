//
// Created by Andres on 5/05/2026.
//

#ifndef RECTAGULO_RECTANGULO_H
#define RECTAGULO_RECTANGULO_H

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

#endif //RECTAGULO_RECTANGULO_H
