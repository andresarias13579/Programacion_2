import java.util.Scanner;
import java.util.ArrayList;

public class AlumnoDeIntercambio extends Alumno {
    private String paisDeOrigen;
    private ArrayList<String> idiomas;
    private int numeroDeSemestres;

    public AlumnoDeIntercambio(){
        idiomas = new ArrayList<>();
    }

    public String getPaisDeOrigen() {
        return paisDeOrigen;
    }

    public void setPaisDeOrigen(String paisDeOrigen) {
        this.paisDeOrigen = paisDeOrigen;
    }

    public ArrayList<String> getIdiomas() {
        return idiomas;
    }

    public void setIdiomas(ArrayList<String> idiomas) {
        this.idiomas = idiomas;
    }

    public int getNumeroDeSemestres() {
        return numeroDeSemestres;
    }

    public void setNumeroDeSemestres(int numeroDeSemestres) {
        this.numeroDeSemestres = numeroDeSemestres;
    }

    @Override
    public void leer(Scanner arch) {
        super.leer(arch);
        paisDeOrigen = arch.next();
        while (true){
            String idioma;
            idioma = arch.next();
            idiomas.add(idioma);
            if (arch.hasNextInt()) break;
        }
        numeroDeSemestres = arch.nextInt();
    }

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.println("Alumno de intercambio");
        System.out.printf("Pais: %s\n",paisDeOrigen);
        System.out.println("Idiomas:");
        for(String idioma:idiomas){
            System.out.printf("   %s",idioma);
            System.out.println();
        }
        System.out.printf("Permanecera %d semestres\n",numeroDeSemestres);
    }
}
