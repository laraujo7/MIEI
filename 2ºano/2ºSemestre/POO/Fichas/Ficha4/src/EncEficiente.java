import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.stream.Stream;

public class EncEficiente {

    private String nomeCliente;
    private String nif;
    private String morada;
    private int nEncomenda;
    private LocalDate data;
    private ArrayList<LinhaEncomenda> encomendas;

    public EncEficiente(){
        this.nomeCliente = "n/a";
        this.nif = "n/a";
        this.morada = "n/a";
        this.nEncomenda = 0;
        this.data = LocalDate.now();
        this.encomendas = new ArrayList<>();
    }

    public EncEficiente(String nome, String numeroFiscal, String m, int nEnc,LocalDate date, ArrayList<LinhaEncomenda> enc){
        this.nomeCliente = nome;
        this.nif = numeroFiscal;
        this.morada = m;
        this.nEncomenda = nEnc;
        this.data = date;
        this.encomendas = enc;
    }

    public EncEficiente(EncEficiente e){
        this.nomeCliente = e.getNomeCliente();
        this.nif = e.getNIF();
        this.morada = e.getMorada();
        this.nEncomenda = e.getNEncomenda();
        this.data = e.getData();
        this.encomendas = new ArrayList<LinhaEncomenda>(e.encomendas);
    }

    public String getNomeCliente() {
        return this.nomeCliente;
    }

    public String getNIF() {
        return this.nif;
    }

    public String getMorada() {
        return this.morada;
    }

    public int getNEncomenda() {
        return this.nEncomenda;
    }

    public LocalDate getData() {
        return this.data;
    }

    public void setNomeCliente(String nomeCliente) {
        this.nomeCliente = nomeCliente;
    }

    public void setNif(String nif) {
        this.nif = nif;
    }

    public void setMorada(String morada) {
        this.morada = morada;
    }

    public void setnEncomenda(int nEncomenda) {
        this.nEncomenda = nEncomenda;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }

    public void setEncomendas(ArrayList<LinhaEncomenda> encomendas) {
        this.encomendas = encomendas;
    }

    //ii
    public double calculaValorTotal(){
        double res = 0;
        for(LinhaEncomenda e : this.encomendas) res += e.calculaValorLinhaEnc();

        return res;
    }

    //iii
    public double calculaValorDesconto(){
        double res = 0;
        for(LinhaEncomenda e : this.encomendas) res += e.calculaValorDesconto();

        return res;
    }

    //iv
    public int numeroTotalProdutos(){
        return this.encomendas.size();
    }

    //v
    public boolean existeProdutoEncomenda(String refProduto){
        boolean res = false;
        Iterator<LinhaEncomenda> it = this.encomendas.iterator();

        while(it.hasNext() && !res) {

            LinhaEncomenda le = it.next();

            if(le.getCodigo().equals(refProduto)) res = true;
        }

        return res;
    }

    //vi
    public void adicionaLinha(LinhaEncomenda linha){
        this.encomendas.add(linha);
    }

    //vii
    public void removeProduto(String codProd){
        boolean encontrado = false;
        Iterator<LinhaEncomenda> it = this.encomendas.iterator();

        while(it.hasNext() && !encontrado){
            LinhaEncomenda le = it.next();

            if(le.getCodigo().equals(codProd)) {
                encontrado = true;
                it.remove();
            }
            
        }

    }


    public String toString(){
        StringBuilder sb = new StringBuilder();

        sb.append("Clientes -> ").append(this.nomeCliente).append("\n");

        for(LinhaEncomenda e : this.encomendas){
            sb.append(e.toString()).append("\n");
        }

        return sb.toString();
    }

    public EncEficiente clone(){
        return new EncEficiente(this);
    }

    public boolean equals(Object obj){
        if(this == obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        EncEficiente e = (EncEficiente) obj;

        return this.nif.equals(e.getNIF());
    }

}
