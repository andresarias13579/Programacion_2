//
// Created by aml on 11/06/2026.
//

#ifndef EJEMPLOFICHAS_CABALLO_H
#define EJEMPLOFICHAS_CABALLO_H
#include "Ficha.h"

class Caballo : public Ficha{
private:

public:
    void imprime(ofstream &arch) const;
    void mover(char direccion, int cantidad);
};

#endif //EJEMPLOFICHAS_CABALLO_H