//
// Created by Andres on 14/04/2026.
//

#ifndef LAB2_ANDRES_FUNCIONESAUXILIARES_H
#define LAB2_ANDRES_FUNCIONESAUXILIARES_H

void cargar_faltas_de_los_conductores(struct Faltas &faltas);
void leemosArchivoFaltas(ifstream &arch,int *arrDnis,int *arrCodInfra,char ***&arrPlacas,int *&arrCapacidades,int numConductores,
    int numInfracciones);
void insertarPlacas(int idConductor,char **&arrPlacas,int &capacidad,char *placa);
bool validarPlaca(char *placa,char **arrPlacas,int numPlacas);
void incrementamosMemoria(char **&arrPlacas,int &capacidad,int &numDatos);
void imprimir_faltas_de_los_conductores(struct Faltas faltas);
void mostramosConductores(ofstream &arch,int *arrDnis,char **arrNombres,int numConductores, char ***arrPlacas);
int buscamosID(int dni,int *arrDnis,int numConductores);
int numPlacas(char **arrPlacas);
void imprimirLinea(ofstream &arch,char caracter);

#endif //LAB2_ANDRES_FUNCIONESAUXILIARES_H
