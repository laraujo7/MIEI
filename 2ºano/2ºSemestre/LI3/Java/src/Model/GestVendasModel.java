package Model;

import Adicionais.IParClienteCusto;
import Adicionais.IQuery6Aux;
import Adicionais.IQuery8Aux;

import java.io.*;
import java.util.*;

public class GestVendasModel implements IGestVendasModel, Serializable {

    private IClientes clientes;
    private IProdutos produtos;
    private IVendas vendas;
    private IFiliais filiais;
    private String ultFicheiroLido;
    private int vendasErradas;


    public GestVendasModel() {
        this.clientes = new Clientes();
        this.produtos = new Produtos();
        this.vendas = new Vendas();
        this.filiais = new Filiais();
        this.ultFicheiroLido = null;
        this.vendasErradas = 0;
    }


    /**
     * Criar estrutura de Dados.
     *
     * @param ficheiroClientes Ficheiro Clientes.
     * @param ficheiroProdutos Ficheiro Produtos.
     * @param ficheiroVendas   Ficheiro Vendas.
     */
    public void criarData(String ficheiroClientes, String ficheiroProdutos, String ficheiroVendas) {
        this.clientes = LeituraFicheiros.loadClientes(ficheiroClientes);
        this.produtos = LeituraFicheiros.loadProdutos(ficheiroProdutos);


        String linha;
        IVenda vd;

        try {
            BufferedReader ficheiro = new BufferedReader(new FileReader(ficheiroVendas));

            while ((linha = ficheiro.readLine()) != null) {
                vd = LeituraFicheiros.linhaVenda(linha);

                if (vd != null && vd.validade() && this.clientes.existe(vd.getCodigoCliente()) && this.produtos.existe(vd.getCodigoProduto())) {

                    this.vendas.addVDS(vd);
                    this.filiais.addVDS(vd);

                } else this.vendasErradas++;
            }
        } catch (IOException e) {
            System.out.println(e);
        }

        this.ultFicheiroLido = ficheiroVendas;
    }

    public Set<String> getCLS() {
        return clientes.getClientes();
    }

    public Set<String> getPRDS() {
        return produtos.getProdutos();
    }

    public String getUltFicheiroLido() {
        return ultFicheiroLido;
    }

    public int getVendasErradas() {
        return vendasErradas;
    }

    public Set<String> produtosNaoComprados() {

        return vendas.getProdutosNaoComprdos(produtos);

    }

    public double faturacaoTotal() {
        return vendas.get_faturacao_total();
    }

    public int getVendasValorZero() {
        return vendas.getVendasZero();
    }

    public Set<String> clientesNuncaCompraram() {
        return filiais.get_clientes_nunca_compraram(clientes.getClientes());
    }

    public List<Integer> numComprasMensal() {
        return this.vendas.num_compras_mensal();
    }

    public List<Double> faturacaoMensalGlobal() {
        return this.vendas.faturacao_mensal_global();
    }

    public List<List<Double>> faturacaoMensalFilial() {
        return this.vendas.faturacao_mensal_filial();
    }

    /**
     * Numero de Clientes mensais por filial.
     *
     * @return Resultado.
     */
    public List<List<Integer>> numClientesMensalFilial() {
        List<List<Set<String>>> aux = this.filiais.num_clientes_mensal_filial();
        List<List<Integer>> res = new ArrayList<>();

        for (int i = 0; i < 3; i++) {
            List<Integer> list_aux = new ArrayList<>();
            for (int j = 0; j < 12; j++) list_aux.add(aux.get(i).get(j).size());
            res.add(list_aux);
        }

        return res;
    }

    /**
     * Escreve um objeto.
     *
     * @param nomeFicheiro Ficheiro onde escrever.
     * @throws IOException
     */
    public void writeObject(String nomeFicheiro) throws IOException {
        FileOutputStream fileOutputStream = new FileOutputStream(nomeFicheiro);
        ObjectOutputStream oos = new ObjectOutputStream(fileOutputStream);
        oos.writeObject(this);
    }

    /**
     * Lè um objeto.
     *
     * @param nomeFicheiro
     * @return Gestão de Vendas Model.
     * @throws ClassNotFoundException
     * @throws IOException
     */
    public GestVendasModel readObject(String nomeFicheiro) throws ClassNotFoundException, IOException {
        FileInputStream fileInputStream = new FileInputStream(nomeFicheiro);
        ObjectInputStream ois = new ObjectInputStream(fileInputStream);
        return (GestVendasModel) ois.readObject();
    }

    /**
     * Função para realizar query 1.
     *
     * @return Resposta.
     */
    public Set<String> query1() {
        return vendas.getProdutosNaoComprdos(produtos);
    }

    /**
     * Função para realizar query 2.
     *
     * @param mes Mes dado.
     * @return Resultado.
     */
    public int[] query2(int mes) {
        return filiais.getVendasClientesMes(mes);
    }

    /**
     * Função para realizar query 3.
     *
     * @param cliente Cliente dado.
     * @return Resultado.
     */
    public double[] query3(String cliente) {
        return vendas.clienteInfo(cliente, filiais.clienteInfo(cliente));
    }

    /**
     * Função para realizar query 4.
     *
     * @param produto Produto dado.
     * @return Resultado.
     */
    public double[] query4(String produto) {
        return filiais.produtoInfo(produto, vendas.produtoInfo(produto));
    }

    /**
     * Função para realizar query 5.
     *
     * @param cliente Cliente dado.
     * @return Resultado.
     */
    public List<IVenda> query5(String cliente) {
        return filiais.produtosCompradosPorCliente(cliente);
    }

    /**
     * Função para realizar query 6.
     *
     * @param n Numero dado.
     * @return Resultado.
     */
    public List<IQuery6Aux> query6(int n) {
        return vendas.produtosMaisVendidos(n);
    }

    /**
     * Função para realizar query 7.
     *
     * @return Resultado.
     */
    public List<IParClienteCusto> query7() {
        return filiais.top3Clientes();

    }

    /**
     * Função para realizar query 8.
     *
     * @param n Numero dado.
     * @return Resultado.
     */
    public List<IQuery8Aux> query8(int n) {
        return filiais.topXClientes(n);
    }

    /**
     * Função para realizar query 9.
     *
     * @param produto Produto dado.
     * @param x       Numero dado.
     * @return resultado.
     */
    public List<IVenda> query9(String produto, int x) {
        return vendas.topXClienetesDoProduto(produto, x);
    }

    /**
     * Função para realizar query 10.
     *
     * @return Resultado.
     */
    public List<List<Map<String, Double>>> query10() {
        return filiais.faturacaoPorMesPorFilial();

    }


}
