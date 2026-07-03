public class RegistroInformacion {
    private String codigoInfraccion;
    private double monto;
    private int puntos;
    private Captura captura;
    private Vehiculo vehiculo;

    public String getCodigoInfraccion() {
        return codigoInfraccion;
    }

    public void setCodigoInfraccion(String codigoInfraccion) {
        this.codigoInfraccion = codigoInfraccion;
    }

    public double getMonto() {
        return monto;
    }

    public void setMonto(double monto) {
        this.monto = monto;
    }

    public int getPuntos() {
        return puntos;
    }

    public void setPuntos(int puntos) {
        this.puntos = puntos;
    }

    public Captura getCaptura() {
        return captura;
    }

    public void setCaptura(Captura captura) {
        this.captura = captura;
    }

    public Vehiculo getVehiculo() {
        return vehiculo;
    }

    public void setVehiculo(Vehiculo vehiculo) {
        this.vehiculo = vehiculo;
    }

    public void mostrar(){
        System.out.println("        REGISTRO DE INFRACCION DE TRANSITO");
        System.out.printf("Codigo de infraccion: %s\n",codigoInfraccion);
        System.out.printf("Monto de la multa: %f\n",monto);
        System.out.printf("Puntos en licencia: %d\n",puntos);
        vehiculo.imprimir();
        System.out.println();
        System.out.println("DATOS DE LA CAPTURA ELECTRONICA");
        captura.imprimir();
        System.out.println();
    }
}
