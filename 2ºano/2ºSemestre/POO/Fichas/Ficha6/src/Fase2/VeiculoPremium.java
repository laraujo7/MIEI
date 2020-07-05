package Fase2;


public class VeiculoPremium extends Veiculo {

    private double taxaLuxo;

    public VeiculoPremium(){
        super();
        this.taxaLuxo = 0;
    }

    public VeiculoPremium(String cod, String marca, String modelo, int ano, double velocMedia,
                          double preco, int classi , double kilometragem, int nClientes,
                          double taxaLuxo){

        super(cod,marca,modelo,ano,velocMedia,preco,classi,kilometragem,nClientes);
        this.taxaLuxo = taxaLuxo;
    }

    public VeiculoPremium(VeiculoPremium vo){
        super(vo);
        this.taxaLuxo = vo.getTaxaLuxo();
    }

    public double getPreco() {
        return this.taxaLuxo * super.getPreco();
    }

    public double getTaxaLuxo(){
        return this.taxaLuxo;
    }

    public void setTaxaLuxo(int taxaLuxo) {
        this.taxaLuxo = taxaLuxo;
    }

    public double custoRealKm() {
        return super.getPreco() * this.taxaLuxo * 1.1;
    }


    @Override
    public int hashCode(){
        return super.hashCode();
    }

    @Override
    public VeiculoPremium clone() {
        return new VeiculoPremium(this);
    }

    @Override
    public boolean equals(Object obj){
        if(this==obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        VeiculoPremium vo = (VeiculoPremium) obj;

        return super.equals(vo) && this.taxaLuxo == vo.getTaxaLuxo();
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString());
        sb.append("Taxa de Luxo -> ").append(this.taxaLuxo).append("\n\n");
        return sb.toString();
    }

}
