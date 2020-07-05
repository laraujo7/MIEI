package Model;

import Adicionais.IQuery6Aux;

import java.io.Serializable;
import java.util.List;
import java.util.Set;

public interface IVendas extends Serializable {

    void addVDS(IVenda vd);

    double get_faturacao_total();

    int getVendasZero();

    List<Integer> num_compras_mensal();

    List<Double> faturacao_mensal_global();

    List<List<Double>> faturacao_mensal_filial();

    Set<String> getProdutosNaoComprdos(IProdutos produtos);

    double[] clienteInfo(String cliente,double[] array);

    double[] produtoInfo(String produto);

    List<IQuery6Aux> produtosMaisVendidos(int n);

    List<IVenda> topXClienetesDoProduto(String produto, int x);
}
