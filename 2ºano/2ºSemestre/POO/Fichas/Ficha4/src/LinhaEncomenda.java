public class LinhaEncomenda {

    private String codigo;
    private String descricao;
    private double preco;
    private int quantidade;
    private double percentagem;
    private double desconto;

    public LinhaEncomenda(){
        this.codigo = "n/a";
        this.descricao = "n/a";
        this.preco = 0;
        this.quantidade = 0;
        this.percentagem = 0;
        this.desconto = 0;
    }

    public LinhaEncomenda(String code, String description, double price,
                          int quantity, double percentage, double discount){

        this.codigo = code;
        this.descricao = description;
        this.preco = price;
        this.quantidade = quantity;
        this.percentagem = percentage;
        this.desconto = discount;
    }

    public LinhaEncomenda(LinhaEncomenda e){
        this.codigo = e.getCodigo();
        this.descricao = e.getDescricao();
        this.preco = e.getPreco();
        this.quantidade = e.getQuantidade();
        this.percentagem = e.getPercentagem();
        this.desconto = e.getDesconto();
    }

    public String getCodigo() {
        return this.codigo;
    }

    public String getDescricao() {
        return this.descricao;
    }

    public double getPreco() {
        return this.preco;
    }

    public int getQuantidade() {
        return this.quantidade;
    }

    public double getPercentagem() {
        return this.percentagem;
    }

    public double getDesconto() {
        return this.desconto;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public void setPercentagem(double percentagem) {
        this.percentagem = percentagem;
    }

    public void setDesconto(double desconto) {
        this.desconto = desconto;
    }


    //b
    public double calculaValorLinhaEnc(){
        double valor = this.quantidade * this.preco;
        valor -= valor * this.desconto;
        valor *= this.percentagem;

        return valor;
    }

    //c
    public double calculaValorDesconto(){
        double valor = this.quantidade * this.preco;
        valor *= percentagem;
        return (valor - this.calculaValorLinhaEnc());
    }



    public boolean equals(Object obj){
        if(obj == this) return true;
        if(obj == null || obj.getClass() != this.getClass()) return false;

        LinhaEncomenda e = (LinhaEncomenda) obj;

        return e.getCodigo().equals(this.codigo);

    }

    public String toString(){
        StringBuilder sb = new StringBuilder();

        sb.append("Codigo -> ").append(this.codigo).append("\n")
                .append("Descrição -> ").append(this.descricao).append("\n")
                .append("Preço -> ").append(this.preco);

        return sb.toString();
    }

    public LinhaEncomenda clone() {
        return new LinhaEncomenda(this);
    }

}
