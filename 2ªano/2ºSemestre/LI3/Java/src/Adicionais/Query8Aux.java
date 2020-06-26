package Adicionais;

public class Query8Aux implements IQuery8Aux {

    private String cliente;
    private int qt;

    public Query8Aux(int qt, String cliente){
        this.cliente = cliente;
        this.qt = qt;
    }

    public String getCliente() {
        return cliente;
    }

    public int getQt() {
        return qt;
    }

    public void setQt(int qt) {
        this.qt = qt;
    }

    @Override
    public String toString() {
        return "Cliente = '" + cliente + '\n' +
                "Quantidade = " + qt + '\n';
    }
}
