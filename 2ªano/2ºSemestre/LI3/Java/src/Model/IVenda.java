package Model;

import java.io.Serializable;

public interface IVenda extends Serializable{

    String getCodigoProduto();

    double getPreco();

    int getQt();

    String getTipo();

    String getCodigoCliente();

    int getMes();

    int getFilial();

    double getFaturacao();

    boolean validade();

    boolean equals(Object obj);

    String toString();

    IVenda clone();

    void setQt(int i);

    void setPreco(double v);

    void setFaturacao(double faturacao);
}
