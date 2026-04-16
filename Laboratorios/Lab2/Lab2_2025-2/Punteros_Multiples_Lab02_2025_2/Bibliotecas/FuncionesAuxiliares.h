//
// Created by aml on 16/04/2026.
//

#ifndef PUNTEROS_MULTIPLES_LAB02_2025_2_FUNCIONESAUXILIARES_H
#define PUNTEROS_MULTIPLES_LAB02_2025_2_FUNCIONESAUXILIARES_H

void cargarCategorias(const char*nombArch,char ***&categorias);
void cargarStreamers(const char*nombArch,char ***&streamers,int **&fechasPromedios,long long **&tiempoRepSeguidores);
void cargarComentarios(const char*nombArch,char ***&comentarios,char ***&etiquetas);
void leemosComentarioEtiquetas(ifstream &arch,char *&come,char **&bufferEti);
void asignamosEtiquetas(ifstream &arch,char **&arrEti);
void imprimirReporte(const char*nombArch,char ***categorias,char ***streamers,int **fechasPromedios,
    long long **tiempoRepSeguidores,char ***comentarios,char ***etiquetas);
void mostramosCuentas(ofstream &arch,char ***streamers,int **fechasPromedios,long long **tiempoRepSeguidores,
    char ***etiquetas,char ***comentarios,char *codCategoria);

char* leeCadenaExacta(ifstream &arch,char delimitador);
void incrementarMemoria(char ***&categorias,int numDatos,int &capacidad);
void incrementarMemoriaInt(int **&fechasPromedios,int numDatos,int &capacidad);
void incrementarMemoriaLongLong(long long **&tiempoRepSeguidores,int numDatos,int &capacidad);
bool verificamosUltimaLetra(char *etiqueta);
int buscarChar(char *codCategoria,char ***streamers);
int bucarComen(char *streamer,char ***etiquetas);

#endif //PUNTEROS_MULTIPLES_LAB02_2025_2_FUNCIONESAUXILIARES_H