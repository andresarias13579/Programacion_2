public class CarrilRapido extends Carril{
    @Override
    public String getTipo() {
        return "Rapido";
    }

    @Override
    public double velocidadMaxima(int km) {
        if ((km <= 100)) return 120;
        else if (km>100 && km<=200) return 160;
        else return 140;
    }

    @Override
    public boolean velocidadPermitida(int km, double velocidad) {
        return velocidad<=velocidadMaxima(km);
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return categoria.compareTo("Coupe") == 0 ||
                categoria.compareTo("SUV") == 0 ||
                categoria.compareTo("Camioneta") == 0||
                categoria.compareTo("Sedan")  == 0;
    }
}
