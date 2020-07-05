package Fase3;

public class VeiculoOcasiao extends Veiculo {

    private boolean promocao;

    public VeiculoOcasiao(){
        super();
        this.promocao = false;
    }

    public VeiculoOcasiao(String cod, String marca, String modelo, int ano, double velocMedia,
                          double preco, int classi , double kilometragem, int nClientes,
                          boolean promocao){

        super(cod,marca,modelo,ano,velocMedia,preco,classi,kilometragem,nClientes);
        this.promocao = promocao;
    }

    public VeiculoOcasiao(VeiculoOcasiao vo){
        super(vo);
        this.promocao = vo.getPromocao();
    }


    public boolean getPromocao(){
        return promocao;
    }

    public void setPromocao(boolean promocao) {
        this.promocao = promocao;
    }


    public double custoRealKm() {
        return (this.promocao ? (0.75 * super.getPreco()) : super.getPreco()) * 1.1;
    }


    @Override
    public int hashCode(){
        return super.hashCode();
    }

    @Override
    public VeiculoOcasiao clone() {
        return new VeiculoOcasiao(this);
    }

    @Override
    public boolean equals(Object obj){
        if(this==obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        VeiculoOcasiao vo = (VeiculoOcasiao) obj;

        return super.equals(vo) && this.promocao == vo.getPromocao();
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        if(this.promocao) sb.append(" -> Em Promocao <-\n");
        sb.append(super.toString()).append("\n");
        return sb.toString();
    }

}
