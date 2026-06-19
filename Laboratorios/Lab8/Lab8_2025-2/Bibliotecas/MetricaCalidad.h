//
// Created by Andres on 18/06/2026.
//

#ifndef LAB8_2025_2_METRICACALIDAD_H
#define LAB8_2025_2_METRICACALIDAD_H
#include "Metrica.h"

class MetricaCalidad : public Metrica{
private:
    int bitrate_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedio;
public:
    MetricaCalidad();
    MetricaCalidad(const MetricaCalidad &mc);
    ~MetricaCalidad();
    void inicializa();
    void elimina();
    void operator = (const MetricaCalidad &mc);

    int get_bitrate_promedio_kbps() const;

    void set_bitrate_promedio_kbps(const int bitrate_promedio_kbps);

    double get_porcentaje_frames_perdidos() const;

    void set_porcentaje_frames_perdidos(const double porcentaje_frames_perdidos);

    int get_fps_promedio() const;

    void set_fps_promedio(const int fps_promedio);

    void leer(ifstream &arch) ;
    void imprimir(ofstream &arch) const ;
    char tipoMetrica() ;
};

#endif //LAB8_2025_2_METRICACALIDAD_H
