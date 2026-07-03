import java.util.Scanner;

public class Captura extends Registro{
    private String placa;
    private double velocidad;
    private Carril carril;
    private double latitud;
    private double longitud;
    private String region;
    private String provincia;
    private int km;
    private String fecha;
    private String hora;
    private String codigoCamara;

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public double getVelocidad() {
        return velocidad;
    }

    public void setVelocidad(double velocidad) {
        this.velocidad = velocidad;
    }

    public Carril getCarril() {
        return carril;
    }

    public void setCarril(Carril carril) {
        this.carril = carril;
    }

    public double getLatitud() {
        return latitud;
    }

    public void setLatitud(double latitud) {
        this.latitud = latitud;
    }

    public double getLongitud() {
        return longitud;
    }

    public void setLongitud(double longitud) {
        this.longitud = longitud;
    }

    public String getRegion() {
        return region;
    }

    public void setRegion(String region) {
        this.region = region;
    }

    public String getProvincia() {
        return provincia;
    }

    public void setProvincia(String provincia) {
        this.provincia = provincia;
    }

    public int getKm() {
        return km;
    }

    public void setKm(int km) {
        this.km = km;
    }

    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    public String getHora() {
        return hora;
    }

    public void setHora(String hora) {
        this.hora = hora;
    }

    public String getCodigoCamara() {
        return codigoCamara;
    }

    public void setCodigoCamara(String codigoCamara) {
        this.codigoCamara = codigoCamara;
    }

    public Carril getCarril(int numero){
        switch (numero){
            case 1: return new CarrilEmergencia();
            case 2: return new CarrilLento();
            case 3: return new CarrilEstandar();
            case 4: return new CarrilEstandar();
            case 5: return new CarrilRapido();
            default: return null;
        }
    }

    @Override
    public void cargar(Scanner archivo) {
        placa = archivo.next();
        velocidad = archivo.nextDouble();
        int nroCarril;
        nroCarril = archivo.nextInt();
        carril = getCarril(nroCarril);
        latitud = archivo.nextDouble();
        longitud = archivo.nextDouble();
        region = archivo.next();
        provincia = archivo.next();
        km = archivo.nextInt();
        fecha = archivo.next();
        hora = archivo.next();
        codigoCamara = archivo.next();
    }

    @Override
    public void imprimir() {
        System.out.printf("Placa: %s\n",placa);
        System.out.printf("Velocidad: %f\n",velocidad);
        System.out.printf("Carril: %s\n",carril.getTipo());
        System.out.printf("Ubicacion: Lat %f Long %f\n",latitud,longitud);
        System.out.printf("Region: %s\n",region);
        System.out.printf("Provincia: %s\n",provincia);
        System.out.printf("Kilometro: %d\n",km);
        System.out.printf("Fecha: %s\n",fecha);
        System.out.printf("Hora: %s\n",hora);
        System.out.printf("Codigo Camara: %s\n",codigoCamara);
    }
}
