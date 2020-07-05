import Controller.GestVendasController;
import Controller.IGestVendasController;
import Model.GestVendasModel;
import Model.IGestVendasModel;
import View.GestVendasView;
import View.IGestVendasView;


public class GestVendasAppMVC {

    public static void main(String[] args){
        IGestVendasModel model = new GestVendasModel();
        IGestVendasView view = new GestVendasView();
        IGestVendasController controller = new GestVendasController(model, view);
        controller.run();
    }

}
