//
// Created by Andres on 25/03/2026.
//

#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

void operator <<(struct Empleados &empleados, const char *nombArch);

void operator <<(const char *nombArchstruct,const struct Empleados &empleados);

#endif //OPERADORESSOBRECARGADOS_H
