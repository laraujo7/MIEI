import java.util.ArrayList;
import java.util.Iterator;

public class CasaInteligente {

    private String nome;
    private ArrayList<Lampada> lampadas;

    public CasaInteligente(){
        this.nome = "n/a";
        this.lampadas = new ArrayList<>();
    }

    public CasaInteligente(String name, ArrayList<Lampada> lamps){
        this.nome = name;
        setLampadas(lamps);
    }

    public CasaInteligente(CasaInteligente casaI){
        this.nome = casaI.getNome();
        setLampadas(casaI.getLampadas());
    }

    public String getNome(){
        return this.nome;
    }

    public ArrayList<Lampada> getLampadas(){
        ArrayList<Lampada> aux = new ArrayList<>();
        for(Lampada l : this.lampadas) aux.add(l.clone());

        return aux;
    }

    public void setNome(String name){
        this.nome = name;
    }

    public void setLampadas(ArrayList<Lampada> lamps) {
        this.lampadas = new ArrayList<>();
        for (Lampada l : lamps) this.lampadas.add(l.clone());
    }

    //i
    public void addLampada(Lampada l){
        this.lampadas.add(l.clone());
    }

    //ii
    public void ligaLampadaNormal(int index){
        this.lampadas.get(index).lampON();
    }

    //iii
    public void ligaLampadaEco(int index){
        this.lampadas.get(index).lampECO();
    }

    //iv
    public int qtEmEco(){
        int res = 0;

        for(Lampada l : this.lampadas) if(l.getModo() == 2) res++;

        return res;
    }

    //v
    public void removeLampada(int index){
        if(!this.lampadas.isEmpty()) this.lampadas.remove(index);
    }

    //vi.1
    public void ligaTodasEco(){
        this.lampadas.stream().forEach(Lampada::lampECO);
    }

    //vi.2
    public void ligaTodasMax(){
        this.lampadas.stream().forEach(Lampada::lampON);
    }

    //vii
    public double consumoTotal(){
        return this.lampadas.stream().mapToDouble(Lampada::getTotal).sum();
    }

    //viii
    public void reset(){
        for(Lampada l : this.lampadas) l.setTotal(0);
    }


    public boolean equals(Object obj){
        if(this == obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        CasaInteligente casaI = (CasaInteligente) obj;

        return casaI.getNome().equals(this.nome) && casaI.getLampadas().equals(this.lampadas);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();

        sb.append("Casa -> ").append(this.getNome()).append("\n");

        for(Lampada l : this.getLampadas()) sb.append(l.toString()).append("\n");

        return sb.toString();
    }

    public CasaInteligente clone(){
        return new CasaInteligente(this);
    }


}