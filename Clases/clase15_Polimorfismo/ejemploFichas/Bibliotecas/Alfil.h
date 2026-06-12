//
// Created by aml on 11/06/2026.
//

#ifndef EJEMPLOFICHAS_ALFIL_H
#define EJEMPLOFICHAS_ALFIL_H
#include "Ficha.h"

class Alfil : public Ficha{
private:

public:
    void imprime(ofstream &arch) const;
    void mover(char direccion, int cantidad);
};

#endif //EJEMPLOFICHAS_ALFIL_H