package Fase4;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
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
     * Exercicio
     */

    public List<BonificaKms> daoPontos(){
        return this.veiculosDriveIt.values().stream()
                                            .filter(v -> v instanceof VeiculoPremium || v instanceof AutocarroInteligente)
                                            .map(v -> (BonificaKms) v.clone())
                                            .collect(Collectors.toList());
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
