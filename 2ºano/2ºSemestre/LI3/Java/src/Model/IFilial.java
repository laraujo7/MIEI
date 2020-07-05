package Model;

import java.io.Serializable;
import java.util.List;
import java.util.Map;

public interface IFilial extends Serializable {


    void addVDS(IVenda vd);

    List<Map<String, List<IVenda>>> getVendas_clientes();

    List<Map<String, List<IVenda>>> getVendas_produtos();

}
