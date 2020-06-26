package Model;

public class Venda implements IVenda {

    private String codigoProduto;
    private double preco;
    private int qt;
    private String tipo;
    private String codigoCliente;
    private int mes;
    private int filial;
    private double faturacao;

    public Venda(String codigoProduto, double preco, int qt, String tipo, String codigoCliente, int mes, int filial, double faturacao) {
        this.codigoProduto = codigoProduto;
        this.preco = preco;
        this.qt = qt;
        this.tipo = tipo;
        this.codigoCliente = codigoCliente;
        this.mes = mes;
        this.filial = filial;
        this.faturacao = faturacao;
    }


    public Venda(Venda venda) {
        this.codigoProduto = venda.getCodigoProduto();
        this.preco = venda.getPreco();
        this.qt = venda.getQt();
        this.tipo = venda.getTipo();
        this.codigoCliente = venda.getCodigoCliente();
        this.mes = venda.getMes();
        this.filial = venda.getFilial();
        this.faturacao = venda.getFaturacao();
    }

    public String getCodigoProduto() {
        return this.codigoProduto;
    }

    public double getPreco() {
        return this.preco;
    }

    public int getQt() {
        return this.qt;
    }

    public String getTipo() {
        return this.tipo;
    }

    public String getCodigoCliente() {
        return this.codigoCliente;
    }

    public int getMes() {
        return this.mes;
    }

    public int getFilial() {
        return this.filial;
    }

    public double getFaturacao() {
        return this.faturacao;
    }

    public void setCodigoProduto(String codigoProduto) {
        this.codigoProduto = codigoProduto;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public void setQt(int qt) {
        this.qt = qt;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public void setCodigoCliente(String codigoCliente) {
        this.codigoCliente = codigoCliente;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public void setFilial(int filial) {
        this.filial = filial;
    }

    public void setFaturacao(double faturacao) {
        this.faturacao = faturacao;
    }

    /**
     * verifica se a venda é dada é válida
     *
     * @return true caso o seja flaso caso contrario
     */
    public boolean validade() {
        return this.codigoProduto.matches("^[A-Z][A-Z][1-9][0-9][0-9][0-9]$")
                && this.codigoCliente.matches("^[A-Z](5000|[1-4][0-9][0-9][0-9])$")
                && this.tipo.equals("N") || this.tipo.equals("P")
                && this.preco >= 0.0 && this.preco <= 999.99
                && this.qt >= 1 && this.qt <= 200
                && this.mes >= 1 && this.mes <= 12
                && this.filial >= 1 && this.filial <= 3;
    }


    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || this.getClass() != obj.getClass()) return false;

        IVenda venda = (IVenda) obj;

        return venda.getCodigoCliente().equals(this.codigoCliente) &&
                venda.getCodigoProduto().equals(this.codigoProduto) &&
                venda.getTipo().equals(this.tipo) &&
                venda.getFilial() == this.filial &&
                venda.getMes() == this.mes &&
                venda.getPreco() == this.preco &&
                venda.getQt() == this.qt;

    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append("Cod Cliente : ").append(this.codigoCliente).append(" ")
                .append("Cod Produto : ").append(this.codigoProduto).append(" ")
                .append("Preço : ").append(this.preco).append(" ")
                .append("Quatidade : ").append(this.qt).append(" ")
                .append("Tipo : ").append(this.tipo).append(" ")
                .append("Filial : ").append(this.filial).append(" ")
                .append("Mes : ").append(this.mes).append("\n");

        return sb.toString();
    }

    @Override
    public IVenda clone() {
        return new Venda(this);
    }
}
