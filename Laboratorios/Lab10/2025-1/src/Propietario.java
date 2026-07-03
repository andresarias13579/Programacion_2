import java.util.Scanner;

public class Propietario extends Registro{
    private int dni;
    private String nombre;
    private String apellidos;
    private String direccion;

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellidos() {
        return apellidos;
    }

    public void setApellidos(String apellidos) {
        this.apellidos = apellidos;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    @Override
    public void cargar(Scanner archivo) {
        dni = archivo.nextInt();
        nombre = archivo.next();
        apellidos = archivo.next();
        direccion = archivo.next();
    }

    @Override
    public void imprimir() {
        System.out.printf("DNI: %d\n",dni);
        System.out.printf("Nombres: %s\n",nombre);
        System.out.printf("Apellido: %s\n",apellidos);
        System.out.printf("Direccion: %s\n",direccion);
    }
}
