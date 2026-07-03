import java.util.Scanner;

public class AlumnoRegular extends Alumno {
    private String especialidad;
    private String facultad;

    public String getEspecialidad() {
        return especialidad;
    }

    public void setEspecialidad(String especialidad) {
        this.especialidad = especialidad;
    }

    public String getFacultad() {
        return facultad;
    }

    public void setFacultad(String facultad) {
        this.facultad = facultad;
    }

    @Override
    public void leer(Scanner arch) {
        super.leer(arch);
        especialidad = arch.next();
        facultad = arch.next();
    }

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.println("Alumno Regular:");
        System.out.printf("Especialidad: %s\n",especialidad);
        System.out.printf("Facultad:     %s\n",facultad);
    }
}
