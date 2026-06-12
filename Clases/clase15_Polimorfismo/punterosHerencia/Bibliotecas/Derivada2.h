//
// Created by aml on 11/06/2026.
//

#ifndef PUNTEROSHERENCIA_DERIVADA2_H
#define PUNTEROSHERENCIA_DERIVADA2_H
#include "Base.h"

class Derivada2 : public Base{
private:
    int d2;

public:
    Derivada2();

    ~Derivada2();

    int get_d2() const;

    void set_d2(const int d2);

    void mostrar() const;
};

#endif //PUNTEROSHERENCIA_DERIVADA2_H