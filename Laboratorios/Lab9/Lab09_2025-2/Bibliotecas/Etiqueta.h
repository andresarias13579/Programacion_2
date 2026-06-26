//
// Created by Andres on 25/06/2026.
//

#ifndef LAB09_2025_2_ETIQUETA_H
#define LAB09_2025_2_ETIQUETA_H
#include <string>

class Etiqueta {
private:
    string codigo;
    string nombre;
public:
    Etiqueta();
    Etiqueta(const Etiqueta &eti);
    ~Etiqueta();
    void inicializa();
    void operator=(const Etiqueta &eti);
    void eliminar();

    string get_codigo() const;

    void set_codigo(const string &codigo);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    void lee(ifstream &arch) ;
    void imprime(ofstream &arch) const;
};
void operator >> (ifstream &arch,  Etiqueta &eti);
void operator << (ofstream &arch, const Etiqueta &eti);

#endif //LAB09_2025_2_ETIQUETA_H
