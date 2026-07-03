import java.util.Scanner;

public class Vehiculo extends Registro{
    private String placa;
    private String marca;
    private String modelo;
    private int anhoFab;
    private String categoria;
    private Propietario propietario;

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getAnhoFab() {
        return anhoFab;
    }

    public void setAnhoFab(int anhoFab) {
        this.anhoFab = anhoFab;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public Propietario getPropietario() {
        return propietario;
    }

    public void setPropietario(Propietario propietario) {
        this.propietario = propietario;
    }

    @Override
    public void cargar(Scanner archivo) {
        placa = archivo.next();
        marca = archivo.next();
        modelo = archivo.next();
        anhoFab = archivo.nextInt();
        categoria = archivo.next();
    }

    @Override
    public void imprimir() {
        System.out.println();
        System.out.println("DESTINATARIO DE LA INFRACCION");
        propietario.imprimir();
        System.out.println();
        System.out.println("DATOS DEL VEHICULO");
        System.out.printf("Placa: %s\n",placa);
        System.out.printf("Marca: %s\n",marca);
        System.out.printf("Modelo: %s\n",modelo);
        System.out.printf("Anho: %d\n",anhoFab);
        System.out.printf("Categoria: %s\n",categoria);
    }
}
