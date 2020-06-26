package Fase3;

import java.util.Comparator;

public class ComparatorCustoRealKm implements Comparator<Veiculo> {
    public int compare(Veiculo a, Veiculo b) {
        return (int) (b.custoRealKm() - a.custoRealKm());
    }
}