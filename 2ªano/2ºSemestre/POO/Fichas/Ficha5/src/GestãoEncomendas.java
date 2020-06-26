import java.time.LocalDate;
import java.util.*;
import java.util.stream.Collectors;

public class GestãoEncomendas {

    private String referencia;
    private Map<String,EncEficiente> encomendas;

    public GestãoEncomendas(){
        this.referencia = "n/a";
        this.encomendas = new HashMap<>();
    }

    public GestãoEncomendas(String ref, Map<String,EncEficiente> le){
        this.referencia = ref;
        setEncomendas(le);
    }

    public GestãoEncomendas(GestãoEncomendas ge){
        this.referencia = ge.getReferencia();
        this.encomendas = ge.getEncomendas();
    }

    public String getReferencia(){
        return this.referencia;
    }

    public Map<String,EncEficiente> getEncomendas(){
        Map<String,EncEficiente> aux = new HashMap<>();
        this.encomendas.values().forEach(e -> aux.put(e.getNomeCliente(),e.clone()));
        return aux;
    }

    public void setReferencia(String referencia) {
        this.referencia = referencia;
    }

    public void setEncomendas(Map<String,EncEficiente> le){
        this.encomendas = new HashMap<>();
        le.values().forEach(e -> this.encomendas.put(e.getNomeCliente(),e.clone()));
        //le.forEach((key,value) -> this.encomendas.put(key,value.clone()));
    }

    //i
    public Set<String> todosCodigosEnc(){
        return this.encomendas.keySet();
    }

    //ii
    public void addEncomenda(EncEficiente enc){
        Map<String,EncEficiente> aux = new HashMap<>(this.getEncomendas());
        aux.put(enc.getNomeCliente(), enc);
        setEncomendas(aux);
    }

    //iii
    public EncEficiente getEncomenda(String codEnc){
        return this.encomendas.get(codEnc).clone();
    }

    //iv
    public boolean existeEncomenda(String codEnc){
        return this.encomendas.containsKey(codEnc);
    }

    public void removeEncomenda(String codEnc){
        if(existeEncomenda(codEnc)){
            Map<String,EncEficiente> aux = new HashMap<>(this.getEncomendas());
            aux.remove(codEnc);
            setEncomendas(aux);
        }
    }

    //v
    public String encomendaComMaisProdutos(){
        String res = "n/a";
        int nProdutos = 0;
        int maior = 0;

        if(!this.encomendas.isEmpty()){
            for(EncEficiente e : this.encomendas.values()) {
                nProdutos = e.numeroTotalProdutos();
                if (maior < nProdutos) {
                    maior = nProdutos;
                    res = e.getNomeCliente();
                }
            }
        }
        return res;
    }

    //vi -> assumir que o produto existe
    public Set<String> encomendasComProduto(String codProd){
        Set<String> s = new TreeSet<>();

        for(EncEficiente e : this.encomendas.values()){
            if(e.existeProdutoEncomenda(codProd)) s.add(e.getNomeCliente());
        }

        return s;
    }

    //vii
    public Set<String> encomendasAposData(LocalDate d){
        Set<String> s = new TreeSet<>();

        for(EncEficiente e : this.encomendas.values()){
            if(e.getData().isAfter(d)) s.add(e.getNomeCliente());
        }

        return s;
    }

    //viii
    public Set<EncEficiente> encomendasValorDecrescente(){
        Set<EncEficiente> res = new TreeSet<>(new ComparatorValorEncomenda());

        for(EncEficiente e : this.encomendas.values())
            res.add(e.clone());

        return res;
    }

    //ix
    public Map<String, List<String>> encomendasDeProduto(){
        Map<String,List<String>> res = new HashMap<>();

        for(EncEficiente enc : this.encomendas.values()){

            for(LinhaEncomenda e : enc.getEncomendas())
                res.put(e.getCodigo(), new ArrayList<>(encomendasComProduto(e.getCodigo())));

        }

        return res;
    }



}
