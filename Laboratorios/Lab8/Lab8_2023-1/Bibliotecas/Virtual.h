//
// Created by aml on 4/06/2026.
//

#ifndef LAB8_2023_1_VIRTUAL_H
#define LAB8_2023_1_VIRTUAL_H

class Virtual : public Alumno {
private:
    char *licencia;
    double total;
public:
    Virtual();

    Virtual(const char* licencia, double total, int cod, const char*nomb,
        int escal, double tot);

    Virtual(const Virtual &vir);

    ~Virtual();

    void eliminar();

    void operator = (const Virtual &vir);

    void inicializar();

    char * get_licencia(char *lice) const;

    void set_licencia(const char * lice);

    double get_total() const;

    void set_total(const double total);

    void leeVirtual(ifstream &arch);

    void actualizar(double monto);

    void mostrar(ofstream &arch);
};

#endif //LAB8_2023_1_VIRTUAL_H