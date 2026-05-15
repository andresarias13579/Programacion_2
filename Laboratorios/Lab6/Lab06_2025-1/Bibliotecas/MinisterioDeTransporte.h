//
// Created by aml on 14/05/2026.
//

#ifndef LAB06_2025_1_MINISTERIODETRANSPORTE_H
#define LAB06_2025_1_MINISTERIODETRANSPORTE_H

#include "Empresa.h"
#include "Infraccion.h"

class MinisterioDeTransporte {
    private:
    class Infraccion *infracciones;
    int numInf;
    class Empresa empresas[50];
    int numEmp;

    public:
    MinisterioDeTransporte();

    ~MinisterioDeTransporte();

    void liberar();

    void inicializar();

    void operator < (const char*nombArch);

    void operator <= (const char*nombArch);

    void operator <<= (const char*nombArch);

    double buscarMulta(int codInfra);

    int buscarEmpresa(const char *placa);

    bool tieneLaPlaca(Empresa &empresas,const char *placa);

    void operator >> (const char*nombArch);

    void imprimeLinea(ofstream &arch,char line);
};

#endif //LAB06_2025_1_MINISTERIODETRANSPORTE_H