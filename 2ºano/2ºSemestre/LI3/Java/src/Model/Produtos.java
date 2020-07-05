package Model;

import java.util.HashSet;
import java.util.Set;

public class Produtos implements IProdutos {

    private Set<IProduto> produtos;

    public Produtos(){
        this.produtos = new HashSet<>();
    }


    public Set<String> getProdutos(){
        Set<String> res = new HashSet<>();
        this.produtos.forEach(pr -> res.add(pr.getID()));
        return res;
    }


    public void addPRDS(IProduto prd){
        this.produtos.add(prd.clone());
    }


    public boolean existe(String codProd){
        return this.produtos.contains(new Produto(codProd));
    }


    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder() ;

        this.produtos.forEach(prd -> sb.append(prd.toString()).append("\n"));

        return sb.toString();
    }



}
