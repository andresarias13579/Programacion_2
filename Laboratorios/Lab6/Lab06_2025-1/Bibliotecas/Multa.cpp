#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "Multa.h"

Multa::Multa() {
    inicializar();
}

Multa::Multa(const Multa &mul) {
    inicializar();
    *this = mul;
}

Multa::~Multa() {
    liberar();
}

void Multa::liberar() {
    if (placa) delete [] placa;
}

void Multa::operator = (const Multa &mul) {
    char plac[200];
    mul.get_placa(plac);
    set_placa(plac);
    fechaDeInfraccion = mul.get_fecha_de_infraccion();
    fechaDePago = mul.get_fecha_de_pago();
    codigoInfraccion = mul.get_codigo_infraccion();
    multa = mul.get_multa();
}

void Multa::inicializar() {
    placa = nullptr;
    multa = 0;
}

char * Multa::get_placa(char *plac) const {
    if (placa == nullptr) plac[0] = 0;
    else strcpy(plac, placa);
    return plac;
}

void Multa::set_placa(char * const plac) {
    if (placa) delete [] placa;
    placa = new char[strlen(plac)+1];
    strcpy(placa,plac);
}

int Multa::get_fecha_de_infraccion() const {
    return fechaDeInfraccion;
}

void Multa::set_fecha_de_infraccion(const int fecha_de_infraccion) {
    fechaDeInfraccion = fecha_de_infraccion;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

void Multa::set_fecha_de_pago(const int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

int Multa::get_codigo_infraccion() const {
    return codigoInfraccion;
}

void Multa::set_codigo_infraccion(const int codigo_infraccion) {
    codigoInfraccion = codigo_infraccion;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(const double multa) {
    this->multa = multa;
}

void Multa::leeArch(ifstream &arch) {
    int dd,mm,aa,ddP,mmP,aaP,codMulta;
    int fecha,fechaPago;
    char placa[9],pagado,c;
    arch>>dd;
    if (arch.eof()) return;
    arch>>c>>mm>>c>>aa>>c;
    fecha = aa*10000+mm*100+dd;
    arch.getline(placa,9,',');
    arch>>codMulta;
    if (arch.get()==',') {
        arch>>pagado>>c>>ddP>>c>>mmP>>c>>aaP;
        arch.get();
        fechaPago = aaP*10000+mmP*100+ddP;
    } else fechaPago = 0;
    set_fecha_de_infraccion(fecha);
    set_placa(placa);
    set_codigo_infraccion(codMulta);
    set_fecha_de_pago(fechaPago);
}

void Multa::imprimirArch(ofstream &arch) const {
    arch<<fixed<<setprecision(2);
    arch<<setw(20)<<placa<<setw(15)<<fechaDeInfraccion<<setw(10)<<codigoInfraccion
        <<setw(11)<<multa<<setw(15)<<fechaDePago<<endl;
}

void operator >> (ifstream &arch, Multa &origen) {
    origen.leeArch(arch);
}
void operator << (ofstream &arch, const Multa &origen) {
    origen.imprimirArch(arch);
}
