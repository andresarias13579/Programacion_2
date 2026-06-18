//
// Created by Andres on 18/06/2026.
//

#ifndef LAB8_2025_2_METRICA_H
#define LAB8_2025_2_METRICA_H

class Metrica {
private:
    int id;
    char *descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;
public:
    Metrica();
    Metrica(const Metrica &metrica);
    ~Metrica();
    void operator=(const Metrica &metrica);
    void inicializar();
    void eliminar();

    int get_id() const;

    void set_id(const int id);

    char * get_descripcion(char * desc) const;

    void set_descripcion(const char * desc);

    int get_fecha_calculo() const;

    void set_fecha_calculo(const int fecha_calculo);

    int get_fecha_expiracion() const;

    void set_fecha_expiracion(const int fecha_expiracion);

    bool get_estado() const;

    void set_estado(const bool estado);

    virtual void leer(ifstream &arch);
    void leeFecha(ifstream &arch,int &fecha);
    virtual void imprimir(ofstream &arch) const;
};

#endif //LAB8_2025_2_METRICA_H
