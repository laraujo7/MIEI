package View;

import Adicionais.IParClienteCusto;
import Adicionais.IQuery6Aux;
import Adicionais.IQuery8Aux;
import Model.IVenda;

import java.util.List;
import java.util.Map;
import java.util.Set;

public interface IGestVendasView {

    void menu(int titulo);

    void menuPrincipal();

    void menuQueries();

    void dadosEstatisticos_UltiFicheiro(String ultiFicheiro,int vendasErradas, int produtos,
                                        int diffProdutos, int produtosNComprados, int clientes,
                                        int diffClientes, int clientesNComprados, int vendasValor0,
                                        double faturacaoTotal);

    void dadosEstatisticos_Gerais(List<Integer> numComprasMensal, List<Double> fatMensalFilial
            ,List<List<Double>> fatMensalGlobal,List<List<Integer>> clientesMensalFilial);

    void query1(Set<String> produtos,String tempo);

    void query2(int mes, int[] array,String tempo);

    void query3(String cliente,double[] array,String tempo);

    void query4(String produto, double[] array,String tempo);

    void query5(String cliente, List<IVenda> vendas, String tempo);

    void query6(int n, List<IQuery6Aux> top, String tempo);

    void query7(List<IParClienteCusto> top, String tempo);

    void query8(int n, List<IQuery8Aux> topClientes, String tempo);

    void query9(int x, List<IVenda> topX,String tempo);

    void query10(List<List<Map<String, Double>>> faturacao,String tempo);

}
