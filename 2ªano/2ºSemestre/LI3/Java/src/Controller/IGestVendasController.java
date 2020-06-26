package Controller;

import java.io.IOException;

public interface IGestVendasController {

    void run();

    void dadosEstatisticos();

    void guardar() throws IOException;

    void ler() throws IOException, ClassNotFoundException;

    void queries();

    void lerFicheiros();

    void dadosEstatisticos_UltFicheiro();

    void dadosEstatisticos_Gerais();

}
