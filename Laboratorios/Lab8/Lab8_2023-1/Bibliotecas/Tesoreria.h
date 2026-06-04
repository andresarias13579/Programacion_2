//
// Created by aml on 4/06/2026.
//

#ifndef LAB8_2023_1_TESORERIA_H
#define LAB8_2023_1_TESORERIA_H

class Tesoreria {
private:
    Presencial lpresencial[100];
    Semipresencial lsemipresencial[100];
    Virtual lvirtual[100];
    Escala lescala[100];

public:
    void cargaescalas (const char* nombArch);
    void cargaalumnos(const char* nombArch);
    void actualiza(int creditos);
    double buscarMontoEscala(Escala *escalas,int codEscala);
    void imprime(const char*nombArch);
};

#endif //LAB8_2023_1_TESORERIA_H