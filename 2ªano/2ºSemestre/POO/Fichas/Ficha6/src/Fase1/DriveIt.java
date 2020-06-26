package Fase1;

import java.util.*;
import java.util.stream.Collectors;

public class DriveIt {

    private boolean promocao;
    private Map<String, Veiculo> veiculosDriveIt;


    public DriveIt(){
        this.promocao = false;
        this.veiculosDriveIt = new HashMap<>();
    }

    public DriveIt(boolean promocao, Map<String, Veiculo> map){
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


    //i
    public boolean existeVeiculo(String cod){
        return this.veiculosDriveIt.containsKey(cod);
    }

    //ii
    public int quantos(){
        return this.veiculosDriveIt.size();
    }

    //iii
    public int quantos(String marca){
        return (int) this.veiculosDriveIt.values().stream().filter(v -> v.getMarca().equals(marca)).count();
    }

    //iv
    public Veiculo getVeiculo(String cod){
        return this.veiculosDriveIt.get(cod).clone();
    }

    //v
    public void adiciona(Veiculo v){
        this.veiculosDriveIt.put(v.getCodigo(),v.clone());
    }

    //vi
    public List<Veiculo> getVeiculos(){
        return this.getVeiculosDriveIt().
                values().stream().map(Veiculo::clone).
                collect(Collectors.toList());
    }

    //vii
    public void adiciona(Set<Veiculo> vs){
        Map<String, Veiculo> st = this.getVeiculosDriveIt();
        vs.forEach(v -> st.put(v.getCodigo(),v.clone()));
        setVeiculos(st);
    }

    //viii
    public void registarAluguer(String codVeiculo, int numKms){
        Veiculo v = getVeiculo(codVeiculo);

        v.setKilometragem(v.getKilometragem() + numKms);
        v.setnClientes(v.getNClientes());

        adiciona(v);
    }

    //ix
    public void classificarVeiculo(String cod, int classificacao) {
        Veiculo v = getVeiculo(cod);

        if(classificacao >= 0 && classificacao <= 10) {
            int res = ((v.getClassificacao() * v.getNClientes()) + classificacao) / (v.getNClientes() + 1);

            if (res > 10) v.setClassificacao(10);
            else v.setClassificacao(Math.max(res, 0));

            adiciona(v);
        }
        else System.out.println("Classificação Invalida");
    }

    //x
    public int custoRealKm(String cod){
        return (int) (this.veiculosDriveIt.get(cod).getPreco() * 1.1);
    }

    public void alteraPromocao(boolean p){
        setPromocao(p);
        for(Veiculo v : this.veiculosDriveIt.values()){
            if(v instanceof VeiculoOcasiao)
                ((VeiculoOcasiao) v).setPromocao(p);
        }
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
