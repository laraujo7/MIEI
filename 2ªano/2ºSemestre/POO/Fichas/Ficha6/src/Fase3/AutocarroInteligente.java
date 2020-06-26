package Fase3;

public class AutocarroInteligente extends Veiculo implements BonificaKms {

    private int percentagemOcupacao;
    private int pontosPorKm;

    public AutocarroInteligente(){
        super();
        this.percentagemOcupacao = 0;
        this.pontosPorKm = 0;
    }

    public AutocarroInteligente(String cod, String marca, String modelo, int ano, double velocMedia,
                                double preco, int classi , double kilometragem, int nClientes,
                                int percentagemOcupacao, int pontosPorKm){

        super(cod,marca,modelo,ano,velocMedia,preco,classi,kilometragem,nClientes);
        this.percentagemOcupacao = percentagemOcupacao;
        this.pontosPorKm = pontosPorKm;
    }

    public AutocarroInteligente(AutocarroInteligente vo){
        super(vo);
        this.percentagemOcupacao = vo.getPercentagemOcupacao();
        this.pontosPorKm = vo.getPontosPorKm();
    }

    public int getPercentagemOcupacao() {
        return this.percentagemOcupacao;
    }

    public int getPontosPorKm(){
        return this.pontosPorKm;
    }

    public void setPercentagemOcupacao(int percentagemOcupacao) {
        this.percentagemOcupacao = percentagemOcupacao;
    }

    public double custoRealKm() {
        return (this.percentagemOcupacao <= 60) ? super.getPreco() * 0.5 : super.getPreco() * 0.25;
    }

    /**
     * Interface
     */

    public void setPtsPorKm(int pts) {
        this.pontosPorKm = pts;
    }

    public int getPtsPorKm() {
        return this.pontosPorKm;
    }

    public int totalPts(){
        return (int) (this.pontosPorKm * super.getKilometragem());
    }




    @Override
    public int hashCode(){
        return super.hashCode();
    }

    @Override
    public AutocarroInteligente clone() {
        return new AutocarroInteligente(this);
    }

    @Override
    public boolean equals(Object obj){
        if(this==obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        AutocarroInteligente vo = (AutocarroInteligente) obj;

        return super.equals(vo);
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString());
        sb.append("Percentagem de Ocupaçao -> ").append(this.percentagemOcupacao).append("\n");
        return sb.toString();
    }

}
