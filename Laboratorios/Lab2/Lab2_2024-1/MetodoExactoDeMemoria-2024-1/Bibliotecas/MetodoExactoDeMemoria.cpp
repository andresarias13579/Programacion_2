#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "MetodoExactoDeMemoria.h"

#define MAX_LINEAS 180
#define NO_ENCONTRADO -1

enum LIBROS {CODL,NOML,AUTL};
enum STOCK {STKI,CNA};

void lecturaDeLibros(const char*nombArch,char ***&libros,int **&stock) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    char **bufferLibros[300]{},**datosLibro,c;
    int *bufferStock[300]{},*stockIni,numDatos=0;
    double precio;
    while (true) {
        datosLibro = new char*[3]{};
        datosLibro[CODL] = leeCadenaExacta(arch,',');
        if (arch.eof()) break;
        datosLibro[NOML] = leeCadenaExacta(arch,',');
        datosLibro[AUTL] = leeCadenaExacta(arch,',');
        stockIni = new int[2]{};
        arch >> stockIni[STKI] >> c>>precio;
        arch.get();
        bufferStock[numDatos] = stockIni;
        bufferLibros[numDatos] = datosLibro;
        numDatos++;
    }
    asignacionMemoriaExactaLibrosStock(libros,stock,bufferLibros,bufferStock,numDatos);
}
void asignacionMemoriaExactaLibrosStock(char ***&libros,int **&stock,char ***bufferLibros,int **bufferStock,
    int numDatos) {
    libros = new char**[numDatos+1]{};
    stock = new int*[numDatos+1]{};
    for (int i = 0; i < numDatos; ++i) {
        libros[i] = bufferLibros[i];
        stock[i] = bufferStock[i];
    }
}
void pruebaDeLecturaDeLibros(const char*nombArch,char ***libros,int **stock) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    arch<<"COD LIBRO"<<setw(25)<<"NOMBRE"<<setw(47)<<"AUTOR"<<setw(50)<<"STOCK"<<setw(25)
            <<"NO ATENDIDOS"<<endl;
    imprimirLinea(arch,'=');
    char **datosLibro;
    int *stockLibro;
    for (int i = 0; libros[i]; ++i) {
        datosLibro = libros[i];
        stockLibro = stock[i];
        arch<<left<<setw(15)<<datosLibro[CODL]<<setw(60)<<datosLibro[NOML]<<setw(25)<<datosLibro[AUTL]<<right
            <<setw(25)<<stockLibro[STKI]<<setw(25)<<stockLibro[CNA]<<endl;
    }
}
void atencionsDePedidos(const char*nombArch,char ***&libros,int **&stock,int **&pedidosClientes,
    char **&pedidoLibros,bool **&pedidosAtendidos) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    int *bufferPedCli[200]{},*pedCli,numDatos=0,pedidos,dni,idCLiente;
    char **bufferPedLib[200]{},**pedLib;
    bool *bufferPedAte[200]{},*pedAte;
    while (true) {
        arch>>pedidos;
        if (arch.eof()) break;
        arch.get();
        arch>>dni;
        idCLiente = buscarCliente(dni,bufferPedCli,numDatos);
        if (idCLiente == NO_ENCONTRADO) creamosCliente(pedCli,dni,numDatos,idCLiente);
        actualizarPedCli(pedCli[idCLiente],pedidos,pedLib,pedAte);
    }
}
void creamosCliente(int *&pedCli,int dni,int &numDatos,int &idCLiente) {
    pedCli = new int[2]{};
    pedCli[0] = dni;
    pedCli[1] = 0;
    idCLiente = numDatos;
}
void actualizarPedCli(int &pedCli,int pedidos,char ***&pedLib,bool **&pedAte) {

}

char *leeCadenaExacta(ifstream &arch,char delimitador) {
    char *ptrAux,cadena[200];
    arch.getline(cadena,200,delimitador);
    if (arch.eof()) return nullptr;
    ptrAux = new char[strlen(cadena)+1];
    strcpy(ptrAux,cadena);
    return ptrAux;
}
void imprimirLinea(ofstream &arch,char line) {
    for (int i = 0; i < MAX_LINEAS; ++i) arch << line;
    arch<<endl;
}
int buscarCliente(int dni,int **bufferPedCli,int numDatos) {
    int *pedCliente;
    for (int i = 0; i < numDatos; ++i) {
        pedCliente = bufferPedCli[i];
        if (pedCliente[0] == dni) return i;
    }
    return NO_ENCONTRADO;
}