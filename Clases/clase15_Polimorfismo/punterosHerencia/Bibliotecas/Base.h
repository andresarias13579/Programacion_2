//
// Created by aml on 11/06/2026.
//

#ifndef PUNTEROSHERENCIA_BASE_H
#define PUNTEROSHERENCIA_BASE_H

class Base {
private:
    int b;

public:
    Base();

    ~Base();

    int get_b() const;

    void set_b(const int b);

    virtual void mostrar() const;
};

#endif //PUNTEROSHERENCIA_BASE_H