package Model;

import Adicionais.IParClienteCusto;
import Adicionais.IQuery8Aux;
import Adicionais.ParClienteCusto;
import Adicionais.Query8Aux;
import Model.Comparators.ParClienteCustoComparator;
import Model.Comparators.Query8AuxComparator;
import Model.Comparators.VendaComparator;

import java.util.*;

public class Filiais implements IFiliais {

    private List<IFilial> filiais;

    public Filiais() {
        this.filiais = new ArrayList<>();

        for (int i = 0; i < 3; i++) {
            IFilial filial = new Filial();

            this.filiais.add(filial);
        }

    }

    /**
     * Adiciona vendas.
     *
     * @param vd Venda.
     */
    public void addVDS(IVenda vd) {
        int filial = vd.getFilial() - 1;

        this.filiais.get(filial).addVDS(vd);
    }


    /**
     * Numero de Clientes mensal por filial.
     *
     * @return Resultado.
     */
    public List<List<Set<String>>> num_clientes_mensal_filial() {
        List<List<Set<String>>> res = new ArrayList<>();

        for (int i = 0; i < 3; i++) {
            List<Set<String>> list_aux = new ArrayList<>();
            for (int j = 0; j < 12; j++) {

                Set<String> aux = new TreeSet<>(this.filiais.get(i).getVendas_clientes().get(j).keySet());

                list_aux.add(aux);
            }
            res.add(list_aux);
        }

        return res;
    }

    /**
     * Clientes que nunca compraram.
     *
     * @param clientes Clientes.
     * @return Resultado
     */
    public Set<String> get_clientes_nunca_compraram(Set<String> clientes) {
        filiais.forEach(f -> f.getVendas_clientes().forEach(l -> clientes.stream().filter(v -> l.containsKey(v))));
        return clientes;
    }


    /**
     * Dado um mês válido, determinar o número total global de vendas realizadas e o
     * número total de clientes distintos que as fizeram; Fazer o mesmo mas para cada
     * uma das filiais;
     *
     * @param mes Mês dado.
     * @return Resultado
     */
    public int[] getVendasClientesMes(int mes) {
        int[] array = new int[6];

        for (int i = 0; i < 3; i++)
            array[i] = filiais.get(i).getVendas_clientes().get(mes - 1).size();

        for (int j = 3; j < 6; j++)
            array[j] = filiais.get(j - 3).getVendas_clientes().get(mes - 1).values().stream().mapToInt(List::size).reduce(0, Integer::sum);

        return array;
    }


    /**
     * Informação cliente.
     *
     * @param cliente Codigo Cliente.
     * @return Parsed info.
     */
    public double[] clienteInfo(String cliente) {
        double[] res = new double[36];


        for (IFilial f : this.filiais) {

            for (int i = 0; i < 12; i++) {
                List<IVenda> list = f.getVendas_clientes().get(i).get(cliente);

                if (list != null)
                    list.forEach(v -> {
                        res[v.getMes() - 1]++;
                        res[(v.getMes() - 1) + 24] += v.getFaturacao();
                    });


            }

        }
        return res;
    }


    /**
     * Informação produto.
     *
     * @param produto Codigo Produto.
     * @param array array que completa info
     * @return Parsed info.
     */
    public double[] produtoInfo(String produto, double[] array) {

        for (IFilial f : this.filiais) {

            for (int i = 0; i < 12; i++) {
                Set<String> clientes = new HashSet<>();

                List<IVenda> list = f.getVendas_produtos().get(i).get(produto);

                if (list != null)
                    list.forEach(v -> clientes.add(v.getCodigoCliente()));

                array[i + 12] += clientes.size();
            }

        }

        return array;
    }

    /**
     * Dado um cliente determina a lista de códigos de produtos que mais comprou.
     *
     * @param cliente Codigo de cliente.
     * @return Lista de vendas.
     */
    public List<IVenda> produtosCompradosPorCliente(String cliente) {
        Map<String, IVenda> vendas = new HashMap<>();

        for (IFilial f : filiais) {

            for (int i = 0; i < 12; i++) {

                List<IVenda> list = f.getVendas_clientes().get(i).get(cliente);

                if (list != null) {

                    for (IVenda venda : list) {
                        if (vendas.containsKey(venda.getCodigoProduto())) {
                            vendas.get(venda.getCodigoProduto()).setQt(vendas.get(venda.getCodigoProduto()).getQt() + venda.getQt());
                        } else {
                            vendas.put(venda.getCodigoProduto(), venda.clone());
                        }
                    }

                }
            }
        }
        List<IVenda> res = new ArrayList<>(vendas.values());
        res.sort(new VendaComparator());
        return res;
    }


    /**
     * Determinar, para cada filial, a lista dos três maiores compradores em termos de dinheiro faturado.
     *
     * @return
     */
    public List<IParClienteCusto> top3Clientes() {
        List<IParClienteCusto> res = new ArrayList<>();

        for (IFilial f : filiais) {
            Map<String, IParClienteCusto> vendas = new HashMap<>();

            for (int i = 0; i < 12; i++) {


                for (List<IVenda> list : f.getVendas_clientes().get(i).values()) {

                    for (IVenda venda : list) {
                        if (vendas.containsKey(venda.getCodigoCliente())) {
                            vendas.get(venda.getCodigoCliente()).setCusto(vendas.get(venda.getCodigoCliente()).getCusto() + venda.getFaturacao());
                        } else {
                            vendas.put(venda.getCodigoCliente(), new ParClienteCusto(venda.getCodigoCliente(), venda.getFaturacao()));
                        }
                    }
                }
            }

            List<IParClienteCusto> res_aux = new ArrayList<>(vendas.values());
            res_aux.sort(new ParClienteCustoComparator());
            for (int j = 0; j < 3; j++) res.add(res_aux.get(j));
        }

        return res;
    }

    /**
     * Top n de clientes que mais compraram produtos diferentes.
     *
     * @param n
     * @return
     */
    public List<IQuery8Aux> topXClientes(int n) {
        Map<String, IQuery8Aux> aux = new HashMap<>();

        filiais.forEach(f -> f.getVendas_clientes().forEach(m -> m.values().forEach(l -> {

            if (aux.containsKey(l.get(0).getCodigoCliente())) {
            aux.get(l.get(0).getCodigoCliente()).setQt(aux.get(l.get(0).getCodigoCliente()).getQt() + l.size());
        } else {
            aux.put(l.get(0).getCodigoCliente(), new Query8Aux(l.size(), l.get(0).getCodigoCliente()));
        }
            })));


        List<IQuery8Aux> res = new ArrayList<>(aux.values());
        res.sort(new Query8AuxComparator());
        return res;
    }


    /**
     * Calcula a faturação por mês e por filial.
     *
     * @return Lista mês que contém listas de filiais que contém um map com a quantidade e o produto.
     */
    public List<List<Map<String, Double>>> faturacaoPorMesPorFilial() {
        List<List<Map<String, Double>>> res = new ArrayList<>();

        filiais.forEach(f -> {
            List<Map<String, Double>> lista = new ArrayList<>();

            f.getVendas_clientes().forEach(m -> {
                Map<String, Double> produtos = new TreeMap<>();
                m.forEach((key,value) -> {
                    if (!produtos.containsKey(key)) {
                        produtos.put(key, value.get(0).getQt() * value.get(0).getPreco());
                    } else {
                        produtos.put(key, produtos.get(key) + value.get(0).getQt() * value.get(0).getPreco());
                    }
                });
                lista.add(produtos);
            });
            res.add(lista);
        });


        return res;
    }


}
