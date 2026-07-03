public class CarrilLento extends Carril{
    @Override
    public String getTipo() {
        return "Lento";
    }

    @Override
    public double velocidadMaxima(int km) {
        return 60;
    }

    @Override
    public boolean velocidadPermitida(int km, double velocidad) {
        return velocidad<=velocidadMaxima(km);
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return categoria.compareTo("Camion")==0 ||
                categoria.compareTo("Tractor") == 0||
                categoria.compareTo("Trailer") == 0;
    }
}
