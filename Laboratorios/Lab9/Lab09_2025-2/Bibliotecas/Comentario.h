//
// Created by Andres on 25/06/2026.
//

#ifndef LAB09_2025_2_COMENTARIO_H
#define LAB09_2025_2_COMENTARIO_H

class Comentario {
private:
    string canal;
    string comentario;
public:
    Comentario();
    Comentario(const Comentario &com);
    void operator=(const Comentario &com);
    string get_canal() const;

    void set_canal(const string &canal);

    string get_comentario() const;

    void set_comentario(const string &comentario);

    void lee(ifstream &arch);
    void imprime(ofstream &arch) const;

    bool operator < (const Comentario &com);
};

void operator>>(ifstream &arch, Comentario &com);
void operator<<(ofstream &arch,const Comentario &com);

#endif //LAB09_2025_2_COMENTARIO_H
