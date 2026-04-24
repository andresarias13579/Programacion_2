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
// Ojo: agregué cantReq a los parámetros de actualizarInsumo para hacer la validación más fácil
void actulizamosInsumosBebidas(void *men, void *inv, int cantidad, char *unidad, int &capacidades) {
    void **inventario = (void **)inv, **menus = (void **)men;

    // 1. Extraemos las ventas estimadas de esta bebida
    int *cantVentasPtr = (int*)menus[CANTm];
    int ventasEstimadas = *cantVentasPtr;

    // 2. Extraemos los punteros de cantidades del inventario
    double *cantReq = (double*)inventario[CANRi];
    double *cantDisponible = (double*)inventario[CANDi];

    // 3. Actualizamos el requerimiento global en el inventario
    actualizarInventario(cantReq, cantidad, ventasEstimadas);

    // 4. Actualizamos el arreglo interno de la bebida
    actualizarInsumo(menus, cantDisponible, cantidad, unidad, inventario, capacidades, cantReq);
}
void actualizarInventario(double *cantReq, int cantidad, int ventasEstimadas) {
    // cantidad (ej. 10g) * ventasEstimadas (ej. 120) = 1200g.
    // Lo dividimos entre 1000 para pasarlo a kg (1.2kg) y lo sumamos al requerimiento total.
    *cantReq += (double)(cantidad * ventasEstimadas) / 1000.0;
}
// Actualizar la firma para recibir 'cantReq'
void actualizarInsumo(void **menus, double *cantDisponible, int cantidad, char *unidad, void **inventario,
    int &capacidades, double *cantReq) {

    int numDatos = 0;
    void **insumos = (void**)menus[INSm];

    if (insumos == nullptr) numDatos = 0;
    else while (insumos[numDatos] != nullptr) numDatos++;

    if (numDatos == 0 || numDatos == capacidades-1) incrementarMemoria(insumos, capacidades, numDatos);

    void *disponibilidad = menus[DISm];
    bool *dis = (bool *)disponibilidad;

    // Le pasamos el cantReq en lugar de hacer cálculos extraños adentro
    asignamosInsumos(insumos[numDatos], inventario, cantDisponible, cantidad, unidad, dis, cantReq);

    // ¡No olvides devolver el arreglo al menú como te mencioné antes!
    menus[INSm] = insumos;
}

// Nueva versión limpia de asignamosInsumos
void asignamosInsumos(void *&insumos, void **inventario, double *cantDisponible, int cantidad, char *unidad,
    bool *&disponibilidad, double *cantReq) {

    void **datosInsumo = new void *[3]{};

    datosInsumo[0] = inventario;

    double *cantidadDin = new double;
    *cantidadDin = (double)cantidad; // Aquí se guarda la cantidad unitaria (ej. 10) según la Figura 3
    datosInsumo[1] = cantidadDin;

    datosInsumo[2] = unidad;

    // LA PRUEBA DE FUEGO: Si lo que requiere el inventario total superó lo disponible...
    if (*cantReq > *cantDisponible) {
        *disponibilidad = false; // ...deshabilitamos la bebida
    }

    insumos = datosInsumo;
}

void reporteMenu(const char* nombArch, void *men) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }

    // Imprimimos la cabecera exacta del reporte
    arch << "====================== Menú del día ======================" << endl;

    void **menus = (void **)men;
    int numDatos = 0;

    // Recorremos el menú hasta encontrar el puntero nulo final
    while (menus[numDatos] != nullptr) {
        imprimirBebida(arch, menus[numDatos]);
        arch << "----------------------------------------------------------" << endl;
        numDatos++;
    }
}

void imprimirBebida(ofstream &arch, void *beb) {
    void **bebida = (void **)beb;

    // Extrayendo los datos que necesitamos para el reporte
    char *nombre = (char*)bebida[NOMm];
    char *descripcion = (char*)bebida[DESm];
    char *tipo = (char*)bebida[TIPm];
    double *precio = (double*)bebida[PREm];
    bool *disponible = (bool*)bebida[DISm];

    // Decodificando el tipo de bebida
    const char *tipoStr = "";
    if (tipo[0] == 'C') tipoStr = "Café";
    else if (tipo[0] == 'T') tipoStr = "Té";
    else if (tipo[0] == 'I') tipoStr = "Infusión";
    else if (tipo[0] == 'H') tipoStr = "Chocolate";

    // Imprimiendo con el formato solicitado
    arch << tipoStr << ": " << nombre << endl;
    arch << descripcion << endl;

    // fixed y setprecision(2) aseguran que salga S/2.50 y no S/2.5
    arch << "Precio: S/" << fixed << setprecision(2) << *precio << endl;

    // Operador ternario para imprimir "Si" o "No" en lugar de 1 o 0
    arch << "Disponible: " << (*disponible ? "Si" : "No") << endl;
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
    int numDatos=0;
    while (menus[numDatos] != nullptr) numDatos++;
    for (int i = 0; i < numDatos; ++i) {
        void **bebida = (void **)menus[i];
        char *codigo = (char*)bebida[CODm];
        if (strcmp(codigo,codBebida)==0) return i;
    }
    return NO_ENCONTRADO;
}
int buscarInsumo(char *codInsumo,void **inventario) {
    int numDatos=0;
    while (inventario[numDatos] != nullptr) numDatos++;
    for (int i = 0; i < numDatos; ++i) {
        void **insumo = (void **)inventario[i];
        char *codigo = (char*)insumo[CODi];
        if (strcmp(codigo,codInsumo)==0) return i;
    }
    return NO_ENCONTRADO;
}