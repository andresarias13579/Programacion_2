public class CarrilEstandar extends Carril{
    @Override
    public String getTipo() {
        return "Estandar";
    }

    @Override
    public double velocidadMaxima(int km) {
        if (km<=100) return 80;
        else if (km>100 && km<=200) return 120;
        else return 100;
    }

    @Override
    public boolean velocidadPermitida(int km, double velocidad) {
        return velocidad<=velocidadMaxima(km);
    }

    @Override
    public boolean vehiculoPermitido(String categoria) {
        return categoria.compareTo("Motocicleta") == 0 ||
                categoria.compareTo("Coupe") == 0 ||
                categoria.compareTo("SUV") == 0 ||
                categoria.compareTo("Camioneta") == 0 ||
                categoria.compareTo("Sedan") == 0 ||
                categoria.compareTo("Ambulancia") == 0;
    }
}
