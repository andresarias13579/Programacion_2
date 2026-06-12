//
// Created by aml on 11/06/2026.
//

#ifndef EJEMPLOFICHAS_TORRE_H
#define EJEMPLOFICHAS_TORRE_H
#include "Ficha.h"

class Torre : public Ficha{
private:

public:
    void imprime(ofstream &arch) const ;
    void mover(char direccion, int cantidad);
};

#endif //EJEMPLOFICHAS_TORRE_H