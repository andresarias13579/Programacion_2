#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "Restaurante.h"

#define NO_ENCONTRADO -1

Restaurante::Restaurante() {
    inicializar();
}

Restaurante::~Restaurante() {
    eliminar();
}

void Restaurante::eliminar() {
    if (clientes) delete [] clientes;
    if (platos) delete [] platos;
}

void Restaurante::inicializar() {
    cantidadDeClientes = 0;
    cantidadDePlatos = 0;
    capacidadDeClientes = 0;
    capacidadDePlatos = 0;
    clientes = nullptr;
    platos = nullptr;
}

void Restaurante::operator<(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Archivo no se abrio "<<nombArch<<endl;
        exit(1);
    }
    while (true) {
        if (capacidadDeClientes == 0 || cantidadDeClientes == capacidadDeClientes - 1) aumentarMemoriaCliente(clientes,capacidadDeClientes,cantidadDeClientes);
        arch>>clientes[cantidadDeClientes];
        if (arch.eof()) break;
        cantidadDeClientes++;
    }
}

void Restaurante::aumentarMemoriaCliente(Cliente *&clientes, int &capacidadDeClientes, int cantidadDeClientes) {
    if (capacidadDeClientes == 0) {
        clientes = new Cliente[5];
        capacidadDeClientes = 5;
    }else {
        Cliente *aux = new Cliente[capacidadDeClientes+5];
        for (int i=0;i<cantidadDeClientes;i++) aux[i]=clientes[i];
        delete [] clientes;
        clientes = aux;
        capacidadDeClientes+=5;
    }
}

void Restaurante::operator<=(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Archivo no se abrio "<<nombArch<<endl;
        exit(1);
    }
    while (true) {
        if (capacidadDePlatos == 0 || cantidadDePlatos == capacidadDePlatos - 1) aumentarMemoriaPlatos(platos,capacidadDePlatos,cantidadDePlatos);
        arch>>platos[cantidadDePlatos];
        if (arch.eof()) break;
        cantidadDePlatos++;
    }
}

void Restaurante::aumentarMemoriaPlatos(Plato *&platos, int &capacidadDePlatos, int cantidadDePlatos) {
    if (capacidadDePlatos == 0) {
        platos = new Plato[5];
        capacidadDePlatos = 5;
    }else {
        Plato *aux = new Plato[capacidadDePlatos+5];
        for (int i=0;i<cantidadDePlatos;i++) aux[i]=platos[i];
        delete [] platos;
        platos = aux;
        capacidadDePlatos+=5;
    }
}

void Restaurante::operator<<=(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Archivo no se abrio "<<nombArch<<endl;
        exit(1);
    }
    while (true) {
        int numPedido,dni,cantPlatoPedido,idCliente,idPlato;
        char codPlato[20],c;
        arch>>numPedido;
        if (arch.eof()) break;
        arch>>c>>dni>>c;
        idCliente=buscarCliente(clientes,dni);
        if (idCliente != NO_ENCONTRADO) {
            while (true) {
                arch.getline(codPlato,20,',');
                arch>>cantPlatoPedido;
                idPlato = buscarPlato(platos,codPlato);
                if (idPlato != NO_ENCONTRADO) actualizamosDatos(platos[idPlato],clientes[idCliente],cantPlatoPedido);
                if (arch.get()=='\n') break;
            }
        } else while (arch.get()!='\n');
    }
}

void Restaurante::actualizamosDatos(Plato &plato, Cliente &cliente, int cantPlatoPedido) {
    double precioPlato,descPlato,descCliente;
    precioPlato = plato.get_precio();
    descPlato = plato.get_descuento()/100;
    descCliente = cliente.get_descuento()/100;
    if (plato.get_preparados() > plato.get_atendidos() + cantPlatoPedido) {
        cliente.set_total_pagado(cliente.get_total_pagado() + precioPlato*(1-descPlato)*(1-descCliente));
        plato.set_atendidos( cantPlatoPedido + plato.get_atendidos() );
        plato.set_total_esperado( plato.get_total_esperado() + precioPlato);
        plato.set_total_bruto(plato.get_total_bruto() + precioPlato*(1-descPlato));
        plato.set_total_neto(platos->get_total_neto() + precioPlato*(1-descPlato)*(1-descCliente));
    }else {
        plato.set_no_atendidos( cantPlatoPedido + plato.get_no_atendidos() );
    }
}

int Restaurante::buscarCliente(const Cliente *clientes, int dni) {
    for (int i = 0; i < cantidadDeClientes; ++i) {
        if (clientes[i].get_dni() == dni) return i;
    }
    return NO_ENCONTRADO;
}

int Restaurante::buscarPlato(const Plato *platos, char *codPlato) {
    for (int i = 0; i < cantidadDePlatos; ++i) {
        char codPlatito[20];
        platos[i].get_codigo(codPlatito);
        if (strcmp(codPlatito,codPlato)==0) return i;
    }
    return NO_ENCONTRADO;
}

void Restaurante::operator>>(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Archivo no se abrio "<<nombArch<<endl;
        exit(1);
    }
    arch<<setw(90)<<"RESTAURANTE 1INF25"<<endl;
    arch<<setw(90)<<"VENTAS DEL DIA"<<endl;
    imprimirLinea(arch,'=');
    arch<<setw(90)<<"RELACION DE PLATOS VENDIDOS"<<endl;
    imprimirLinea(arch,'-');
    arch<<"No.  CODIGO"<<setw(20)<<"NOMBRE"<<setw(20)<<"PRECIO"<<setw(20)<<"CATEGORIA"<<setw(20)<<"DESCUENTO"<<setw(20)<<"PREPARADOS"<<setw(20)<<"ATENDIDOS"
        <<setw(20)<<"NO ATENDIDOS"<<setw(20)<<"ESPERADO"<<setw(20)<<"BRUTO"<<setw(20)<<"NETO"<<endl;
    imprimirLinea(arch,'-');
    for (int i = 0; i < cantidadDePlatos; ++i) {
        arch<<setw(2)<<i+1<<") ";
        arch<<platos[i];
    }
    imprimirLinea(arch,'=');
    arch<<setw(90)<<"RELACION DE CLIENTES VENDIDOS"<<endl;
    imprimirLinea(arch,'-');
    arch<<"No.  DNI"<<setw(20)<<"NOMBRE"<<setw(20)<<"DSITRITO"<<setw(20)<<"DESCUENTO"<<setw(20)<<"TOTAL PAGADO"<<endl;
    for (int i = 0; i < cantidadDeClientes; ++i) {
        arch<<setw(2)<<i+1<<") ";
        arch<<clientes[i];
    }
    imprimirLinea(arch,'=');
}

void Restaurante::imprimirLinea(ofstream &arch,char line) {
    for (int i = 0; i < 250; ++i) arch<<line;
    arch<<endl;
}
