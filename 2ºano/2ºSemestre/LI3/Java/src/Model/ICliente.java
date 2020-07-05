package Model;

import java.io.Serializable;

public interface ICliente extends Serializable {

    String getID();

    void setID(String ID);

    ICliente clone();


}
