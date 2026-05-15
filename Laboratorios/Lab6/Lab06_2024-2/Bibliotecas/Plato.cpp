#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "Plato.h"

Plato::Plato() {
    inicializar();
}

Plato::Plato(const Plato &plato) {
    inicializar();
    *this = plato;
}

Plato::~Plato() {
    eliminar();
}

void Plato::eliminar() {
    if (nombre) delete [] nombre;
    if (categoria) delete [] categoria;
    if (codigo) delete [] codigo;
}

void Plato::operator=(const Plato &plato) {
    char nombre[100],categoria[100],codigo[100];
    plato.get_codigo(codigo);
    set_codigo(codigo);
    plato.get_nombre(nombre);
    set_nombre(nombre);
    precio = plato.get_precio();
    plato.get_categoria(categoria);
    set_categoria(categoria);
    descuento = plato.get_descuento();
    preparados = plato.get_preparados();
    atendidos = plato.get_atendidos();
    noAtendidos = plato.get_no_atendidos();
    totalEsperado = plato.get_total_esperado();
    totalBruto = plato.get_total_bruto();
    totalNeto = plato.get_total_neto();
}

void Plato::inicializar() {
    nombre = nullptr;
    categoria = nullptr;
    codigo = nullptr;
    totalEsperado = 0;
    totalBruto = 0;
    totalNeto = 0;
    atendidos = 0;
    noAtendidos = 0;
    preparados = 0;
}

char * Plato::get_codigo(char *cod) const {
    if (codigo == nullptr) cod[0] = 0;
    else strcpy(cod, codigo);
    return cod;
}

void Plato::set_codigo(char * const cod) {
    if (codigo) delete [] codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

char * Plato::get_nombre(char *nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
    return nomb;
}

void Plato::set_nombre(char * const nomb) {
    if (nombre) delete [] nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

double Plato::get_precio() const {
    return precio;
}

void Plato::set_precio(const double precio) {
    this->precio = precio;
}

char * Plato::get_categoria(char *cat) const {
    if (categoria == nullptr) cat[0] = 0;
    else strcpy(cat, categoria);
    return cat;
}

void Plato::set_categoria(char * const cat) {
    if (categoria) delete [] categoria;
    categoria = new char[strlen(cat) + 1];
    strcpy(categoria, cat);
}

double Plato::get_descuento() const {
    return descuento;
}

void Plato::set_descuento(const double descuento) {
    this->descuento = descuento;
}

int Plato::get_preparados() const {
    return preparados;
}

void Plato::set_preparados(const int preparados) {
    this->preparados = preparados;
}

int Plato::get_atendidos() const {
    return atendidos;
}

void Plato::set_atendidos(const int atendidos) {
    this->atendidos = atendidos;
}

int Plato::get_no_atendidos() const {
    return noAtendidos;
}

void Plato::set_no_atendidos(const int no_atendidos) {
    noAtendidos = no_atendidos;
}

double Plato::get_total_esperado() const {
    return totalEsperado;
}

void Plato::set_total_esperado(const double total_esperado) {
    totalEsperado = total_esperado;
}

double Plato::get_total_bruto() const {
    return totalBruto;
}

void Plato::set_total_bruto(const double total_bruto) {
    totalBruto = total_bruto;
}

double Plato::get_total_neto() const {
    return totalNeto;
}

void Plato::set_total_neto(const double total_neto) {
    totalNeto = total_neto;
}

void Plato::imprimir(ofstream &arch) const{
    arch<<fixed<<setprecision(2);
    arch<<left<<setw(11)<<codigo<<setw(50)<<nombre<<setw(10)<<precio<<setw(15)<<categoria<<right<<setw(10)<<descuento<<setw(15)<<preparados<<setw(15)<<atendidos
        <<setw(15)<<noAtendidos<<setw(15)<<totalEsperado<<setw(15)<<totalBruto<<setw(15)<<totalNeto<<endl;
}

void operator >> (ifstream &arch, Plato &plato) {
    char codigo[50],nombre[100],categoria[50],c;
    double precio;
    int preparados;
    double descuento;
    arch.getline(codigo,50,',');
    if (arch.eof()) return;
    arch.getline(nombre,100,',');
    arch>>precio>>c;
    arch.getline(categoria,50,',');
    arch>>preparados;
    if (arch.get() != '\n') {
        arch>>descuento>>c;
        arch.get();
    }else descuento = 0;
    plato.set_codigo(codigo);
    plato.set_nombre(nombre);
    plato.set_precio(precio);
    plato.set_categoria(categoria);
    plato.set_preparados(preparados);
    plato.set_descuento(descuento);
}
void operator << (ofstream &arch, const Plato &plato) {
    plato.imprimir(arch);
}
