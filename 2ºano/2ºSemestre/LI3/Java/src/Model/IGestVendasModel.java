package Model;

import Adicionais.IParClienteCusto;
import Adicionais.IQuery6Aux;
import Adicionais.IQuery8Aux;

import java.io.IOException;
import java.io.Serializable;
import java.util.List;
import java.util.Map;
import java.util.Set;

public interface IGestVendasModel extends Serializable {

    void criarData(String ficheiroClientes,String ficheiroProdutos ,String ficheiroVendas);

    Set<String> getCLS();

    Set<String> getPRDS();

    String getUltFicheiroLido();

    int getVendasErradas();

    Set<String> produtosNaoComprados();

    double faturacaoTotal();

    int getVendasValorZero();

    Set<String> clientesNuncaCompraram();

    List<Integer> numComprasMensal();

    List<Double> faturacaoMensalGlobal();

    List<List<Double>> faturacaoMensalFilial();

    List<List<Integer>> numClientesMensalFilial();

    void writeObject(String nomeFicheiro) throws IOException;

    GestVendasModel readObject(String nomeFicheiro) throws ClassNotFoundException, IOException;

    Set<String> query1();

    int[] query2(int mes);

    double[] query3(String cliente);

    double[] query4(String produto);

    List<IVenda> query5(String cliente);

    List<IQuery6Aux> query6(int i);

    List<IParClienteCusto> query7();

    List<IQuery8Aux> query8(int n);

    List<IVenda> query9(String produto, int num);

    List<List<Map<String, Double>>> query10();

}
