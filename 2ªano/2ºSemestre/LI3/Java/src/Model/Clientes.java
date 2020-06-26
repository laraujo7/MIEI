package Model;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;


public class Clientes implements IClientes {

    private Set<ICliente> clientes;


    public Clientes() {
        this.clientes = new HashSet<>();
    }

    public Clientes(Set<ICliente> cls) {
        setCLS(cls);
    }


    public Set<String> getClientes() {
        Set<String> res = new TreeSet<>();
        this.clientes.forEach(cl -> res.add(cl.getID()));
        return res;
    }

    public void setCLS(Set<ICliente> cls) {
        this.clientes = new HashSet<>();
        cls.forEach(cl -> this.clientes.add(cl.clone()));
    }

    public void addCLS(ICliente cl) {
        this.clientes.add(cl.clone());
    }

    public boolean existe(String codCl) {
        return this.clientes.contains(new Cliente(codCl));
    }


    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        this.clientes.forEach(cl -> sb.append(cl.toString()).append("\n"));

        return sb.toString();
    }


}
