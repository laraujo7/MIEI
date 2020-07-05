import java.util.Comparator;

public class ComparatorValorEncomenda implements Comparator<EncEficiente> {

    public int compare(EncEficiente a1, EncEficiente a2) {
        return (int) (a2.calculaValorTotal() - a1.calculaValorTotal());
    }

}