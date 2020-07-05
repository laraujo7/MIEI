package Adicionais;

public class ParClienteCusto implements IParClienteCusto {

    private String cliente;
    private double custo;

    public ParClienteCusto(String cliente, double custo) {
        this.cliente = cliente;
        this.custo = custo;
    }

    public ParClienteCusto() {
        this.cliente = "";
        this.custo = 0.0;
    }

    public void setCliente(String cliente) {
        this.cliente = cliente;
    }

    public void setCusto(double custo) {
        this.custo = custo;
    }

    public void set (ParClienteCusto par) {
        this.cliente = par.getCliente();
        this.custo = par.getCusto();
    }

    public String getCliente() {
        return cliente;
    }

    public double getCusto() {
        return custo;
    }

    @Override
    public String toString() {
        return "ParClienteCusto{" +
                "cliente='" + cliente + '\'' +
                ", custo=" + custo +
                '}';
    }
}
