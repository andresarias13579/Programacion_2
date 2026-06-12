//
// Created by aml on 11/06/2026.
//

#ifndef EJEMPLOFICHAS_FICHA_H
#define EJEMPLOFICHAS_FICHA_H

class Ficha {
private:
    char *id;
    int  fila;
    int columna;

public:
    Ficha();
    Ficha(const Ficha &fich);
    ~Ficha();
    void inicializa();
    void elimina();
    void operator = (const Ficha &fich);
    char * get_id(char *ID) const;
    void set_id( const char * id);
    int get_fila() const;
    void set_fila(const int fila);
    int get_columna() const;
    void set_columna(const int columna);
    void asigna (char *ident, int fil, int col);
    virtual void imprime(ofstream &arch) const;
    virtual void mover(char direccion, int cantidad) = 0;
};

#endif //EJEMPLOFICHAS_FICHA_H