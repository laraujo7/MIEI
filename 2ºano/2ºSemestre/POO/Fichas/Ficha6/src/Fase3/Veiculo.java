package Fase3;

public abstract class Veiculo implements Comparable<Veiculo>{

    private String codigo;
    private String marca;
    private String modelo;
    private int ano;
    private double velocMedia;
    private double preco;
    private int classificacao;
    private double kilometragem;
    private int nClientes;


    public Veiculo(){
        this.codigo = "n/a";
        this.marca = "n/a";
        this.modelo = "n/a";
        this.ano = 0;
        this.velocMedia = 0;
        this.preco = 0;
        this.classificacao = 0;
        this.kilometragem = 0;
        this.nClientes = 0;
    }

    public Veiculo(String cod, String marca, String modelo, int ano, double velocMedia,
                   double preco, int classi , double kilometragem, int nClientes){
        this.codigo = cod;
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        this.velocMedia = velocMedia;
        this.preco = preco;
        this.classificacao = classi;
        this.kilometragem = kilometragem;
        this.nClientes = nClientes;
    }

    public Veiculo(Veiculo v){
        this.codigo = v.getCodigo();
        this.marca = v.getMarca();
        this.modelo = v.getModelo();
        this.ano = v.getAno();
        this.velocMedia = v.getVelocMedia();
        this.preco = v.getPreco();
        this.classificacao = v.getClassificacao();
        this.kilometragem = v.getKilometragem();
        this.nClientes = v.getNClientes();
    }


    public String getCodigo() {
        return codigo;
    }

    public String getMarca() {
        return marca;
    }

    public String getModelo() {
        return this.modelo;
    }

    public int getAno() {
        return this.ano;
    }

    public double getVelocMedia() {
        return this.velocMedia;
    }

    public double getPreco() {
        return this.preco;
    }

    public int getClassificacao() {
        return this.classificacao;
    }


    public double getKilometragem(){
        return this.kilometragem;
    }

    public int getNClientes(){
        return this.nClientes;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public void setVelocMedia(double velocMedia) {
        this.velocMedia = velocMedia;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public void setClassificacao(int classificacao) {
        this.classificacao = classificacao;
    }

    public void setKilometragem(double kilometragem) {
        this.kilometragem = kilometragem;
    }

    public void setnClientes(int nClientes) {
        this.nClientes = nClientes;
    }

    public abstract double custoRealKm();

    @Override
    public int hashCode(){
        int result = this.getCodigo().hashCode();
        result = 31 * result + this.getMarca().hashCode();
        result = 31 * result + this.getModelo().hashCode();
        result = 31 * result + this.getAno();
        result = 31 * result + (int) this.getVelocMedia();
        result = 31 * result + (int) this.getPreco();
        result = 31 * result + this.getClassificacao();
        result = 31 * result + (int) this.getKilometragem();
        result = 31 * result + this.getNClientes();
        return result;
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();

        sb.append("Codigo -> ").append(this.codigo).append("\n")
                .append("Marca -> ").append(this.marca).append("\n")
                .append("Modelo -> ").append(this.modelo).append("\n")
                .append("Ano -> ").append(this.ano).append("\n")
                .append("VelocMedia -> ").append(this.velocMedia).append("\n")
                .append("Preco -> ").append(this.preco).append("\n")
                .append("Classificacao -> ").append(this.classificacao).append("\n")
                .append("Kilometragem -> ").append(this.kilometragem).append("\n")
                .append("Numero de Clientes -> ").append(this.nClientes).append("\n")
                .append("Custo Real Km -> ").append(this.custoRealKm()).append("\n");

        return sb.toString();
    }

    @Override
    public boolean equals(Object obj){
        if(this == obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        Veiculo v = (Veiculo) obj;

        return this.codigo.equals(v.getCodigo())
                && this.marca.equals(v.getMarca())
                && this.modelo.equals(v.getModelo())
                && this.ano == v.getAno()
                && this.velocMedia == v.getVelocMedia()
                && this.preco == v.getPreco()
                && this.classificacao ==  v.getClassificacao()
                && this.kilometragem == v.getKilometragem()
                && this.nClientes == v.getNClientes();

    }

    @Override
    public abstract Veiculo clone();

    @Override
    public int compareTo(Veiculo v){
        if(this.marca.equals(v.getMarca()))
            return this.modelo.compareTo(v.getModelo());

        else return this.marca.compareTo(v.getMarca());
    }

}



