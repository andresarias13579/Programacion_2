//
// Created by Andres on 14/04/2026.
//

#ifndef LAB2_ANDRES_OPERADORESSOBRECARGADOS_H
#define LAB2_ANDRES_OPERADORESSOBRECARGADOS_H

void operator += (struct Conductores &conductores, const char*nombArch);
void leemosArchivoConductores(ifstream &arch, int *&arrDni, char **&arrNombres,int &numConductores);

void operator += (struct Infracciones &infracciones, const char*nombArch);
void leemosArchivoInfracciones(ifstream &nombArch,int *&arrCodigos,char **&arrDescripciones,char **&arrTipos,
        double *&arrValores,int &cantidad);

char *leeCadenaExacta(ifstream &arch,char delimitador);

#endif //LAB2_ANDRES_OPERADORESSOBRECARGADOS_H
