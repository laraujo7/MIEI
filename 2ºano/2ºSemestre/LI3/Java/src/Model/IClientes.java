package Model;

import java.io.Serializable;
import java.util.Set;

public interface IClientes extends Serializable {

    Set<String> getClientes();

    void setCLS(Set<ICliente> cls);

    boolean existe(String codCl);

    void addCLS(ICliente cl);


}
