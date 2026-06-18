//
// Created by Andres on 18/06/2026.
//

#ifndef LAB8_2025_2_METRICABASICA_H
#define LAB8_2025_2_METRICABASICA_H
#include "Metrica.h"

class MetricaBasica : public Metrica {
private:
    double horas_transmitidas;
    int espectadores_promedio;
public:
    MetricaBasica();
    MetricaBasica(const MetricaBasica &metrica);
    ~MetricaBasica();
    void operator=(const MetricaBasica &metrica);
    void inicializa();
    void elimina();
    double get_horas_transmitidas() const;

    void set_horas_transmitidas(const double horas_transmitidas);

    int get_espectadores_promedio() const;

    void set_espectadores_promedio(const int espectadores_promedio);

    void leer(ifstream &arch);
    void imprimir(ofstream &arch) const;
};

#endif //LAB8_2025_2_METRICABASICA_H
