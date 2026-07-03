import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;
import java.io.File;

public class ListaDeAlumnos {
    private final ArrayList<Alumno> alumnos;

    public ListaDeAlumnos(){
        alumnos = new ArrayList<>();
    }

    public void cargarAlumnos() throws FileNotFoundException {
        File archivo = new File("Alumnos.txt");
        Scanner arch = new Scanner(archivo);
        String tipo;
        Alumno alumno;
        while (arch.hasNext()){
            tipo = arch.next();
            if (tipo.compareTo("R") == 0) alumno = new AlumnoRegular() ;
            else alumno = new AlumnoDeIntercambio();
            alumno.leer(arch);
            alumnos.add(alumno);
        }
        System.out.println(alumnos.size());
    }

    public void mostrarAlumnos(){
        for (Alumno alum:alumnos){
            alum.imprimir();
        }
    }
}
