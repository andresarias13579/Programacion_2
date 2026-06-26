//
// Created by Andres on 25/06/2026.
//

#ifndef PRUEBA_PERSONA_H
#define PRUEBA_PERSONA_H

class Persona {
private:
    int dni;
    char *nombre;
    double sueldo;
public:
    Persona();
    Persona(const Persona &orig);
    ~Persona();

    // Métodos selectores (Getters y Setters)
    void set_dni(int dni);
    int get_dni() const;
    void set_nombre(const char *nom);
    void get_nombre(char *nom) const;
    void set_sueldo(double sueldo);
    double get_sueldo() const;

    // Funciones principales de E/S
    void lee(istream &in);
    void imprime(ostream &out) const;

    // Operador de asignación para copia profunda
    void operator =(const Persona &orig);
};

// Sobrecarga de operadores globales de flujo
void operator >>(istream &in, Persona &per);
void operator <<(ostream &out, const Persona &per);

#endif //PRUEBA_PERSONA_H
