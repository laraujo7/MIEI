package Fase1;

import java.util.HashSet;
import java.util.Set;

public class TesteDriveIt {

    public static void main(String[] args){
        DriveIt driveIt = new DriveIt();
        Veiculo v1 = new Veiculo("v1","Audi","A3",2010,80.0,92.4,7,20,3);
        Veiculo v2 = new Veiculo("v2","BMW","Class C",2007,95.3,90.1,8,10.5,3);
        Veiculo v3 = new Veiculo("v3","Mercedes","MG",2005,70.0,86.5,7,12.3,2);
        Veiculo v4 = new Veiculo("v4","Ferrari","1.18",2011,100.4,121.2,9,0,0);
        Veiculo v5 = new Veiculo("v5","Ford","Focus",2016,80.0,59.4,5,12.5,2);
        Veiculo v6 = new Veiculo("v6","Porshe","Panamera",2009,80.0,87.4,8,3.5,1);
        Veiculo v7 = new Veiculo("v7","Audi","A3",2005,78.6,70.8,7,20,3);
        VeiculoOcasiao v8 = new VeiculoOcasiao("v8","Nissan","GTR",2008,77.2,89.7,8,43.8,5,false);
        VeiculoOcasiao v9 = new VeiculoOcasiao("v9","McLaren","P1",2020,121.2,140,9,10,1,false);

        //v
        driveIt.adiciona(v1);
        driveIt.adiciona(v2);
        driveIt.adiciona(v3);
        driveIt.adiciona(v4);
        driveIt.adiciona(v8);


        //i
        System.out.println("i) Existe veiculo (v1) -> " + driveIt.existeVeiculo(v1.getCodigo()) + "\n");

        //ii
        System.out.println("ii) Quantos veiculos existem -> " + driveIt.quantos() + "\n");

        //iii
        System.out.println("iii) Quantos veiculos com a marca (Audi) existem -> " + driveIt.quantos("Audi") + "\n");

        //iv
        System.out.println("iv) Veiculo v4 :\n" + driveIt.getVeiculo("v4") + "\n");

        //vi
        System.out.println("vi) Lista de veiculos (antes da inserçao) :\n" + driveIt.getVeiculos().toString() + "\n");

        //vii
        Set<Veiculo> vs = new HashSet<>();
        vs.add(v5);
        vs.add(v6);
        vs.add(v7);
        vs.add(v9);

        driveIt.adiciona(vs);

        //Empresa entra em promocao
        driveIt.alteraPromocao(true);


        System.out.println("vii) Lista de veiculos (apos inserçao) :\n" + driveIt.getVeiculos().toString() + "\n");

        //viii
        driveIt.registarAluguer("v3",2);

        System.out.println("viii) Veiculo v3 :\n" + driveIt.getVeiculo("v3") + "\n");

        //ix
        driveIt.classificarVeiculo("v2",0);

        System.out.println("ix) Veiculo v2 :\n" + driveIt.getVeiculo("v2") + "\n");

        //x
        System.out.println("x) Custo Real v1 -> " + driveIt.custoRealKm("v1") + "\n");
        System.out.println("x) Custo Real v2 -> " + driveIt.custoRealKm("v2") + "\n");
        System.out.println("x) Custo Real v3 -> " + driveIt.custoRealKm("v3") + "\n");
        System.out.println("x) Custo Real v4 -> " + driveIt.custoRealKm("v4") + "\n");
        System.out.println("x) Custo Real v5 -> " + driveIt.custoRealKm("v5") + "\n");
        System.out.println("x) Custo Real v6 -> " + driveIt.custoRealKm("v6") + "\n");
        System.out.println("x) Custo Real v7 -> " + driveIt.custoRealKm("v7") + "\n");
        System.out.println("x) Custo Real v8 -> " + driveIt.custoRealKm("v8") + "\n");
        System.out.println("x) Custo Real v9 -> " + driveIt.custoRealKm("v9") + "\n");



    }
}
