#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "FuncionesAuxiliares.h"

void cargarCategorias(const char*nombArch,char ***&categorias) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    int capacidad = 0,numDatos = 0;
    char **catego,*cod,*nombre,*descripcion;
    catego = new char*[3];
    while (true) {
        cod = leeCadenaExacta(arch,',');
        if (arch.eof()) break;
        nombre = leeCadenaExacta(arch,',');
        descripcion = leeCadenaExacta(arch,'\n');
        catego[0] = cod;
        catego[1] = nombre;
        catego[2] = descripcion;
        if (capacidad == numDatos) incrementarMemoria(categorias,numDatos,capacidad);
        categorias[numDatos] = catego;
        // cout<<categorias[numDatos][0]<<"   "<<categorias[numDatos][1]<<"    "<<categorias[numDatos][2]<<endl;
        numDatos++;
    }
}
void cargarStreamers(const char*nombArch,char ***&streamers,int **&fechasPromedios,long long **&tiempoRepSeguidores) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    int capacidadStreamer = 0,capacidadFecha=0, capacidadTiempo = 0,numDatos = 0,*fechProm,dc,mc,ac,du,mu,au;
    char **bloger,c,*bloger1;
    long long *tiemRepSeg;
    bloger = new char*[2];
    tiemRepSeg = new long long[2];
    fechProm = new int [3];
    while (true) {
        bloger[0] = leeCadenaExacta(arch,',');
        if (arch.eof()) break;
        arch>>dc>>c>>mc>>c>>ac>>c>>du>>c>>mu>>c>>au>>c>>tiemRepSeg[0]>>c>>fechProm[2]>>c>>tiemRepSeg[1]>>c;
        fechProm[0] = ac*10000 + mc*100 + dc;
        fechProm[1] = au*10000 + mu*100 + du;
        bloger[1] = leeCadenaExacta(arch,'\n');
        if (capacidadStreamer == numDatos) incrementarMemoria(streamers,numDatos,capacidadStreamer);
        if (capacidadFecha == numDatos) incrementarMemoriaInt(fechasPromedios,numDatos,capacidadFecha);
        if (capacidadTiempo == numDatos) incrementarMemoriaLongLong(tiempoRepSeguidores,numDatos,capacidadTiempo);
        streamers[numDatos] = bloger;
        fechasPromedios[numDatos] = fechProm;
        tiempoRepSeguidores[numDatos] = tiemRepSeg;
        // cout << streamers[numDatos][0]<<"   "<<streamers[numDatos][1]<<"   "<<tiempoRepSeguidores[numDatos][0]<<"   "<<tiempoRepSeguidores[numDatos][1]<<endl ;
        numDatos++;
    }
}
void cargarComentarios(const char*nombArch,char ***&comentarios,char ***&etiquetas) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    int capacidadCome = 0, numDatos = 0;
    char **come,**bufferEti[200]{};
    come = new char*[2];
    while (true) {
        come[0] = leeCadenaExacta(arch,',');
        if (arch.eof()) break;
        leemosComentarioEtiquetas(arch,come[1],bufferEti[numDatos]);
        if (capacidadCome == numDatos) incrementarMemoria(comentarios,numDatos,capacidadCome);
        comentarios[numDatos] = come;
        numDatos++;
    }
    etiquetas = new char**[numDatos+1]{};
    for (int i = 0; i < numDatos; ++i) {
        etiquetas[i] = bufferEti[i];
    }
}
void leemosComentarioEtiquetas(ifstream &arch,char *come,char **&bufferEti) {
    char comentario1[400],comentario2[200];
    arch.getline(comentario1,400,'[');
    asignamosEtiquetas(arch,bufferEti);
    arch.getline(comentario2,200,'\n');
    strcat(comentario1,comentario2);
    come = new char[strlen(comentario1)+1]{};
    strcpy(come,comentario1);
}
void asignamosEtiquetas(ifstream &arch,char **&arrEti) {
    char *buffer[50]{},etiqueta[50];
    int numDatos = 0;
    while (true) {
        arch>>etiqueta;
        buffer[numDatos] = new char [strlen(etiqueta)+1]{};
        strcpy(buffer[numDatos],etiqueta);
        numDatos++;
        if (arch.get()==']') break;
    }
    arrEti = new char*[numDatos+1]{};
    for (int i = 0; i < numDatos; ++i) {
        arrEti[i] = buffer[i];
    }
}

char* leeCadenaExacta(ifstream &arch,char delimitador) {
    char *ptr,cadena[500];
    arch.getline(cadena,500,delimitador);
    if (arch.eof()) return nullptr;
    ptr = new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}
void incrementarMemoria(char ***&categorias,int numDatos,int &capacidad) {
    char ***ptrAux;
    if (capacidad == 0) {
        categorias = new char**[5]{};
        capacidad = 5;
    }else {
        ptrAux = new char**[capacidad + 5]{};
        for (int i = 0; i < numDatos; ++i) ptrAux[i] = categorias[i];
        delete [] categorias;
        categorias = ptrAux;
        capacidad+=5;
    }
}
void incrementarMemoriaInt(int **&fechasPromedios,int numDatos,int &capacidad) {
    int **ptrAux;
    if (capacidad == 0) {
        fechasPromedios = new int*[5]{};
        capacidad = 5;
    }else {
        ptrAux = new int*[capacidad + 5]{};
        for (int i = 0; i < numDatos; ++i) ptrAux[i] = fechasPromedios[i];
        delete [] fechasPromedios;
        fechasPromedios = ptrAux;
        capacidad+=5;
    }
}
void incrementarMemoriaLongLong(long long **&tiempoRepSeguidores,int numDatos,int &capacidad) {
    long long **ptrAux;
    if (capacidad == 0) {
        tiempoRepSeguidores = new long long*[5]{};
        capacidad = 5;
    }else {
        ptrAux = new long long*[capacidad + 5]{};
        for (int i = 0; i < numDatos; ++i) ptrAux[i] = tiempoRepSeguidores[i];
        delete [] tiempoRepSeguidores;
        tiempoRepSeguidores = ptrAux;
        capacidad+=5;
    }
}