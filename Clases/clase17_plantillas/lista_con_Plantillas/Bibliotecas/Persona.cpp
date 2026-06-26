#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Persona.h"

// Constructor por defecto
Persona::Persona() {
    dni = 0;
    nombre = nullptr;
    sueldo = 0.0;
}

// Constructor copia
Persona::Persona(const Persona &orig) {
    nombre = nullptr;
    *this = orig; // Llama a la sobrecarga del operator=
}

// Destructor para liberar memoria RAM
Persona::~Persona() {
    if (nombre != nullptr) {
        delete[] nombre;
    }
}

void Persona::set_dni(int dni) {
    this->dni = dni;
}

int Persona::get_dni() const {
    return dni;
}

void Persona::set_nombre(const char *nom) {
    if (this->nombre != nullptr) delete[] this->nombre;
    this->nombre = new char[strlen(nom) + 1];
    strcpy(this->nombre, nom);
}

void Persona::get_nombre(char *nom) const {
    if (this->nombre != nullptr) {
        strcpy(nom, this->nombre);
    } else {
        nom[0] = '\0';
    }
}

void Persona::set_sueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::get_sueldo() const {
    return sueldo;
}

// Método de lectura exacto al formato esperado por el main de tu profesor
void Persona::lee(istream &in) {
    int d;
    double s;
    char nom[60];

    in >> d;
    if (in.eof()) return;
    in.get(); // Salta el delimitador (ej. la coma del CSV)

    in.getline(nom, 60, ',');
    in >> s;

    set_dni(d);
    set_nombre(nom);
    set_sueldo(s);
}

// Método de impresión respetando el formato tabular del PDF
void Persona::imprime(ostream &out) const {
    out.precision(2);
    out << fixed;
    out << left << setw(10) << dni
        << setw(35) << (nombre ? nombre : "---")
        << right << setw(10) << sueldo << endl;
}

// Operador de asignación (Garantiza que no compartan el mismo puntero de texto)
void Persona::operator =(const Persona &orig) {
    this->dni = orig.dni;
    this->sueldo = orig.sueldo;

    char nom[60];
    orig.get_nombre(nom);
    set_nombre(nom);
}

// Implementación de las funciones sobrecargadas globales
void operator >>(istream &in, Persona &per) {
    per.lee(in);
}

void operator <<(ostream &out, const Persona &per) {
    per.imprime(out);
}

bool Persona::operator <(const Persona &otro) const {
    // Definimos que una persona es "menor" si su DNI es menor
    return this->dni < otro.dni;
}