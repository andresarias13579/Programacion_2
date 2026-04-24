#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

enum INVENTARIO {CODi,NOMi,CANDi,CANRi,UNIi};
enum MENU {CODm,NOMm,DESm,TIPm,DISm,PREm,CANTm,INSm};
#define NO_ENCONTRADO -1

using namespace std;
#include "FuncionesAuxiliares.h"

void cargarInventario(const char*nombArch,void *&inv) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    int numDatos = 0,capacidad = 0;
    char *codigo,*nombre,*uniMedida;
    double *cantidad;
    void **inventario = (void **)inv;
    while (true) {
        codigo = leeCadenaExacta(arch,',');
        if (arch.eof()) break;
        leeDatosInventario(arch,nombre,uniMedida,cantidad);
        if (numDatos == 0 || numDatos == capacidad-1) incrementarMemoria(inventario,capacidad,numDatos);
        asignamosDatos(inventario[numDatos],nombre,uniMedida,cantidad,codigo);
        numDatos++;
    }
    inv = inventario;
}
void leeDatosInventario(ifstream &arch,char *&nombre,char *&uniMedida,double *&cantidad) {
    nombre = leeCadenaExacta(arch,',');
    cantidad = new double;
    arch>>*cantidad;
    arch.get();
    uniMedida = leeCadenaExacta(arch,'\n');
}
void asignamosDatos(void *&inv,char *nombre,char *uniMedida,double *cantidad,char *codigo) {
    void **producto;
    producto = new void *[5]{};
    producto[CODi] = codigo;
    producto[NOMi] = nombre;
    producto[CANDi] = cantidad;
    double *cantReq = new double;
    *cantReq = 0;
    producto[CANRi] = cantReq;
    producto[UNIi] = uniMedida;
    inv = producto;
}
void probarCargarInventario(const char*nombArch,void *inv) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    void **inventario = (void **)inv;
    int numDatos = 0;
    while (inventario[numDatos]) numDatos++;
    for (int i = 0; i < numDatos; ++i) {
        mostramosProducto(arch,inventario[i]);
    }
}
void mostramosProducto(ofstream &arch,void *pro) {
    void **producto = (void **)pro;
    char *codigo = (char*)producto[CODi];
    char *nombre = (char*)producto[NOMi];
    char *uniMedida = (char*)producto[UNIi];
    double *cantidadD = (double*)producto[CANDi];
    double *cantidadR = (double*)producto[CANRi];
    arch<<left<<setw(10)<<codigo<<setw(40)<<nombre<<right<<setw(10)<<*cantidadD
        <<setw(20)<<*cantidadR
        <<setw(10)<<uniMedida<<endl;
}

void cargarMenu(const char*nombArch,void *&menu) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    void **menus = (void **)menu;
    int numDatos = 0,*cantVentas,capacidad = 0;
    double *precio;
    char *tipo,*descripcion,*nombre,*codigo;
    while (true) {
        codigo = leeCadenaExacta(arch,',');
        if (arch.eof()) break;
        leeDatosMenu(arch,cantVentas,precio,tipo,descripcion,nombre);
        if (numDatos == 0 || numDatos == capacidad -1) incrementarMemoria(menus,capacidad,numDatos);
        asignamosDatosMenu(menus[numDatos],codigo,nombre,descripcion,tipo,precio,cantVentas);
        numDatos++;
    }
    menu = menus;
}
void leeDatosMenu(ifstream &arch,int *&cantVentas,double *&precio,char *&tipo,
    char *&descripcion,char *&nombre) {
    nombre = leeCadenaExacta(arch,',');
    descripcion = leeCadenaExacta(arch,',');
    tipo = leeCadenaExacta(arch,',');
    precio = new double;
    arch>>*precio;
    arch.get();
    cantVentas = new int;
    arch>>*cantVentas;
    arch.get();
}
void asignamosDatosMenu(void *&menus,char *codigo,char *nombre,char *descripcion,char *tipo,
    double *precio,int *cantVentas) {
    void **menu = new void *[8]{};
    menu[CODm] = codigo;
    menu[NOMm] = nombre;
    menu[DESm] = descripcion;
    menu[TIPm] = tipo;
    bool *disponible = new bool;
    *disponible = true;
    menu[DISm] = disponible;
    menu[PREm] = precio;
    menu[CANTm] = cantVentas;
    menus = menu;
}
void probarCargarMenu(const char*nombArch,void *men) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    void **menus = (void **)men;
    int numDatos = 0;
    while (menus[numDatos] != nullptr) numDatos++;
    for (int i = 0; i < numDatos; ++i) {
        mostramosMenu(arch,menus[i]);
    }
}
void mostramosMenu(ofstream &arch,void *men) {
    void **menus = (void **)men;
    char *codigo = (char*)menus[CODm],*nombre = (char*)menus[NOMm];
    char *descripcion = (char*)menus[DESm],*tipo = (char*)menus[TIPm];
    bool *disponible = (bool*)menus[DISm];
    double *precio = (double*)menus[PREm];
    int *cantVentas = (int*)menus[CANTm];
    arch<<setw(10)<<codigo<<setw(30)<<nombre<<setw(10)<<tipo<<setw(10)<<*disponible
        <<setw(10)<<*precio<<setw(10)<<*cantVentas<<setw(60)<<descripcion<<endl;
}

