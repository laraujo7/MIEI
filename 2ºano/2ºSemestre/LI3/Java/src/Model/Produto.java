package Model;

public class Produto implements IProduto {

    private String ID;


    public Produto(){
        this.ID = "n/a";
    }

    public Produto(String ID) {
        this.ID = ID;
    }

    public Produto(Produto pr){
        this.ID = pr.getID();
    }

    public String getID() {
        return this.ID;
    }


    @Override
    public int hashCode(){
        return 31 * this.ID.hashCode();
    }

    @Override
    public boolean equals(Object obj){
        if(this == obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;

        Produto pr = (Produto) obj;

        return pr.getID().equals(this.ID);
    }

    @Override
    public String toString(){
        return this.ID;
    }

    @Override
    public Produto clone(){
        return new Produto(this);
    }


}
