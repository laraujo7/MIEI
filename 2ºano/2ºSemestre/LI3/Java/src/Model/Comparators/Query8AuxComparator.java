package Model.Comparators;

import Adicionais.IQuery8Aux;

import java.util.Comparator;

public class Query8AuxComparator implements Comparator<IQuery8Aux> {

    public int compare(IQuery8Aux a, IQuery8Aux b) {

        if(b.getQt() == a.getQt()) return a.getCliente().compareTo(b.getCliente());
        else return b.getQt() - a.getQt();
    }
}
