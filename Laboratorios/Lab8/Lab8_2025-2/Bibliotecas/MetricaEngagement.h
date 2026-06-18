//
// Created by Andres on 18/06/2026.
//

#ifndef LAB8_2025_2_METRICAENGAGEMENT_H
#define LAB8_2025_2_METRICAENGAGEMENT_H
#include "Metrica.h"

class MetricaEngagement : public Metrica{
private:
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;
public:
    MetricaEngagement();
    MetricaEngagement(const MetricaEngagement& metrica);
    ~MetricaEngagement();
    void inicializa();
    void elimina();
    void operator = (const MetricaEngagement& metrica);

    int get_mensajes_chat() const;

    void set_mensajes_chat(const int mensajes_chat);

    int get_usuarios_unicos_chat() const;

    void set_usuarios_unicos_chat(const int usuarios_unicos_chat);

    int get_clips_generados() const;

    void set_clips_generados(const int clips_generados);

    void leer(ifstream &arch) ;
    void imprimir(ofstream &arch) const ;
};

#endif //LAB8_2025_2_METRICAENGAGEMENT_H

