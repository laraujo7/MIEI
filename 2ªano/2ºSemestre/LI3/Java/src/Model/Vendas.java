package Model;

import Adicionais.*;
import Model.Comparators.Query6AuxComparator;
import Model.Comparators.VendaComparator;

import java.util.*;
import java.util.stream.Collectors;

public class Vendas implements IVendas {

    private Map<String, List<IVenda>> vendas_produtos;


    public Vendas() {
        this.vendas_produtos = new HashMap<>();

    }


    public void addVDS(IVenda vd) {
        String codProd = vd.getCodigoProduto();

        if (this.vendas_produtos.containsKey(codProd)) {
            this.vendas_produtos.get(codProd).add(vd.clone());
        } else {
            List<IVenda> aux = new ArrayList<>();
            aux.add(vd.clone());

            this.vendas_produtos.put(codProd, aux);
        }

    }

    /**
     * passa todas as ventas e calcula o preço faturado
     *
     * @return faturação
     */
    public double get_faturacao_total() {
        double res = 0;

        for (List<IVenda> l : this.vendas_produtos.values()) {
            for (IVenda v : l) {
                res += v.getPreco() * v.getQt();
            }
        }
        return res;
    }

    /**
     * Verifica o numero de vendas cujo o preço era 0
     *
     * @return numero de vendas
     */
    public int getVendasZero() {
        int res = 0;

        for (List<IVenda> l : this.vendas_produtos.values()) {
            for (IVenda v : l) {
                if (v.getPreco() == 0) {
                    res++;
                }
            }
        }
        return res;
    }

    /**
     * Função que retorna um TreeSet com todos os produtos que não foram comprados
     *
     * @param produtos Um set com todos os produto
     * @return resultado
     */
    public Set<String> getProdutosNaoComprdos(IProdutos produtos) {

        return produtos.getProdutos().stream().filter(p -> !vendas_produtos.containsKey(p)).collect(Collectors.toCollection(TreeSet::new));
    }

    /**
     * Numero de vendas feitas em cada mes
     *
     * @return List onde cada index tem o numero de vendas feitas
     */
    public List<Integer> num_compras_mensal() {
        int[] aux = new int[12];
        List<Integer> res = new ArrayList<>();

        this.vendas_produtos.values().forEach(l -> l.forEach(v -> aux[v.getMes() - 1]++));

        for (int i = 0; i < 12; i++) res.add(aux[i]);

        return res;
    }

    /**
     * Faturação feita em cada mes no total
     *
     * @return List onde cada index tem a faturação feita para todas a vendas
     */
    public List<Double> faturacao_mensal_global() {
        double[] aux = new double[12];
        List<Double> res = new ArrayList<>();

        this.vendas_produtos.values().forEach(l -> l.forEach(v -> aux[v.getMes() - 1] += v.getPreco() * v.getQt()));

        for (int i = 0; i < 12; i++) res.add(aux[i]);

        return res;
    }

    /**
     * Faturação feita em cada mes em cada filial
     *
     * @return List de filiais de List de meses com faturação dentro
     */
    public List<List<Double>> faturacao_mensal_filial() {
        double[][] aux = new double[3][12];
        List<List<Double>> res = new ArrayList<>();

        this.vendas_produtos.values().forEach(l -> l.forEach(v -> aux[v.getFilial() - 1][v.getMes() - 1] += v.getPreco() * v.getQt()));

        for (int i = 0; i < 3; i++) {
            List<Double> list_aux = new ArrayList<>();
            for (int j = 0; j < 12; j++) list_aux.add(aux[i][j]);
            res.add(list_aux);
        }

        return res;
    }

    /**
     * Conta quantas compras um especifico cliente faz por mes e quantos produtos distintos comprou
     *
     * @param cliente o cliente sobre o qual queremos informação
     * @param array   array usado para o resultado
     * @return resultado
     */
    public double[] clienteInfo(String cliente, double[] array) {

        for (List<IVenda> list : vendas_produtos.values()) {
            boolean found = false;
            for (IVenda v : list) {
                if (v.getCodigoCliente().equals(cliente)) {
                    int mes = v.getMes() - 1;
                    array[mes + 12]++;
                    found = true;
                }
                if (found) break;
            }
        }
        return array;
    }

    /**
     * Conta quantos vezes um produto foi vendido todos em cada mes, por quantos clientes diferentes e a faturação nele feita
     *
     * @param produto produto que quer ser procurado
     * @return resultado
     */
    public double[] produtoInfo(String produto) {
        double[] array = new double[36];

        for (IVenda v : this.vendas_produtos.get(produto)) {
            int mes = v.getMes() - 1;
            double preco = v.getPreco() * v.getQt();
            array[mes]++;
            array[mes + 24] += preco;
        }
        return array;
    }

    /**
     * Determina os produtos mais vendidos por quantidade e quantos diferentes clientes os compraram
     *
     * @param n numero de produtos a determinar
     * @return Lista organizada do trio composto pela quantidade, numero de clientes e produto
     */
    public List<IQuery6Aux> produtosMaisVendidos(int n) {
        List<IQuery6Aux> res = new ArrayList<>();

        for (List<IVenda> list : this.vendas_produtos.values()) {

            int qt = list.stream().mapToInt(IVenda::getQt).sum();
            int n_clientes = list.stream().map(IVenda::getCodigoCliente).collect(Collectors.toSet()).size();
            String produto = list.get(0).getCodigoProduto();

            res.add(new Query6Aux(qt, n_clientes, produto));
        }

        res.sort(new Query6AuxComparator());

        return res;
    }

    /**
     * Verifica os X clientes que mais compraram um certo produto dado
     *
     * @param produto produto para pesquisar
     * @param x numero de clientes a apresentar
     * @return resultado
     */
    public List<IVenda> topXClienetesDoProduto(String produto, int x) {
        TreeSet<IVenda> vendas = new TreeSet<>(new VendaComparator());
        List<IVenda> aux = new ArrayList<>();


        for (IVenda v : vendas_produtos.get(produto)) {
            if (!aux.contains(v.getCodigoCliente())) {
                aux.add(v);
            } else {
                IVenda venda = aux.get(aux.indexOf(v.getCodigoProduto()));
                venda.setQt(venda.getQt() + v.getQt());
                venda.setPreco(venda.getPreco() + v.getPreco());
                venda.setFaturacao(venda.getFaturacao() + v.getFaturacao());
            }
        }

        vendas.addAll(aux);

        return vendas.stream().limit(x).collect(Collectors.toList());
    }


}
