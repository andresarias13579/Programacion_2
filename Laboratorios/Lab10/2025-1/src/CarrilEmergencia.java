public class CarrilEmergencia extends Carril{
    @Override
    public String getTipo() {
        return "Emergencia";
    }

    @Override
    public double velocidadMaxima(int km) {
        return 80;
    }

    @Override
    public boolean velocidadPermitida(int km, double velocidad) {
        return velocidad <= velocidadMaxima(km);
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return categoria.compareTo("Ambulancia")==0 || categoria.compareTo("Grua")==0;
    }
}
