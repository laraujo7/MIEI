package Model.Comparators;

import Model.IVenda;

import java.util.Comparator;

public class VendaComparator implements Comparator<IVenda> {

    public int compare(IVenda venda1, IVenda venda2) {
        if (venda1.getQt() < venda2.getQt()) return 1;
        if (venda1.getQt() > venda2.getQt()) return -1;
        if (venda1.getCodigoCliente().equals(venda2.getCodigoCliente())) {
            return venda1.getCodigoProduto().compareTo(venda2.getCodigoProduto());
        }
        else return  venda1.getCodigoCliente().compareTo(venda2.getCodigoCliente());
    }
}
