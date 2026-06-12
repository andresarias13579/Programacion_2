//
// Created by aml on 11/06/2026.
//

#ifndef PUNTEROSHERENCIA_DERIVADA1_H
#define PUNTEROSHERENCIA_DERIVADA1_H
#include "Base.h"

class Derivada1 : public Base {
private:
    int d;

public:
    Derivada1();

    ~Derivada1();

    int get_d() const;

    void set_d(const int d);

    void mostrar() const;
};

#endif //PUNTEROSHERENCIA_DERIVADA1_H