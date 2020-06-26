package Model;


import Adicionais.IParClienteCusto;
import Adicionais.IQuery8Aux;

import java.io.Serializable;
import java.util.List;
import java.util.Map;
import java.util.Set;

public interface IFiliais extends Serializable {

    void addVDS(IVenda vd);

    List<List<Set<String>>> num_clientes_mensal_filial();

    Set<String> get_clientes_nunca_compraram(Set<String> clientes);

    int[] getVendasClientesMes(int mes);

    double[] clienteInfo(String cliente);

    double[] produtoInfo(String produto, double[] array);

    List<IVenda> produtosCompradosPorCliente(String cliente);

    List<IParClienteCusto> top3Clientes();

    List<IQuery8Aux> topXClientes(int n);

    List<List<Map<String, Double>>> faturacaoPorMesPorFilial();

}
