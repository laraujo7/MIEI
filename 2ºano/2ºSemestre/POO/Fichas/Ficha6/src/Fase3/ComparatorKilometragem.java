package Fase3;

import java.util.Comparator;

public class ComparatorKilometragem implements Comparator<Veiculo> {
    public int compare(Veiculo a, Veiculo b) {
        return (int) (b.getKilometragem() - a.getKilometragem());
    }
}