import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class AutoridadTransporte {
    private ArrayList<Propietario> propietarios;
    private ArrayList<Vehiculo> vehiculos;
    private ArrayList<Captura> capturas;
    private ArrayList<RegistroInformacion> registroInfracciones;
    private Scanner archivo;

    public AutoridadTransporte(String nombArch) throws FileNotFoundException{
        File arch = new File(nombArch);
        archivo = new Scanner(arch);
        propietarios = new ArrayList<>();
        vehiculos = new ArrayList<>();
        capturas = new ArrayList<>();
        registroInfracciones = new ArrayList<>();
    }

    public void cargarDatos() {

        while (archivo.hasNext() && !archivo.hasNext("FIN")){
            Propietario registro = new Propietario();
            registro.cargar(archivo);
            propietarios.add(registro);
        }
        archivo.next();
        while (archivo.hasNext() && !archivo.hasNext("FIN")){
            Vehiculo registro = new Vehiculo();
            registro.cargar(archivo);
            int dni;
            dni = archivo.nextInt();
            for (Propietario p:propietarios) if (p.getDni() == dni) registro.setPropietario(p);
            vehiculos.add(registro);
        }
        archivo.next();
        while (archivo.hasNext()){
            Captura registro = new Captura();
            registro.cargar(archivo);
            capturas.add(registro);
        }
    }

    public void procesarCapturas(){
        for (Captura c:capturas){
            procesarUnaCaptura(c);
        }
    }

    private void procesarUnaCaptura(Captura captura){
        for (Vehiculo v:vehiculos){
            if (captura.getPlaca().compareTo(v.getPlaca())==0) {
                Carril carril = captura.getCarril();
                if (!carril.velocidadPermitida(captura.getKm(),captura.getVelocidad())){
                    RegistroInformacion registro = new RegistroInformacion();
                    registro.setCaptura(captura);
                    registro.setMonto(963);
                    registro.setPuntos(50);
                    registro.setVehiculo(v);
                    registro.setCodigoInfraccion("M20");
                    registroInfracciones.add(registro);
                }
                if (!carril.vehiculoPermitido(v.getCategoria())){
                    RegistroInformacion registro = new RegistroInformacion();
                    registro.setCaptura(captura);
                    registro.setMonto(428);
                    registro.setPuntos(50);
                    registro.setVehiculo(v);
                    registro.setCodigoInfraccion("G29");
                    registroInfracciones.add(registro);
                }

                break;
            }
        }
    }

    private void imprimeLinea(char line, int num){
        for (int i = 0; i < num; i++) {
            System.out.print(line);
        }
        System.out.println();
    }

    public void imprimirInfracciones(){
        for (RegistroInformacion rg:registroInfracciones){
            rg.mostrar();
            imprimeLinea('=',55);
        }
    }
}
