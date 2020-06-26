package Model;

public class Cliente implements ICliente {

    private String ID;

    public Cliente() {
        this.ID = "n/a";
    }

    public Cliente(String ID) {
        this.ID = ID;
    }

    public Cliente(Cliente cl) {
        this.ID = cl.getID();
    }


    public String getID() {
        return this.ID;
    }


    public void setID(String ID) {
        this.ID = ID;
    }


    @Override
    public int hashCode() {
        return 31 * this.ID.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || this.getClass() != obj.getClass()) return false;

        Cliente cl = (Cliente) obj;

        return cl.getID().equals(this.ID);
    }

    @Override
    public String toString() {
        return this.ID;
    }

    @Override
    public Cliente clone() {
        return new Cliente(this);
    }


}
