package Fase2;

import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.Set;
import java.util.Iterator;
import java.util.Comparator;
import java.util.TreeSet;
import java.util.TreeMap;
import java.util.stream.Collectors;

public class DriveIt{

    private boolean promocao;
    private Map<String, Veiculo> veiculosDriveIt;


    public DriveIt(){
        this.promocao = false;
        this.veiculosDriveIt = new HashMap<>();
    }

    public DriveIt(boolean promocao,Map<String, Veiculo> map){
        this.promocao = promocao;
        setVeiculos(map);
    }

    public DriveIt(DriveIt driveList){
        this.promocao = driveList.getPromocao();
        this.veiculosDriveIt = driveList.getVeiculosDriveIt();
    }

    public boolean getPromocao(){
        return this.promocao;
    }

    public Map<String, Veiculo> getVeiculosDriveIt(){
        Map<String, Veiculo> list = new HashMap<>();
        this.veiculosDriveIt.forEach((key,value) -> list.put(key,value.clone()));
        return list;
    }

    public void setPromocao(boolean p){
        this.promocao = p;
    }

    public void setVeiculos(Map<String, Veiculo> list){
        this.veiculosDriveIt = new HashMap<>();
        list.forEach((key,value) -> this.veiculosDriveIt.put(key,value.clone()));
    }

    public void adiciona(Veiculo v){
        this.veiculosDriveIt.put(v.getCodigo(),v.clone());
    }

    public List<Veiculo> getVeiculos(){
        return this.getVeiculosDriveIt().
                values().stream().map(Veiculo::clone).
                collect(Collectors.toList());
    }


    public void alteraPromocao(boolean p){
        setPromocao(p);
        for(Veiculo v : this.veiculosDriveIt.values()){
            if(v instanceof VeiculoOcasiao)
                ((VeiculoOcasiao) v).setPromocao(p);
        }
    }


    /**
     * Exercicios
     */

    //i
    public Set<Veiculo> ordenarVeiculos(){
        return this.veiculosDriveIt.values().stream()
                                            .sorted()
                                            .map(Veiculo::clone)
                                            .collect(Collectors.toSet());
    }

    //ii
    public List<Veiculo> ordenarVeiculosLista(){
        return this.veiculosDriveIt.values().stream()
                                            .sorted()
                                            .map(Veiculo::clone)
                                            .collect(Collectors.toList());
    }

    //iii
    public Set<Veiculo> ordenarVeiculos(Comparator<Veiculo> c){
        return this.veiculosDriveIt.values().stream()
                                            .map(Veiculo::clone)
                                            .collect(Collectors.toCollection(() -> new TreeSet<>(c)));
    }

    //iv
    private static Map<String,Comparator<Veiculo>> ordem = new TreeMap<>();

    public void addCriterio(String c,Comparator<Veiculo> cp){
        ordem.put(c,cp);
    }

    //v
    public Iterator<Veiculo> ordernarVeiculos(String criterio){
        return this.veiculosDriveIt.values().stream()
                                            .map(Veiculo::clone)
                                            .collect(Collectors.toCollection(() -> new TreeSet<>(ordem.get(criterio))))
                                            .iterator();
    }



    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();

        this.veiculosDriveIt.forEach((key,value) -> sb.append(value.toString()));

        return sb.toString();
    }

    @Override
    public boolean equals(Object obj){
        if(this == obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        DriveIt drivel = (DriveIt) obj;

        return this.veiculosDriveIt.equals(drivel.getVeiculos());
    }

    @Override
    public DriveIt clone(){
        return new DriveIt(this);
    }

}
