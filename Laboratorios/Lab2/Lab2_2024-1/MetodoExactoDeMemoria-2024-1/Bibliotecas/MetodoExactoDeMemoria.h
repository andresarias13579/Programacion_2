//
// Created by alulab14 on 16/04/2026.
//

#ifndef METODOEXACTODEMEMORIA_2024_1_METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_2024_1_METODOEXACTODEMEMORIA_H

void lecturaDeLibros(const char*nombArch,char ***&libros,int **&stock);
void asignacionMemoriaExactaLibrosStock(char ***&libros,int **&stock,char ***bufferLibros,int **bufferStock,
    int numDatos);
void pruebaDeLecturaDeLibros(const char*nombArch,char ***libros,int **stock);
void atencionsDePedidos(const char*nombArch,char ***&libros,int **&stock,int **&pedidosClientes,
    char **&pedidoLibros,bool **&pedidosAtendidos);
void creamosCliente(int *&pedCli,int dni,int &numDatos,int &idCLiente);

char *leeCadenaExacta(ifstream &arch,char delimitador);
void imprimirLinea(ofstream &arch,char line);
int buscarCliente(int dni,int **bufferPedCli,int numDatos);

#endif //METODOEXACTODEMEMORIA_2024_1_METODOEXACTODEMEMORIA_H
