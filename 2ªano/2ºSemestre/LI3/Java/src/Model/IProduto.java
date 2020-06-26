package Model;

import java.io.Serializable;

public interface IProduto extends Serializable {

    String getID();

    IProduto clone();

}
