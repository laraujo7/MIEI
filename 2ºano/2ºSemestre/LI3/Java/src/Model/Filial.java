package Model;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Filial implements IFilial {
    //mes 0-11
    List<Map<String,List<IVenda>>> vendas_produtos;
    List<Map<String,List<IVenda>>> vendas_clientes;


    public Filial(){
        this.vendas_produtos = new ArrayList<>();
        this.vendas_clientes = new ArrayList<>();

        for(int i=0 ; i<12 ; i++){
            Map<String,List<IVenda>> map_prod = new HashMap<>();
            Map<String,List<IVenda>> map_client = new HashMap<>();

            this.vendas_produtos.add(map_prod);
            this.vendas_clientes.add(map_client);
        }

    }

    public List<Map<String, List<IVenda>>> getVendas_produtos() {
        return vendas_produtos;
    }

    public List<Map<String, List<IVenda>>> getVendas_clientes() {
        return vendas_clientes;
    }

    /**
     * Adiciona venda.
     * @param vd Venda.
     */
    public void addVDS(IVenda vd){
        String codProd = vd.getCodigoProduto();
        String codCl = vd.getCodigoCliente();
        int mes = vd.getMes() - 1;

        if(this.vendas_produtos.get(mes).containsKey(codProd)){
            this.vendas_produtos.get(mes).get(codProd).add(vd.clone());
        }

        else{
            List<IVenda> aux = new ArrayList<>();
            aux.add(vd.clone());

            this.vendas_produtos.get(mes).put(codProd,aux);
        }

        if(this.vendas_clientes.get(mes).containsKey(codCl)){
            this.vendas_clientes.get(mes).get(codCl).add(vd.clone());
        }

        else{
            List<IVenda> aux = new ArrayList<>();
            aux.add(vd.clone());

            this.vendas_clientes.get(mes).put(codCl,aux);
        }

    }

}
