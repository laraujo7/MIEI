package Fase4;

public class VeiculoNormal extends Veiculo {


    public VeiculoNormal(){
        super();

    }

    public VeiculoNormal(String cod, String marca, String modelo, int ano, double velocMedia,
                         double preco, int classi , double kilometragem, int nClientes){

        super(cod,marca,modelo,ano,velocMedia,preco,classi,kilometragem,nClientes);
    }

    public VeiculoNormal(VeiculoNormal vo){
        super(vo);
    }


    public double custoRealKm() {
        return getPreco() * 1.1;
    }


    @Override
    public int hashCode(){
        return super.hashCode();
    }

    @Override
    public VeiculoNormal clone() {
        return new VeiculoNormal(this);
    }

    @Override
    public boolean equals(Object obj){
        if(this==obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        VeiculoNormal vo = (VeiculoNormal) obj;

        return super.equals(vo);
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString()).append("\n\n");
        return sb.toString();
    }

}
