package Model.Comparators;

import Adicionais.IParClienteCusto;

import java.util.Comparator;

public class ParClienteCustoComparator implements Comparator<IParClienteCusto> {

    public int compare(IParClienteCusto a, IParClienteCusto b) {

        return (int) (b.getCusto() - a.getCusto());

    }
}
