package Model;

import java.io.Serializable;
import java.util.Map;
import java.util.Set;

public interface IProdutos extends Serializable {

    Set<String> getProdutos();

    public void addPRDS(IProduto prd);

    boolean existe(String codProd);

}
