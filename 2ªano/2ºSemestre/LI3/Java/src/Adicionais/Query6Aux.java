package Adicionais;

public class Query6Aux implements IQuery6Aux {
    int quantidade;
    int numeroClientes;
    String produto;

    public Query6Aux(int quantidade, int numeroClientes, String produto) {
        this.quantidade = quantidade;
        this.numeroClientes = numeroClientes;
        this.produto = produto;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public int getNumeroClientes() {
        return numeroClientes;
    }

    public String getProduto() {
        return produto;
    }

    @Override
    public String toString() {
        return "|" +
                "Produto = '" + produto + '\'' +
                ", Quantidade = " + quantidade +
                ", Numero de Clientes = " + numeroClientes + "|";
    }
}
