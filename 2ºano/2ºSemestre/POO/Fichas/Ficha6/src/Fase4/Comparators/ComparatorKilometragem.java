package Fase4.Comparators;

import Fase4.Veiculo;

import java.util.Comparator;

public class ComparatorKilometragem implements Comparator<Veiculo> {
    public int compare(Veiculo a, Veiculo b) {
        return (int) (b.getKilometragem() - a.getKilometragem());
    }
}