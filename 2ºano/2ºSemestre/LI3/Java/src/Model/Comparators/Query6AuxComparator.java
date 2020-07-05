package Model.Comparators;

import Adicionais.IQuery6Aux;

import java.util.Comparator;

public class Query6AuxComparator implements Comparator<IQuery6Aux> {

    public int compare(IQuery6Aux a, IQuery6Aux b) {

        if (a.getQuantidade() == b.getQuantidade())
            return b.getNumeroClientes() - a.getNumeroClientes();

        else return b.getQuantidade() - a.getQuantidade();

    }
}
