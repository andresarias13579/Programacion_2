import java.util.Scanner;

public abstract class Alumno {
    private int codigo;
    private String nombre;

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void leer(Scanner arch){
        codigo = arch.nextInt();
        nombre = arch.next();
    }

    public void imprimir(){
        imprimirLinea('=',55);
        System.out.printf("Codigo del alumno: %10d \n",codigo);
        System.out.printf("Nombre del alumno: %s \n",nombre);
    }

    public void imprimirLinea(char line, int num){
        for (int i = 0; i < num; i++) {
            System.out.print(line);
        }
        System.out.println();
    }
}