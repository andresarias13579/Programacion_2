#include <iostream>
#include <iomanip>

using namespace std;
#include "Bibliotecas/FuncionesAuxiliares.h"

int main() {
    void *inventario,*menu;

    cargarInventario("ArchivosDeDatos/inventario.csv",inventario);
    probarCargarInventario("ArchivoDeReporte/prueba-inventario.txt",inventario);

    cargarMenu("ArchivosDeDatos/menu.csv",menu);
    probarCargarMenu("ArchivoDeReporte/prueba-menu.txt",menu);

    actualizarMenu("ArchivosDeDatos/insumos-bebidas.csv",inventario,menu);
    reporteMenu("ArchivoDeReporte/menu.txt",menu);

    return 0;
}