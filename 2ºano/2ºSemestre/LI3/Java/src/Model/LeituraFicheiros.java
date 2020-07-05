package Model;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.InputMismatchException;

public class LeituraFicheiros {

    /**
     * le os clientes de um ficheiro dado
     *
     * @param ficheiroClientes ficheiro para ler os clientes
     * @return set de clientes
     */
    public static IClientes loadClientes(String ficheiroClientes) {
        String linha;
        IClientes cls = new Clientes();
        Cliente cl;

        try {
            BufferedReader ficheiro = new BufferedReader(new FileReader(ficheiroClientes));

            while ((linha = ficheiro.readLine()) != null) {
                cl = LeituraFicheiros.linhaCliente(linha);
                if (cl != null) cls.addCLS(cl);
            }
        } catch (IOException e) {
            System.out.println(e);
        }

        return cls;
    }

    /**
     * verifica se um cliente é valido
     *
     * @param linha linha recebida de um ficheiro que deveria ser um cliente
     * @return null se não for valido cliente se for
     */
    public static Cliente linhaCliente(String linha) {
        String[] string = linha.split("\\r?\\n");
        Cliente cliente = null;

        if (string[0].matches("^[A-Z](5000|[1-4][0-9][0-9][0-9])$")) {
            cliente = new Cliente(string[0]);
        }

        return cliente;
    }

    /**
     * le os produtos de um ficheiro
     *
     * @param ficheiroProdutos ficheiro a ser lido
     * @return set de produtos
     */
    public static IProdutos loadProdutos(String ficheiroProdutos) {
        String linha;
        IProdutos prds = new Produtos();
        Produto prd;

        try {
            BufferedReader ficheiro = new BufferedReader(new FileReader(ficheiroProdutos));

            while ((linha = ficheiro.readLine()) != null) {
                prd = LeituraFicheiros.linhaProduto(linha);
                if (prd != null) prds.addPRDS(prd);
            }
        } catch (IOException e) {
            System.out.println(e);
        }

        return prds;
    }

    /**
     * verifica se um produto é valido
     *
     * @param linha linha recebida de um ficheiro que deveria ser um produto
     * @return null se não for valido produto caso seja
     */
    public static Produto linhaProduto(String linha) {
        String[] string = linha.split("\\r?\\n");
        Produto produto = null;

        if (string[0].matches("^[A-Z][A-Z][1-9][0-9][0-9][0-9]$")) {
            produto = new Produto(string[0]);
        }

        return produto;
    }

    /**
     * le uma linha de vendas e caso seja valida guarda a linha
     *
     * @param linha string que contem a venda
     * @return venda nova
     */
    public static IVenda linhaVenda(String linha) {
        String[] string = linha.split(" ");

        String codigoProduto, codigoCliente, tipo;
        int mes, filial, qt;
        double preco;

        codigoProduto = string[0];
        codigoCliente = string[4];
        tipo = string[3];

        try {
            preco = Double.parseDouble(string[1]);
            qt = Integer.parseInt(string[2]);
            mes = Integer.parseInt(string[5]);
            filial = Integer.parseInt(string[6]);
        } catch (InputMismatchException e) {
            return null;
        }

        return new Venda(codigoProduto, preco, qt, tipo, codigoCliente, mes, filial, preco * qt);
    }


}
