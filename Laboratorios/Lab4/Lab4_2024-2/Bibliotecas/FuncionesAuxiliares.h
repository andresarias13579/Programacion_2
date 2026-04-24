//
// Created by alulab14 on 23/04/2026.
//

#ifndef LAB4_2024_2_FUNCIONESAUXILIARES_H
#define LAB4_2024_2_FUNCIONESAUXILIARES_H

void cargarInventario(const char*nombArch,void *&inv);
void leeDatosInventario(ifstream &arch,char *&nombre,char *&uniMedida,double *&cantidad);
void asignamosDatos(void *&inv,char *nombre,char *uniMedida,double *cantidad,char *codigo);
void probarCargarInventario(const char*nombArch,void *inv);
void mostramosProducto(ofstream &arch,void *pro);

void cargarMenu(const char*nombArch,void *&menu);
void leeDatosMenu(ifstream &arch,int *&cantVentas,double *&precio,char *&tipo,
    char *&descripcion,char *&nombre);
void asignamosDatosMenu(void *&menus,char *codigo,char *nombre,char *descripcion,char *tipo,
    double *precio,int *cantVentas);
void probarCargarMenu(const char*nombArch,void *men);
void mostramosMenu(ofstream &arch,void *men);

void actualizarMenu(const char*nombArch,void *inv,void *men);
void leeDatosBebidasInsumos(ifstream &arch,char *&codInsumo,int &cantidad,char *&unidad);
void actulizamosInsumosBebidas(void *men,void *inv,int cantidad,char *unidad,int &capacidades);
void actualizarInventario(double *cantReq,int cantidad);
void actualizarInsumo(void **menus,double *cantDisponible,int cantidad,char *unidad,void **inventario,
    int &capacidades);
void asignamosInsumos(void *insumos,void **inventario,double *cantDisponible,int cantidad,char *unidad,
    bool *&disponibilidad);

char *leeCadenaExacta(ifstream &arch,char delimitador);
void incrementarMemoria(void **&inventario,int &capacidad,int numDatos);
int buscarBebida(char *codBebida,void **menus);
int buscarInsumo(char *codInsumo,void **inventario);

#endif //LAB4_2024_2_FUNCIONESAUXILIARES_H