void actualizarMenu(const char*nombArch,void *inv,void *men) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    void **inventario = (void **)inv,**menus = (void **)men;
    char *codBebida,*codInsumo,*unidad;
    int cantidad,idInsumo,idBebida,capacidades[40]{};
    while (true) {
        codBebida = leeCadenaExacta(arch,',');
        if (arch.eof()) break;
        leeDatosBebidasInsumos(arch,codInsumo,cantidad,unidad);
        idBebida = buscarBebida(codBebida,menus);
        idInsumo = buscarInsumo(codInsumo,inventario);
        if (idBebida !=NO_ENCONTRADO and idInsumo !=NO_ENCONTRADO)
            actulizamosInsumosBebidas(menus[idBebida],inventario[idInsumo],cantidad,unidad,capacidades[idBebida]);
    }
}
void leeDatosBebidasInsumos(ifstream &arch,char *&codInsumo,int &cantidad,char *&unidad) {
    codInsumo = leeCadenaExacta(arch,',');
    arch>>cantidad;
    arch.get();
    unidad = leeCadenaExacta(arch,'\n');
}
void actulizamosInsumosBebidas(void *men,void *inv,int cantidad,char *unidad,int &capacidades) {
    void **inventario = (void **)inv,**menus = (void **)men;
    actualizarInventario((double*)inventario[CANRi],cantidad);
    actualizarInsumo(menus,(double*)inventario[CANDi],cantidad,unidad,inventario,capacidades);
}
void actualizarInventario(double *cantReq,int cantidad) {
    *cantReq += (double)cantidad/1000;
}
void actualizarInsumo(void **menus,double *cantDisponible,int cantidad,char *unidad,void **inventario,
    int &capacidades) {
    int numDatos=0;
    void **insumos = (void**)menus[INSm];
    if (insumos == nullptr) numDatos = 0;
    else while (insumos[numDatos] != nullptr) numDatos++;
    if (numDatos == 0 || numDatos == capacidades-1) incrementarMemoria(insumos,capacidades,numDatos);
    void *disponibilidad = menus[DISm];
    bool *dis = (bool *)disponibilidad;
    asignamosInsumos(insumos[numDatos],inventario,cantDisponible,cantidad,unidad,dis);
}
void asignamosInsumos(void *insumos,void **inventario,double *cantDisponible,int cantidad,char *unidad,
    bool *&disponibilidad) {
    void **datosInsumo;
    if (datosInsumo == nullptr) {
        datosInsumo = new void *[3]{};
    }
    datosInsumo[0] = inventario;
    double *cantidadDin = new double;
    *cantidadDin = (double)cantidad;
    // cout << *(double *) datosInsumo[1];
    datosInsumo[1] = cantidadDin;
    // if (datosInsumo[1] == nullptr) datosInsumo[1] = new double;
    // *(double*)datosInsumo[1] += *cantidadDin;
    datosInsumo[2] = unidad;
    if (*(double*)datosInsumo[1] > *cantDisponible*1000) *disponibilidad = false;
}

char *leeCadenaExacta(ifstream &arch,char delimitador) {
    char *ptr,cadena[200];
    arch.getline(cadena,200,delimitador);
    if (arch.eof() and strlen(cadena)==0) return nullptr;
    ptr = new char[strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}
void incrementarMemoria(void **&inventario,int &capacidad,int numDatos) {
    if (capacidad == 0) {
        inventario = new void *[5]{};
        capacidad = 5;
    }else {
        void **auxiliar;
        auxiliar = new void *[capacidad+5]{};
        for (int i = 0; i < numDatos; ++i) auxiliar[i] = inventario[i];
        delete [] inventario;
        inventario = auxiliar;
        capacidad+=5;
    }
}
int buscarBebida(char *codBebida,void **menus) {
    int numDatos;
    while (menus[numDatos] != nullptr) numDatos++;
    for (int i = 0; i < numDatos; ++i) {
        void **bebida = (void **)menus[i];
        char *codigo = (char*)bebida[CODm];
        if (strcmp(codigo,codBebida)==0) return i;
    }
    return NO_ENCONTRADO;
}
int buscarInsumo(char *codInsumo,void **inventario) {
    int numDatos;
    while (inventario[numDatos] != nullptr) numDatos++;
    for (int i = 0; i < numDatos; ++i) {
        void **insumo = (void **)inventario[i];
        char *codigo = (char*)insumo[CODi];
        if (strcmp(codigo,codInsumo)==0) return i;
    }
    return NO_ENCONTRADO;
}