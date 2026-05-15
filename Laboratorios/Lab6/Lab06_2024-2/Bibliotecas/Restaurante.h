//
// Created by Andres on 14/05/2026.
//

#ifndef LAB06_2024_2_RESTAURANTE_H
#define LAB06_2024_2_RESTAURANTE_H
#include "Cliente.h"
#include "Plato.h"

class Restaurante {
    private:
    Cliente *clientes;
    int cantidadDeClientes;
    int capacidadDeClientes;
    Plato *platos;
    int cantidadDePlatos;
    int capacidadDePlatos;

    public:
    Restaurante();

    ~Restaurante();

    void eliminar();

    void inicializar();

    void operator < (const char *nombArch);

    void aumentarMemoriaCliente(Cliente *&clientes,int &capacidadDeClientes,int cantidadDeClientes);

    void operator <= (const char *nombArch);

    void aumentarMemoriaPlatos(Plato *&platos,int &capacidadDePlatos,int cantidadDePlatos);

    void operator <<=(const char *nombArch);

    void actualizamosDatos(Plato &plato,Cliente &cliente,int cantPlatoPedido);

    int buscarCliente(const Cliente *clientes,int dni);

    int buscarPlato(const Plato *platos,char *codPlato);

    void operator >> (const char *nombArch);

    void imprimirLinea(ofstream &arch,char line);
};

#endif //LAB06_2024_2_RESTAURANTE_H
