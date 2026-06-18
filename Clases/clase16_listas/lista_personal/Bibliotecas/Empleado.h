//
// Created by Andres on 18/06/2026.
//

#ifndef LISTA_PERSONAL_EMPLEADO_H
#define LISTA_PERSONAL_EMPLEADO_H

class Empleado {
private:
    int codigo;
    char *nombre;
    double sueldo;
public:
    Empleado();

    Empleado(const Empleado &emp);

    ~Empleado();

    void inicializar();

    void eliminar();

    void operator = (const Empleado &emp);

    int get_codigo() const;

    void set_codigo(const int codigo);

    char * get_nombre(char *nomb) const;

    void set_nombre(const char * nomb);

    double get_sueldo() const;

    void set_sueldo(const double sueldo);

    void lee(ifstream &arch);

    bool operator > (const Empleado &emp);

    void imprime(ofstream &arch) const;
};

void operator >> (ifstream &arch,Empleado &dato);
void operator << (ofstream &arch,const Empleado &dato);

#endif //LISTA_PERSONAL_EMPLEADO_H
