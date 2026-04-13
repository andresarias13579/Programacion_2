#include <iostream>
#include <iomanip>
#include <fstream>

#define MAX_ALUMNOS 100
#define MAX_CURSOS 10

using namespace std;
#include "MisBibliotecas/Estructuras.h"
#include "MisBibliotecas/Operadores.h"
#include "MisBibliotecas/FuncionesAuxiliares.h"

int main() {
    //1
    struct Alumnos arrAlumnos[MAX_ALUMNOS]{};
    leerArchivoAlumnos("ArchivoDeDatos/Alumnos.csv",arrAlumnos);
    //2
    struct Cursos arrCursos[MAX_CURSOS]{};
    leerArchivoCursos("ArchivoDeDatos/Cursos.csv",arrCursos);
    //3
    leerArchivoMatriculaYActualizar("ArchivoDeDatos/Matricula.csv",arrAlumnos,arrCursos);
    //4
    imprimirReporteCursos("ArchivoDeReporte/ReporteDeCursos.txt",arrCursos);

    return 0;
}