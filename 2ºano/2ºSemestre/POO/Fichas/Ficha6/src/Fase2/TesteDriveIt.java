package Fase2;

import java.util.Iterator;

public class TesteDriveIt {

    public static void main(String[] args){
        DriveIt driveIt = new DriveIt();
        VeiculoNormal v1 = new VeiculoNormal("v1","Audi","A3",2010,80.0,92.4,7,20,3);
        VeiculoNormal v2 = new VeiculoNormal("v2","BMW","Class C",2007,95.3,90.1,8,10.5,3);
        VeiculoNormal v3 = new VeiculoNormal("v6","Porshe","Panamera",2009,80.0,87.4,8,3.5,1);
        VeiculoPremium v4 = new VeiculoPremium("v3","Mercedes","MG",2005,70.0,86.5,7,12.3,2,1.06);
        VeiculoPremium v5 = new VeiculoPremium("v4","Ferrari","1.18",2011,100.4,121.2,9,0,0,1.2);
        VeiculoPremium v6 = new VeiculoPremium("v6","Rolls Royce","Ghost",2020,110.3,200.2,10,7,1,1.15);
        VeiculoOcasiao v7 = new VeiculoOcasiao("v7","Audi","A3",2005,78.6,70.8,7,20,3,false);
        VeiculoOcasiao v8 = new VeiculoOcasiao("v8","Nissan","GTR",2008,77.2,89.7,8,43.8,5,false);
        VeiculoOcasiao v9 = new VeiculoOcasiao("v9","McLaren","P1",2020,121.2,140,9,10,1,false);
        AutocarroInteligente v10 = new AutocarroInteligente("v10","Tesla","CyberTruck",2021,103.2,105.1,9,40,5,85);


        driveIt.adiciona(v1);
        driveIt.adiciona(v2);
        driveIt.adiciona(v3);
        driveIt.adiciona(v4);
        driveIt.adiciona(v5);
        driveIt.adiciona(v6);
        driveIt.adiciona(v7);
        driveIt.adiciona(v8);
        driveIt.adiciona(v9);
        driveIt.adiciona(v10);


        //Empresa entra em promocao
        driveIt.alteraPromocao(true);

        //i
        System.out.println("Primeiro exercicio : \n" + driveIt.ordenarVeiculos() + "\n\n");

        //ii
        System.out.println("Segundo exercicio : \n" + driveIt.ordenarVeiculosLista() + "\n\n");

        //iii
        System.out.println("Terceiro exercicio i : \n" + driveIt.ordenarVeiculos(new ComparatorKilometragem()) + "\n\n");
        System.out.println("Terceiro exercicio ii: \n" + driveIt.ordenarVeiculos(new ComparatorCustoRealKm()) + "\n\n");

        //iv
        driveIt.addCriterio("ComparadorKilometragem",new ComparatorKilometragem());
        driveIt.addCriterio("ComparadorCustoRealKm",new ComparatorCustoRealKm());

        //v
        System.out.println("Quinto exercicio : \n");
        Iterator<Veiculo> it =  driveIt.ordernarVeiculos("ComparadorKilometragem");
        while(it.hasNext()){
            Veiculo v = it.next();
            System.out.println(v.toString());
        }

    }
}
